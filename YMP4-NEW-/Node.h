#pragma once

#include <vector>

using namespace std;

// ��� ������ ��� �������
typedef pair<int, int> TData;

struct Node {
	TData data;
	Node* next;
};