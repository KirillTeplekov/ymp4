#pragma once

#include <vector>

using namespace std;

// тип данных для очереди
typedef pair<int, int> TData;

struct Node {
	TData data;
	Node* next;
};