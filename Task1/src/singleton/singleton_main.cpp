#include "singleton_main.hpp"

int singleton::getSize() 
{
    return purpose.size();
}

void singleton::setText(const std::string& text)
{
    purpose.assign(text.begin(), text.end());
    return;
}