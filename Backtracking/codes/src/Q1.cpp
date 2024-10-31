#include "Q1.hpp"
using namespace std;

const int SIZE = 8;

//a funciton that finds obsticles in board implemented recursivly 
void findObstciles(vector<string> inputBoard, vector<pair<int, int>>& obsticlepositions, int row) {
    if (row == SIZE) {
        return;
    }
    for (int col = 0; col < SIZE; col ++) {
        if (inputBoard[row][col] == '*') {
            obsticlepositions.push_back({row, col});
        }
    }
    findObstciles(inputBoard, obsticlepositions, row + 1);
}

vector<string> getInput() {
    string lineOfInput;
    vector <string> inputBoard;
    while (getline(cin, lineOfInput)) {
        inputBoard.push_back(lineOfInput);
    }
    return inputBoard;
}