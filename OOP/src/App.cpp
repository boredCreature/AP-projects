#include "App.hpp"

using namespace std;

App::App() {
    cmd_manager = new CmdManager();
}

void App::run() {
    cmd_manager->handle_inputs();
}