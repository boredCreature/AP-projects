#include "Q1.hpp"

int main() {
    vector <string> inputBoard;
    vector <pair<int, int>> obsticlepositions;
    inputBoard = getInput();
    findObstciles(inputBoard, obsticlepositions);
    return 0;

}