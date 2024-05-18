#pragma once
#include<iostream>
#include<string>
#include<random>

using namespace std;

const string CHARS = "abcdefghijklmnopqrstuvwxyz";

template<class K, class T>
class MyHashTable {
public:
	struct Pair {
		K _key;
		T _value;
		bool _flag;
		Pair(K key, T value) : _key(key), _value(value), _flag(false) {}
		Pair() : _key(K()), _value(T()), _flag(false) {}
	};

private:
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

	void insert(K key, T value) {
		int index = hash(key);
		int i = 0;
		while (true) {
			if (_data[(index + i) % _capacity]._key == K()) {
				_data[(index + i) % _capacity] = Pair(key, value);
				return;
			}
			++i;
			if ((index + i) % _capacity == index) break;
		}
	}

	void insert_or_assign(K key, T value) {
		int index = hash(key);
		if (!search(key)) {
			insert(key, value);
		}
		else {
			int i = 0;
			while (true) {
				if (_data[(index + i) % _capacity]._key == key) {
					_data[(index + i) % _capacity]._value = value;
					return;
				}
				++i;
				if ((index + i) % _capacity == index) break;
			}
		}
	}

	bool erase(K key) {
		int index = hash(key);
		int i = 0;
		while (true) {
			Pair current = _data[(index + i) % _capacity];
			if (current._key == key) break;
			++i;
			if ((index + i) % _capacity == index) return false;
		}
		_data[(index + i) % _capacity]._key = K();
		_data[(index + i) % _capacity]._value = T();
		_data[(index + i) % _capacity]._flag = true;
		return true;
	}

	bool contains(T value) {
		for (size_t i = 0; i < _capacity; i++)
		{
			if (_data[i]._value == value) return true;
		}
		return false;
	}

	T* search(K key) {
		int index = hash(key);
		int i = 0;
		while (_data[(index + i) % _capacity]._key != K() || _data[(index + i) % _capacity]._flag != false) {
			Pair current = _data[(index + i) % _capacity];
			if (current._key == key) {
				return &current._value;
			}
			++i;
			if ((index + i) % _capacity == index) break;
		}
		return nullptr;
	}

	void print() const {
		for (size_t i = 0; i < _capacity; i++)
		{
			cout << "Key: " << _data[i]._key << ", Value: " << _data[i]._value << endl;
		}
		cout << endl;
	}

	int count(K key) {
		int index = hash(key);
		int i = 0;
		int counter = 0;
		while (_data[(index + i) % _capacity]._key != K()) {
			Pair current = _data[(index + i) % _capacity];
			if (current._key == key) {
				++counter;
			}
			++i;
			if ((index + i) % _capacity == index) break;
		}
		return counter;
	}

	~MyHashTable() {
		delete[] _data;
	}
};

const char T[256] = {
			 98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219,
			 61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115,
			 90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10,
			237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121,
			123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55,
			 59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222,
			197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186,
			 39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99,
			154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254,
			133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139,
			189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44,
			183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12,
			221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166,
			  3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117,
			238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110,
			 43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239
};

int pearson_hash(string s) {
	char hash = 0;
	for (const char& c : s) {
		hash = T[hash ^ c];
	}
	return (int)hash;
}

bool compare_string(int hash, string s) {
	return hash == pearson_hash(s);
}