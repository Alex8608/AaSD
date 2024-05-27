#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

template<typename Vertex, typename Distance = double>
class Graph {
	unordered_map<Vertex, vector<pair<Vertex, Distance>>> _data;

	bool relax(const Vertex& a, const Vertex& v, unordered_map<Vertex, pair<Vertex, Distance>>& dist_pred) {
		auto iter = _data.at(a).begin();
		while (iter->first != a) ++iter;
		if (dist_pred.at(v).second > dist_pred.at(a).second + iter->second) {
			dist_pred.at(v).second = dist_pred.at(a).second + iter->second;
			dist_pred.at(v).first = a;
			return true;
		}
		return false;
	}
public:
	Graph() {
		_data = unordered_map<Vertex, vector<pair<Vertex, Distance>>>();
	}

	bool has_vertex(const Vertex& v) const {
		return _data.contains(v);
	}

	void add_vertex(const Vertex& v) {
		_data.insert(make_pair(v, vector<pair<Vertex, Distance>>()));
	}

	bool remove_vertex(const Vertex& v) {
		if (!has_vertex(v)) return false;
		for (size_t i = 0; i < _data.size(); ++i)
		{
			if (i == v) continue;
			int j = 0;
			auto iter = _data[i].begin();
			while (iter != _data[i].end()) {
				if (iter->first == v) {
					_data[i].erase(iter);
					iter = _data[i].begin() + j;
				}
				else {
					++iter;
					++j;
				}
			}
		}
		_data.erase(v);
		return true;
	}

	void print() const {
		for (auto& v : _data) {
			cout << v.first << ": ";
			for (auto& e : v.second)
			{
				cout << e.first << " (" << e.second << "), ";
			}
			cout << endl;
		}
		cout << endl;
	}

	vector<Vertex> vertices() const {
		vector<Vertex> vert;
		for (auto& v : _data) {
			vert.push_back(v.first);
		}
		return vert;
	}

	void add_edge(const Vertex& from, const Vertex& to, const Distance& dist) {
		if (!has_vertex(from) || !has_vertex(to)) return;
		_data[from].push_back(make_pair(to, dist));
	}

	bool remove_edge(const Vertex& from, const Vertex& to) {
		if (!has_vertex(from) || !has_vertex(to)) return false;
		auto iter = _data[from].begin();
		int i = 0;
		while (iter != _data[from].end()) {
			if (iter->first == to) {
				_data[from].erase(iter);
				iter = _data[from].begin() + i;
			}
			else {
				++iter;
				++i;
			}
		}
		return true;
	}

	bool remove_edge(const Vertex& from, const Vertex& to, const Distance& d) {
		if (!has_vertex(from) || !has_vertex(to)) return false;
		auto it = _data[from].begin();
		while (it != _data[from].end() && it->first != to && it->second != d) ++it;
		if (it == _data[from].end()) return false;
		_data[from].erase(it);
		return true;
	}

	bool has_edge(const Vertex& from, const Vertex& to) const {
		if (!has_vertex(from) || !has_vertex(to)) return false;
		auto it = _data.at(from).begin();
		while (it != _data.at(from).end() && it->first != to) ++it;
		return it != _data.at(from).end();
	}

	bool has_edge(const Vertex& from, const Vertex& to, const Distance& d) const {
		if (!has_vertex(from) || !has_vertex(to)) return false;
		auto it = _data.at(from).begin();
		while (it != _data.at(from).end() && !(it->first == to && it->second == d)) ++it;
		return it != _data.at(from).end();
	}

	vector<pair<Vertex, Distance>> edges(const Vertex& v) const {
		vector<pair<Vertex, Distance>> edges;
		for (auto& e : _data.at(v)) {
			edges.push_back(e);
		}
		return edges;
	}

	size_t degree(const Vertex& v) const {
		return _data.at(v).size();
	}

	size_t order() const {
		return _data.size();
	}

	vector<Vertex> walk(const Vertex& start_vertex) {
		vector<bool> visited;
		for (size_t i = 0; i < _data.size(); i++)
		{
			visited.push_back(false);
		}
		vector<Vertex> walk;
		queue<Vertex> queue;
		queue.push(start_vertex);
		while (!queue.empty()) {
			Vertex u = queue.front();
			walk.push_back(u);
			queue.pop();
			for (const auto& v : _data[u]) {
				if (!visited[v.first]) {
					visited[v.first] = true;
					queue.push(v.first);
				}
			}
		}
		return walk;
	}

	vector<pair<Vertex, Distance>> shortest_path(const Vertex& from, const Vertex& to) {
		unordered_map<Vertex, pair<Vertex, Distance>> dist_pred;
		vector<pair<Vertex, Distance>> path;
		vector<Vertex> vertices = this->vertices();
		stack<int> stack;
		for (auto& e : vertices) {
			dist_pred[e] = make_pair(-1, 1e9);
		}
		dist_pred[from] = make_pair(-1, 0);
		stack.push(from);
		while (!stack.empty()) {
			Vertex u = stack.top();
			stack.pop();
			for (auto& v : _data.at(u)) {
				if (relax(u, v.first, dist_pred)) stack.push(v.first);
			}
		}
		Vertex finish = to;
		pair<Vertex, Distance> pred = dist_pred.at(finish);
		if (pred.second == 1e9) {
			path.insert(path.begin(), make_pair(finish, pred.second));
		}
		else {
			while (finish != from) {
				path.insert(path.begin(), make_pair(finish, pred.second));
				finish = pred.first;
				pred = dist_pred.at(finish);
			}
		}
		path.insert(path.begin(), make_pair(from, 0));
		return path;
	}

	const Vertex& optimal_point() {
		vector<Vertex> vertices = this->vertices();
		Vertex warehouse = Vertex();
		Distance max = 1e9;
		for (auto& from : vertices) {
			Distance current_max = 0.0;
			Vertex current_warehouse = Vertex();
			for (auto& to : vertices) {
				vector<pair<Vertex, Distance>> path = shortest_path(from, to);
				Distance d = (path.end() - 1)->second;
				if (d > current_max && d != 1e9) {
					current_max = d;
				}
			}
			if (current_max != 0.0 && current_max < max) {
				warehouse = from;
				max = current_max;
			}
		}
		return warehouse;
	}
};
