#pragma once

#include "Node.h"
#include <iostream>

using namespace std;

class Queue
{
	Node* head;
	Node* tail;
	int size;
public:
	Queue();
	bool isEmpty();
	void push(TData elem);
	TData pop();
	TData peek();
	void clear();
};

