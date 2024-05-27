#include "lab6.h"

int main() {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_vertex(6);
	graph.add_edge(0, 1, 6);
	graph.add_edge(0, 2, 3);
	graph.add_edge(0, 3, 4);
	graph.add_edge(0, 4, 5);
	graph.add_edge(0, 5, 2);
	graph.add_edge(0, 6, 10);
	graph.add_edge(1, 2, 6);
	graph.add_edge(2, 3, 4);
	graph.add_edge(3, 4, 2);
	graph.add_edge(5, 0, 2);
	graph.add_edge(5, 1, 5);
	graph.add_edge(5, 2, 3);
	graph.add_edge(5, 3, 6);
	graph.add_edge(5, 4, 1);
	graph.add_edge(5, 6, 9);
	graph.print();

	cout << endl << graph.order() << endl;
	cout << endl << graph.has_vertex(6) << endl;
	cout << endl << graph.remove_vertex(6) << endl;
	graph.print();
	cout << endl << graph.order() << endl;
	cout << endl << graph.has_vertex(6) << endl;


}