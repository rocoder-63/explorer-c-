#include "explorer.hpp"

int explorer::addTask(std::shared_ptr<task_base> task_ptr){
    tasks[task_ptr->task_name] = task_ptr;

    // Register for events
    if (task_ptr->task_options.options[TASK_PROPERTY_OBSERVE_SYS_SETTINGS] == true){
        settings_manager::getInstance().addObserver(task_ptr);
    }

    return 0;
}

std::shared_ptr<task_base> explorer::getTask(const std::string& task_name){
    return tasks[task_name];
}