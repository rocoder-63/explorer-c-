#include <iostream>
#include <string>

// Project specific header files can be included here
#include "singleton_main.hpp"
#include "settings_manager.hpp"
#include "explorer.hpp"
#include "audio_task.hpp"

void run_startup_tasks() {
    // Get system level resource instances
    settings_manager& system_settings = settings_manager::getInstance();

    cout << "Creating Explorer Task" << endl;
    task_opt_struct task_options = {};
    task_options.options[TASK_PROPERTY_OBSERVE_SYS_SETTINGS] = true;
    std::shared_ptr<task_base> explorerTask = std::make_shared<explorer>("Admin User", task_options);
    dynamic_pointer_cast<explorer> (explorerTask) ->init();
    
    cout << "Creating Audio Task and Adding to Explorer" << endl;
    task_options.options[TASK_PROPERTY_OBSERVE_SYS_SETTINGS] = true;
    dynamic_pointer_cast<explorer> (explorerTask) ->addTask(std::make_shared<audio_task>(task_options));

    cout << "Event 1 Generated" << endl;
    system_settings.setSettingsType("Audio"); 
    system_settings.setSetting("Volume", "75");

    cout << "Event 2 Generated" << endl;
    system_settings.setSettingsType("Video");
    system_settings.setSetting("Format", "H264");
}

int main(int argc, char** argv) {

    cout << "Program Name: " << argv[0] << endl;

    run_startup_tasks();
    
    cout << "Program Ended Successfully!" << endl;

    return 0;
}
