#include "Q1.hpp"

int main() {
    vector <string> inputBoard;
    set<pair<int, int>> obstaclePositions;
    inputBoard = getInput();
    findObstciles(inputBoard, obstaclePositions);
    int queenColInRow[SIZE];
    fillBoardWithNegOne(queenColInRow);

    int solutionNumber = 0;
    solveEightQueen(0, solutionNumber, queenColInRow ,obstaclePositions);
    cout << solutionNumber << endl;


    return 0;

}