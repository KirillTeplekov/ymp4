#include <iostream>
#include "Pathfinder.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	string fileName = "C:\\Users\\keril\\Desktop\\map.txt";
	int m = 4, n = 4;
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		*(a + i) = new int[n];

	pair <int, int> start = { 0, 0 };
	pair <int, int> goal = { 1, 0 };

	inputPathMatrix(fileName, a, m, n);
	pathfinder(start, goal, a, m, n);
}