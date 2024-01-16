#include<iostream>
#include <fstream>
using namespace std;

class queueNode{
public:
	int value;
	queueNode* nextQueueNode;
	queueNode(int value){
		this->value = value;
		nextQueueNode = nullptr;
	}
};

class Queue{
public:
	queueNode* head;
	Queue(){
		head = nullptr;
	}

	void pushBack(int value){
		queueNode* newData = new queueNode(value);
		if (head == nullptr){
			head = newData;
			return;
		}
		else {
			queueNode* temp = head;
			while (temp->nextQueueNode != nullptr)
			{
				temp = temp->nextQueueNode;
			}
			temp->nextQueueNode = newData;
		}
	}

	int popFront() {
		if (head == nullptr) 
		{
			return -1; 
		}
		queueNode* temp = head;
		head = head->nextQueueNode;
		int poppedValue = temp->value;
		delete temp;
		return poppedValue;
	}

	bool isEmpty(){
		return (head == nullptr);
	}


};

template <typename T>
class stackNode {
public:
	T* queueHead;
	stackNode* nextStackNode;

	stackNode(T* value)
	{
		queueHead = value;
		nextStackNode = nullptr;
	}

	stackNode()
	{
		queueHead = nullptr;
		nextStackNode = nullptr;
	}

};

class stack {
public:
	stackNode<Queue>* stackHead;

	stack()
	{
		stackHead = nullptr;
	}

	void pushBack(Queue* value)
	{
		stackNode<Queue>* newData = new stackNode<Queue>(value);
		if (stackHead == nullptr)
		{
			stackHead = newData;
		}
		else 
		{
			stackNode<Queue>* temp = stackHead;
			while (temp->nextStackNode != nullptr)
			{
				temp = temp->nextStackNode;
			}
			temp->nextStackNode = newData;
		}
	}

	Queue* pop()
	{
		if (stackHead == nullptr)
		{
			return nullptr;
		}
		else
		{
			stackNode<Queue>* temp = stackHead;
			stackHead = stackHead->nextStackNode;

			temp->nextStackNode = nullptr;
			return temp->queueHead;
		}
	}

	void reverseStack() 
	{
		if (!isEmpty()) {
			Queue* top = pop();
			reverseStack();
			pushBack(top);
		}
	}

	~stack()
	{
		while (stackHead != nullptr)
		{
			Queue* temp = stackHead->queueHead;
			while (!temp->isEmpty())
			{
				temp->popFront();
			}
			stackHead = stackHead->nextStackNode;
		}
		
	}

	bool isEmpty()
	{
		return (stackHead == nullptr);
	}

};
