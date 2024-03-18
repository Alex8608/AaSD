#pragma once
#include <iostream>

using namespace std;

struct Node {
	int _data;
	Node* _left, * _right;
	Node(int data) : _data(data), _left(nullptr), _right(nullptr) {}
};


class MySet {
private:
	int* _root;

	void swap(MySet& rhs) noexcept {
		swap(_root, rhs.get_root());
	}
public:
	MySet() : _root(nullptr) {}

	
	int* get_root() const {
		return _root;
	}

	int*& get_root() {
		return _root;
	}
};