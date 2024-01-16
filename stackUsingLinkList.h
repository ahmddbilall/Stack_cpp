#pragma once
#include <iostream>
using namespace std;


template<class N>
class Node {
public:
	N data;
	Node* next;
	Node* previous;
	Node(N data){
		this->data = data;
		next = previous = nullptr;
	}
};

template<class l>
class List {
	Node<l>* head;
	Node<l>* tail;

public:
	List(){
		head = nullptr;
		tail = nullptr;
	}
	void insert(l element){
		Node<l>* N = new Node<l>(element);
		if (head == nullptr){
			head = N;
			tail = N;
			return;
		}
		else{
			tail->next = N;
			N->previous = tail;
			tail = N;
		}
	}

	L last(){
		if (tail)
			return tail->data;
	}

	void removeLast(){
		Node<l>* n = tail;
		tail = tail->previous;
		delete n;
	}
};

template<class S>
class StackWithList {
	List<S>* list;
	int siz;
public:
	StackWithList(){
		list = nullptr;
		siz = 0;
	}

	StackWithList push(S element){
		if (list == nullptr){
			list = new List<S>;
			list->insert(element);
		}
		else {
			list->insert(element);
		}
		siz++;
		return *this;
	}

	StackWithList pop(){
		if (list == nullptr){
			return *this;
		}
		else {
			siz--;
			list->removeLast();
			return *this;
		}
	}

	S top(){
		return list->last();
	}

	int size(){
		return siz;
	}

	bool empty(){
		return (siz == 0);
	}
};