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
public:
	struct Edge {
		Vertex from;
		Vertex to;
		Distance d;
		Edge(const Vertex& from, const Vertex& to, const Distance& d) : from(from), to(to), d(d) {};
	};
private:
	unordered_map<Vertex, vector<pair<Vertex, Distance>>> _data;

	unordered_map<Vertex, pair<Vertex, Distance>> Bellman_Ford_algorithm(const Vertex& from) {
		unordered_map<Vertex, pair<Vertex, Distance>> shortest_ways;
		vector<Vertex> vert = vertices();
		for (auto i : vert) {
			shortest_ways[i] = make_pair(-1, 1e9);
		}

		shortest_ways[from].second = 0;
		vector<Edge> _edges = edges(from);
		for (auto edge : _edges) {
			if (shortest_ways[edge.to].second > shortest_ways[from].second + edge.d) {
				shortest_ways[edge.to].second = shortest_ways[from].second + edge.d;
				shortest_ways[edge.to].first = from;
			}
		}

		for (int i = 0; i < vert.size(); ++i) {
			vector<Edge> _edges = edges(i);
			for (auto edge : _edges) {
				if ((shortest_ways[i].second != 1e9) && shortest_ways[edge.to].second > shortest_ways[i].second + edge.d) {
					shortest_ways[edge.to].second = shortest_ways[i].second + edge.d;
					shortest_ways[edge.to].first = i;
				}
			}
		}

		for (auto& [vertex, edges] : _data) {
			for (auto j : edges) {
				if ((shortest_ways[vertex].second != 1e9) && shortest_ways[j.first].second > shortest_ways[vertex].second + j.second) {
					shortest_ways.clear();
					return shortest_ways;
				}
			}
		}
		return shortest_ways;
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
		for (auto& e : _data)
		{
			Vertex i=e.first;
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
		while (iter != _data[from].end() && iter->first != to) ++iter;
		if (iter == _data[from].end()) return false;
		_data[from].erase(iter);
		return true;
	}

	bool remove_edge(const Edge& e) {
		if (!has_vertex(e.from) || !has_vertex(e.to)) return false;
		auto iter = _data[e.from].begin();
		while (iter != _data[e.from].end() && !(iter->first == e.to && iter->second == e.d)) ++iter;
		if (iter == _data[e.from].end()) return false;
		_data[e.from].erase(iter);
		return true;
	}

	bool has_edge(const Vertex& from, const Vertex& to) const {
		if (!has_vertex(from) || !has_vertex(to)) return false;
		auto iter = _data.at(from).begin();
		while (iter != _data.at(from).end() && iter->first != to) ++iter;
		return iter != _data.at(from).end();
	}

	bool has_edge(const Edge& e) const {
		if (!has_vertex(e.from) || !has_vertex(e.to)) return false;
		auto iter = _data.at(e.from).begin();
		while (iter != _data.at(e.from).end() && !(iter->first == e.to && iter->second == e.d)) ++iter;
		return iter != _data.at(e.from).end();
	}

	vector<Edge> edges(const Vertex& v) const {
		vector<Edge> vec;
		for (auto& e : _data.at(v)) {
			vec.push_back(Edge(v, e.first, e.second));
		}
		return vec;
	}

	size_t degree(const Vertex& v) const {
		return _data.at(v).size();
	}

	size_t order() const {
		return _data.size();
	}

	vector<Vertex> walk(const Vertex& start) {
		vector<bool> visited;
		for (size_t i = 0; i < _data.size(); i++)
		{
			visited.push_back(false);
		}
		vector<Vertex> vec;
		queue<Vertex> queue;
		queue.push(start);
		visited[start] = true;
		while (!queue.empty()) {
			Vertex u = queue.front();
			vec.push_back(u);
			queue.pop();
			for (const auto& v : _data[u]) {
				if (!visited[v.first]) {
					visited[v.first] = true;
					queue.push(v.first);
				}
			}
		}
		return vec;
	}

	vector<Edge> shortest_path(const Vertex& from, const Vertex& to) {
		if (!has_vertex(from) || !has_vertex(to)) throw runtime_error("Vertex is not found.");
		unordered_map<Vertex, pair<Vertex, Distance>> dist_pred = Bellman_Ford_algorithm(from);
		vector<Edge> path;
		if (dist_pred.empty()) {
			return path;
		}
		vector<Vertex> vertices = this->vertices();
		Vertex finish = to;
		pair<Vertex, Distance> pred = dist_pred.at(finish);
		if (pred.second == 1e9) {
			path.insert(path.begin(), Edge(from, finish, pred.second));
		}
		else {
			while (finish != from) {
				path.insert(path.begin(), Edge(pred.first, finish, pred.second));
				finish = pred.first;
				pred = dist_pred.at(finish);
			}
		}
		return path;
	}

	const Vertex& optimal_point() {
		vector<Vertex> vertices = this->vertices();
		Vertex warehouse = Vertex();
		Distance max = 1e9;
		for (auto& from : vertices) {
			Distance current_max = -1e9;
			Vertex current_warehouse = Vertex();
			for (auto& to : vertices) {
				if (from != to) {
					vector<Edge> path = shortest_path(from, to);
					if (path.empty()) continue;
					Distance d = (path.end() - 1)->d;
					if (d > current_max && d != 1e9) {
						current_max = d;
					}
				}
			}
			if (current_max != -1e9 && current_max < max) {
				warehouse = from;
				max = current_max;
			}
		}
		return warehouse;
	}
};
