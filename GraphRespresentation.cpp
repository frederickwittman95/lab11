// Fred Wittman
// Dr. Hill
// COSC 2030
// 06 May 2019

#include "stdafx.h"
// A simple representation of graph using STL 
#include <vector>
#include <iostream>
using namespace std;

void addEdge_list(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Push set the vth element of the uth vector to 1
void addEdge_matrix(vector<vector<int> > &adj, int u, int v)
{
	adj[u][v] = 1;
}

// A utility function to print the adjacency list 
// representation of graph 
void printGraph_list(vector<int> adj[], int number_of_vertices)
{
	for (int v = 0; v < number_of_vertices; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (int x = 0; x<adj[v].size(); x++)
			cout << "-> " << adj[v][x];
		cout << endl;
	}
}

// Print the elements of the matrix
void printGraph_matrix(vector<vector<int> > adj, int number_of_vertices)
{
	cout << "Adjacency matrix:" << endl;
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

void in_out_Degree_list(vector<int> adj[], int number_of_vertices)
{
	// Find the in-degree of each vertex by incrementing the appropriate slot in "counter" each time a value is pointed to
	vector<int> counter(number_of_vertices, 0);
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			counter[adj[i][j]]++;
		}
	}
	// Print in-degree
	cout << endl << "In degree of adjacency list:" << endl;
	for (int i = 0; i < counter.size(); i++) {
		cout << i << ": " << counter[i] << endl;
	}

	// Find the out-degree of each vertex by getting the size of each inner array; print the out degree of each vertex
	cout << "Out degree of adjacency list:" << endl;
	for (int i = 0; i < number_of_vertices; i++) {
		cout << i << ": " << adj[i].size() << endl;
	}
}

void in_out_Degree_matrix(vector<vector<int> > adj, int number_of_vertices)
{
	// Find the in-degree of each vertex by incrementing the appropriate slot in "counter" each time a value is pointed to
	vector<int> counter(number_of_vertices, 0);
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j] == 1) {
				counter[j]++;
			}
		}
	}
	// Print in-degree
	cout << endl << "In degree of adjacency matrix:" << endl;
	for (int i = 0; i < counter.size(); i++) {
		cout << i << ": " << counter[i] << endl;
	}

	// Find the out-degree of each vertex by counting the 1's in each inner vector
	cout << "Out degree of adjacency matrix:" << endl;
	int outdegree = 0;
	for (int i = 0; i < number_of_vertices; i++) {
		outdegree = 0;
		for (int j = 0; j < number_of_vertices; j++)
			if (adj[i][j] == 1) {
				outdegree++;
			}
		cout << i << ": " << outdegree << endl;
	}
}

// Driver code 
int main()
{
	const int number_of_vertices = 5;
	vector<int> adjecency_list[number_of_vertices];
	vector<vector<int> > adjecency_matrix(number_of_vertices, vector<int>(number_of_vertices, 0));
	cout << adjecency_matrix[0][4] << endl;	//Example of how to access elements on a vector of vectors.
	addEdge_list(adjecency_list, 0, 1);
	addEdge_list(adjecency_list, 0, 4);
	addEdge_list(adjecency_list, 1, 2);
	addEdge_list(adjecency_list, 1, 3);
	addEdge_list(adjecency_list, 1, 4);
	addEdge_list(adjecency_list, 2, 3);
	addEdge_list(adjecency_list, 3, 4);
	printGraph_list(adjecency_list, number_of_vertices);
	in_out_Degree_list(adjecency_list, 5);

	// Testing harness for the adjacency matrix; it uses the same values as those used for the adjacency list testing harness
	addEdge_matrix(adjecency_matrix, 0, 1);
	addEdge_matrix(adjecency_matrix, 0, 4);
	addEdge_matrix(adjecency_matrix, 1, 2);
	addEdge_matrix(adjecency_matrix, 1, 3);
	addEdge_matrix(adjecency_matrix, 1, 4);
	addEdge_matrix(adjecency_matrix, 2, 3);
	addEdge_matrix(adjecency_matrix, 3, 4);

	cout << endl;
	printGraph_matrix(adjecency_matrix, number_of_vertices);
	in_out_Degree_matrix(adjecency_matrix, number_of_vertices);
	return 0;
}

