#ifndef APP_HPP_INCLUDE
#define APP_HPP_INCLUDE

#include "CmdManager.hpp"

class App {
public:
    App();
    void run();
private:
    CmdManager* cmd_manager;
};

#endif