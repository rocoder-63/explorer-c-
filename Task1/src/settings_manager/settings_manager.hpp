#ifndef SETTINGS_MANAGER_HPP
#define SETTINGS_MANAGER_HPP

#include <map>
#include <string>
#include <list>
#include <memory>

using namespace std;

#include "task_base.hpp"

class settings_manager {
    
    std::string settings_type; // TO be changed
    std::map<std::string, std::string> settings; 

    std::list<std::shared_ptr<task_base>> observers;

    private:
    settings_manager() = default; // Private constructor
    ~settings_manager() = default; // Private destructor
    settings_manager(settings_manager const&) = delete; // Delete copy constructor
    void operator=(settings_manager const&) = delete; // Delete assignment operator

    public:
    static settings_manager& getInstance() 
    {
        static settings_manager instance; // Guaranteed to be destroyed.
                                         // Instantiated on first use.
        return instance;
    }

    void setSettingsType(const std::string& type);
    std::string& getSettingsType();

    void setSetting(const std::string& key, const std::string& value);
    std::string& getSetting(const std::string& key);

    void addObserver(std::shared_ptr<task_base> observer);
    void removeObserver(std::shared_ptr<task_base> observer);
};
#endif // SETTINGS_MANAGER_HPP