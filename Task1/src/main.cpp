#include <iostream>
#include <string>
#include <algorithm>
#include <mutex>
#include <thread>
#include <chrono>


// Project specific header files can be included here
#include "singleton_main.hpp"
#include "settings_manager.hpp"
#include "explorer.hpp"
#include "audio_task.hpp"

namespace sm = settings_manager_space;

struct task_struct
{
    std::list<std::shared_ptr<task_base>> task_list;

    task_struct()
    {
        task_list.clear();
    }

    task_struct(const task_struct &other)
    {
        task_list = other.task_list;
    }

    ~task_struct()
    {
        task_list.clear();
    }
};

task_struct globl_task_handle;
std::mutex task_list_mutex;

class task_list_accessor
{
    public:

    task_list_accessor() = default;
    ~task_list_accessor() = default;

    int get_task_list(int thread_id)
    {
#ifdef STYLE1_MTX_LOCK
        task_list_mutex.lock();
#else
    // Acquire the lock before touching the list
    std::lock_guard<std::mutex> lock(task_list_mutex);
#endif //TYLE1_MTX_LOCK



        std::cout << std::endl <<" === ID: "<< thread_id <<"Task List 1=== " << std::endl;

        int tsk_cnt = 1;

        for(const auto task_item:globl_task_handle.task_list)
        {
            std::cout<<"Task " << tsk_cnt ++ << ": " << task_item.get()->task_name << ". Pointer: " << &task_item << std::endl;
        }

#ifdef STYLE1_MTX_LOCK
        task_list_mutex.unlock();
#endif // STYLE1_MTX_LOCK

        return 0;

    }

    int push_task_list(std::shared_ptr<task_base>& task_item)
    {
        globl_task_handle.task_list.push_back(task_item);

        return 0;
    }

};

void run_startup_tasks() {
    // Get system level resource instances
    sm::settings_manager& system_settings = sm::settings_manager::getInstance();

    cout << "Creating Explorer Task" << endl;
    task_opt_struct task_options = {};
    task_options.options[TASK_PROPERTY_OBSERVE_SYS_SETTINGS] = true;
    std::shared_ptr<task_base> explorerTask = std::make_shared<explorer>("Admin User", task_options);
    dynamic_pointer_cast<explorer> (explorerTask) ->init();
    
    cout << "Creating Audio Task and Adding to Explorer" << endl;
    task_options.options[TASK_PROPERTY_OBSERVE_SYS_SETTINGS] = true;
    std::shared_ptr<task_base>audio_shared_ptr = std::make_shared<audio_task>(task_options);
    dynamic_pointer_cast<explorer> (explorerTask) ->addTask(audio_shared_ptr);

    cout << "Event 1 Generated" << endl;
    system_settings.setSettingsType("Audio"); 
    system_settings.setSetting("Volume", "75");

    cout << "Event 2 Generated" << endl;
    system_settings.setSettingsType("Video");
    system_settings.setSetting("Format", "H264");

    task_list_accessor tl_hdl_startup;
    
    tl_hdl_startup.push_task_list(explorerTask);
    tl_hdl_startup.push_task_list(audio_shared_ptr);

    tl_hdl_startup.get_task_list(0);

}

void thread_1_list_access()
{
    int i = 10;

    while(i)
    {
        task_list_accessor thread_1_accessor;

        thread_1_accessor.get_task_list(1);
        std::this_thread::sleep_for(1000ms);

        i--;
    }

    return;
}

void thread_2_list_access()
{
    int i = 10;

    while(i)
    {
        task_list_accessor thread_1_accessor;

        thread_1_accessor.get_task_list(2);
        
        std::this_thread::sleep_for(1000ms);

        i--;
    }
    return;
}

#if 0
void task_manager()
{
    // Wait for all tasks to create and let the other thread to signal
    std::cout << std::endl <<" === Task List 1=== " << std::endl;

    for(const auto task_item:globl_task_handle.task_list)
    {
        static int tsk_cnt = 1;
        std::cout<<"Task " << tsk_cnt ++ << ": " << task_item.get()->task_name << ". Pointer: " << &task_item << std::endl;
    }

    auto local_task_hdl = globl_task_handle;

    std::cout << std::endl <<" === Task List 2=== " << std::endl;

    for(const auto &task_item:local_task_hdl.task_list)
    {
        static int tsk_cnt = 1;
        std::cout<<"Task " << tsk_cnt ++ << ": " << task_item.get()->task_name << ". Pointer: " << &task_item << std::endl;
    }

    std::cout << std::endl <<" === Task List 3=== " << std::endl;
    std::list<std::shared_ptr<task_base>>::iterator iter_task = local_task_hdl.task_list.begin();
    for (;iter_task != local_task_hdl.task_list.end();iter_task++)
    {
        static int tsk_cnt = 1;
        std::cout<<"Task " << tsk_cnt ++ << ": " << (*iter_task).get()->task_name << ". Pointer: " << &(*iter_task) << std::endl;
    }

    std::cout << std::endl <<" === Task List 4 === " << std::endl;
    std::for_each(local_task_hdl.task_list.begin(), local_task_hdl.task_list.end(), [](std::shared_ptr<task_base> i) {int id = 1; std::cout << "Task "<< id << ": " <<i.get()->task_name << std::endl; id++;});

}
#endif

#include <iostream>
#include <list>

int main(int argc, char** argv) {

    cout << "Program Name: " << argv[0] << endl;

    run_startup_tasks();

    //task_manager();

    std::vector<std::thread> threads;

    threads.emplace_back(thread_1_list_access);
    threads.emplace_back(thread_2_list_access);
    
    threads[0].join();
    threads[1].join();

    cout << "Program Ended Successfully!" << endl;

    return 0;
}
