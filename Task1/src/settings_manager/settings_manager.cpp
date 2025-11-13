#include "settings_manager.hpp"

void settings_manager::setSettingsType(const std::string& type) {
        settings_type = type;
}

std::string& settings_manager::getSettingsType() {
    return settings_type;
}

void settings_manager::setSetting(const std::string& key, const std::string& value) {
    settings[key] = value;

    // Notify all observers about the settings update
    for (auto& observer : observers) {
        observer->settings_update(const_cast<std::string&>(key), const_cast<std::string&>(value));
    }
}

std::string& settings_manager::getSetting(const std::string& key) {

    return settings[key];
}

void settings_manager::addObserver(std::shared_ptr<task_base> observer){
    observers.push_back(observer);
}

void settings_manager::removeObserver(std::shared_ptr<task_base> observer){
    observers.remove(observer);
}