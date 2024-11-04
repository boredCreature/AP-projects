#include "Q3.hpp"


int main() {
    int n;
    vector <int> numberInFaculty;
    getInput(n, numberInFaculty);
    int minShirini = minShiriniFinder(numberInFaculty);
    cout << minShirini << endl;
    return 0;
}