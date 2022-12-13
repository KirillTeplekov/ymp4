#pragma once

#pragma once

#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void inputPathMatrix(string filename, int** arr, const int m, const int n);
void getNextNodes(vector<pair <int, int>>& nextNodes, pair<int, int> parent, const int m, const int n);
void pathfinder(pair<int, int> start, pair<int, int> goal, int** arr, const int m, const int n);


