#ifndef Q1_HPP
#define Q1_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

const int SIZE = 8;

void findObstciles (vector<string> inputBoard, set<pair<int, int>>& obstaclePositions, int row = 0);
vector<string> getInput ();
bool threat (int r1, int c1, int r2, int c2);
bool checkObstacle (int row, int col, set <pair<int, int>> obstaclePositions);
bool isSafeToPutAt (int row, int col, int queenColInRow[] ,const set <pair<int, int>>& obstaclePositions);
void solveEightQueen (int row, int& solutionNumber, int queenColInRow[], const set <pair<int, int>>& obstaclePositions);
void fillBoardWithNegOne(int queenColInRow[]);


#endif