#include "Q3.hpp"


void getInput (int& n, vector<int>& numberInFaculty) {
    cin >> n;

    int number;
    for(int i = 0; i < n; ++i) {
        cin >> number;
        numberInFaculty.push_back(number);
    }

}


// a recursive functoin to find minimum shirini

int findMinShirini (int current, int n, const vector<int>& numberInFaculty) {
    if (current == n - 1) 
        return 0;
    int minShirini = __INT_MAX__;
    
    for (int size = 1; size <= 2; ++size) {
        int next = current + size;
        if (next < n) {
            int cost = abs(numberInFaculty[next] - numberInFaculty[current]);
            minShirini = min(minShirini, cost + findMinShirini(next, n, numberInFaculty));
        }
    }
    return minShirini;
}

//a wrapper funciton for findMinShirini funciton

int minShiriniFinder (const vector<int>& numberInFaculty) {
    int MinShirini;
    int n = numberInFaculty.size();
    MinShirini = findMinShirini(0, n, numberInFaculty);
    return MinShirini;
}



