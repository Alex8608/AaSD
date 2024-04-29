#pragma once
#include<iostream>
#include<string>
#include<random>

using namespace std;

const string CHARS = "abcdefghijklmnopqrstuvwxyz";

template<class K, class T>
struct Pair {
	bool _del;
	K _key;
	T _value;
	Pair(K key, T value) : _key(key), _value(value), _del(false) {}
	Pair() : _key(K()), _value(T()), _del(false) {}
};

template<class K, class T>
class MyHashTable {
	int _capacity;
	Pair* _data;
	int hash(K key) {
		return (int)fmod(key, _capacity);
	}
	Pair& operator[](int index) {
		return _data[index];
	}
	const Pair& operator[](int index) const {
		return _data[index];
	}
	int& get_capacity() {
		return _capacity;
	}
	Pair* get_data() {
		return _data;
	}
	void swap(MyHashTable& rhs) {
		swap(_capacity, rhs.get_capacity());
		swap(_data, rhs.get_data());
	}
public:
	MyHashTable(size_t capacity) : _capacity(capacity), _data(new Pair[capacity]) {
		for (size_t i = 0; i < capacity; i++)
		{
			_data[i] = Pair();
		}
	}
	MyHashTable(size_t capacity, size_t size_of_string) : _capacity(capacity), _data(new Pair[capacity]) {
		for (size_t i = 0; i < capacity; i++)
		{
			_data[i] = Pair();
		}
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(0, CHARS.size() - 1);
		for (size_t i = 0; i < _capacity; i++)
		{
			string s = "";
			for (size_t j = 0; j < size_of_string; j++)
			{
				s += CHARS[distribution(generator)];
			}
			insert(distribution(generator), s);
		}
	}
	MyHashTable(const MyHashTable& rhs) : _capacity(capacity), _data(new Pair[capacity]) {
		for (size_t i = 0; i < _capacity; i++)
		{
			_data[i] = rhs[i];
		}
	}
	MyHashTable& operator=(const MyHashTable& rhs) {
		MyHashTable copy(rhs);
		swap(copy);
		return *this;
	}