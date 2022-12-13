#pragma once
#include "Queue.h"

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

bool Queue::isEmpty()
{
	return size == 0;
}

void Queue::push(TData elem)
{
	Node* p = new Node;
	p->data = elem;
	p->next = nullptr;
	if (tail == nullptr) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = tail->next;
	}
	size++;
}

TData Queue::pop()
{
	TData poped = head->data;
	Node* p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
	size--;
	if (size == 0)
		head = tail = nullptr;
	return poped;
}

TData Queue::peek()
{
	return head->data;
}

void Queue::clear()
{
	while (!isEmpty()) {
		Node* p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
		size--;
	}
	delete head, tail;
	head = tail = nullptr;
}
