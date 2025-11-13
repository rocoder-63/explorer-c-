#ifndef EXPLORER_HPP
#define EXPLORER_HPP

#include <string>
#include <map>
#include <memory>
using namespace std;

#include "task_base.hpp"
#include "settings_manager.hpp"

class explorer : public task_base, public std::enable_shared_from_this<explorer> {

    std::map<std::string, std::shared_ptr<task_base>> tasks;
    std::string user_name;

public:
    explorer() = delete;
    const explorer& operator=(const explorer&) = delete;
    explorer(const explorer&) = delete;

    explorer(const std::string u_name, task_opt_struct options): user_name(u_name), task_base("Explorer", options) {
    };

    void init() {

        // Register for events
        settings_manager::getInstance().addObserver(shared_from_this());
    }

    void deinit() {

        // Unregister for events
        settings_manager::getInstance().removeObserver(shared_from_this());
    }

    void execute() override {
        std::cout << "Executing Explorer Task" << std::endl;
    }

    void settings_update(std::string &setting, std::string &value) override {
        std::cout << "Explorer Task - Updating setting: " << setting << " to value: " << value << std::endl;
    }

    int addTask(std::shared_ptr<task_base> task_ptr);
    std::shared_ptr<task_base> getTask(const std::string& task_name);
};

#endif // EXPLORER_HPP