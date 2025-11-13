#ifndef SINGLETON_MAIN_HPP
#define SINGLETON_MAIN_HPP

#include <vector>
#include <string>

using namespace std;

class singleton {

    std::vector <char> purpose;

    private:
    singleton() = default; // Private constructor
    ~singleton() = default; // Private destructor
    singleton(singleton const&) = delete; // Delete copy constructor
    void operator=(singleton const&) = delete; // Delete assignment operator

    public:
    static singleton& getInstance() 
    {
        static singleton instance; // Guaranteed to be destroyed.
                                   // Instantiated on first use.
        return instance;
    }

    void setText(const std::string& text);
    
    int getSize();
};

#endif // SINGLETON_MAIN_HPP