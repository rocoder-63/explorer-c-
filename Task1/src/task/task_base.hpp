#ifndef TASK_BASE_HPP
#define TASK_BASE_HPP

#include <string>
#include <iostream>
using namespace std;

typedef enum _task_property{
    TASK_PROPERTY_OBSERVE_SYS_SETTINGS = 0,
    TASK_PROPERTY_EXECUTE_ON_STARTUP = 1
}task_property_enum;

typedef struct _task_opt_strucut{
    std::map<task_property_enum, bool> options;
}task_opt_struct;

class task_base {

public:
    task_base(const std::string& name, task_opt_struct options) : task_name(name), task_options(options) {}

    virtual void execute() = 0; // Pure virtual function
    virtual ~task_base() = default; // Virtual destructor

    virtual void settings_update(std::string &setting, std::string &value) {
        // Default implementation (can be overridden)
        cout << "Updating setting: " << setting << " to value: " << value << std::endl;
    }

public:
    std::string task_name;
    task_opt_struct task_options;
};
#endif // TASK_BASE_HPP