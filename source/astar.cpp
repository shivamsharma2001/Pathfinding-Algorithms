#include<bits/stdc++.h>
#include "astar.hpp"
using namespace std;
astar::node<unsigned> nodes[900223];
//Function to add edge between two nodes of a graph
void addedge(astar::node<unsigned>& u, astar::node<unsigned> &v, unsigned w) {
  u.edges.emplace_back(&v, w);
}
//Note:please provide destination node as command line input to run this file
int main(int argc, char **argv) {
  clock_t start, end;
  //start=clock();

  string s = argv[1];
  int destination = 0;
  for (int i = 0; i < s.length(); i++)
    destination = destination * 10 + s[i] - '0';
  ifstream infile("dataset.txt");//opening file "dataset.txt" in reading mode
  char a;
  int u, v, dist;
  start = clock(); //starting measuring time
  //reading file "datset.txt" and adding edge between nodes of the graph
  while (infile >> a >> u >> v >> dist) {
    addedge(nodes[u], nodes[v], dist);
  }

  int source = 1;
  int distance = astar::path(nodes[source], nodes[destination]); //finding the path length
  end = clock(); //finishing measuring time
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC); //total time taken
  cout << "Source Node\tDestination Node\tDistance\t\tTime Taken(in ms)\n";
  cout << source << "\t\t\t" << destination << "\t\t";
  if (distance == -1)
    cout << -1;
  else
    cout << distance;
  cout << "\t\t\t" /*<< "Time taken by program is : " */ << fixed
       << time_taken * 1000 << setprecision(10) << endl;
  //cout << "msec " << endl;
  cout << "\n\nNote:\nIt is NOT guaranted to always get optimal path using Astar Algorithm.\n\n2.Distance=-1 means Path Doesn't Exists.\n" << endl;

}
