#include "App.hpp"
#include <sstream>
using namespace std;

App::App() {
    cmd_manager = new CmdManager();
}

void App::run() {

    string cmd, line;
    while(getline(cin, line)) {
        cmd = line.substr(0, line.find(" "));
        line = line.substr(line.find(" ") + 1);
        cmd_manager->handle_cmd(cmd, line);
    }
}

string App::to_string() {
    ostringstream os;
    os << cmd_manager->to_string();
    return os.str();
}