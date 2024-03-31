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
	Node* _root;

	void swap(MySet& rhs) noexcept {
		swap(_root, rhs.get_root());
	}

	void copy_data(Node* node) {
		if (node != nullptr) {
			this->insert(node->_data);
			copy_data(node->_left);
			copy_data(node->_right);
		}
	}

	Node* maximum(Node* node) {
		while (node->_right != nullptr) {
			node = node->_right;
		}
		return node;
	}

	Node* erase_node(Node* node, int key, bool& del) {
		if (node == nullptr) return node;
		if (key < node->_data) node->_left = erase_node(node->_left, key, del);
		else if (key > node->_data) node->_right = erase_node(node->_right, key, del);
		else {
			if (node->_left == nullptr) {
				Node* temp = node->_right;
				delete node;
				del = true;
				return temp;
			}
			else if (node->_right == nullptr) {
				Node* temp = node->_left;
				delete node;
				del = true;
				return temp;
			}
			Node* temp = maximum(node->_left);
			node->_data = temp->_data;
			node->_left = erase_node(node->_left, temp->_data, del);
		}
		return node;
	}

public:
	MySet() : _root(nullptr) {}

	MySet(const MySet& rhs) : _root(nullptr) {
		copy_data(rhs.get_root());
	}

	MySet& operator=(const MySet& rhs) {
		MySet copy(rhs);
		swap(copy);
		return *this;
	}
	
	int* get_root() const {
		return _root;
	}

	int* get_root() {
		return _root;
	}

	bool contains(int key) {
		Node* node = _root;
		while (node) {
			if (key < node->_data) node = node->_left;
			else if (key > node->_data) node = node->_right;
			else return true;
		}
		return false;
	}

	bool insert(int key) {
		if (!_root) {
			_root = new Node(key);
			return true;
		}
		if (contains(key)) return false;
		Node* node = _root;
		bool left = false;
		while (node) {
			if (key < node->_data) {
				if (node->_left != nullptr) {
					node = node->_left;
					continue;
				}
				left = true;
				break;
			}
			else if (key > node->_data) {
				if (node->_right != nullptr) {
					node = node->_right;
					continue;
				}
				break;
			}
		}
		if (left) node->_left = new Node(key);
		else node->_right = new Node(key);
		return true;
	}

	bool erase(int key) {
		bool del = false;
		_root = erase_node(_root, key, del);
		return del;
	}
};