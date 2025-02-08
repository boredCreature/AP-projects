#ifndef APP_HPP_INCLUDE
#define APP_HPP_INCLUDE

#include "CmdManager.hpp"

class App {
public:
    App();
    void run();
    std::string to_string();
private:
    CmdManager* cmd_manager;
};

#endif