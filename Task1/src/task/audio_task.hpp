#ifndef AUDIO_TASK_HPP
#define AUDIO_TASK_HPP

#include "task_base.hpp"

class audio_task : public task_base {
public:
    audio_task(task_opt_struct options) : task_base("AudioTask", options) {
        task_name = "AudioTask";
    }

    void execute() override {
        std::cout << "Executing Audio Task" << std::endl;
    }

    void settings_update(std::string &setting, std::string &value) override {
        std::cout << "Audio Task - Updating setting: " << setting << " to value: " << value << std::endl;
    }
};

#endif // AUDIO_TASK_HPP