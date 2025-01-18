#include "App.hpp"
using namespace std;

int main() {
    App app;
    app.run();
    string test = app.to_string();
    cout << "----------------------------" << endl;
    cout << test << endl;
    return 0;
}