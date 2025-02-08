#include "App.hpp"
#include <sstream>
using namespace std;

App::App() {
    cmd_manager = new CmdManager();
}

void App::run() {
    cmd_manager->handle_inputs();
}

string App::to_string() {
    ostringstream os;
    os << cmd_manager->to_string();
    return os.str();
}