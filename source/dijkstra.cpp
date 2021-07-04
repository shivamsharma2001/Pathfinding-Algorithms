#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define INF 1e9
#define ll long long

vector<vector<pi>>adj(800902);
vector<int>d, p;
int n = 0;
void addEdge(int u, int v, int w) {
  adj[u].push_back({v, w});
  //adj[v].push_back({u,w});
}
ll dijkstra(int s, int dest) {
  d[s] = 0;
  priority_queue<pi, vector<pi>, greater<pi>>pq;
  pq.push({0, s}); //storing dist as first parameter so that pq gets arranged in increaing order of dist
  while (!pq.empty()) {
    pi cur = pq.top();
    pq.pop();
    int u = cur.second;
    for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
      int v = (*it).first;
      int wt = (*it).second;
      if (d[v] > d[u] + wt)
      {
        d[v] = d[u] + wt;
        //p[v]=u;
        pq.push({d[v], v});
      }
    }
  }
  /*printing distance and parent
  cout<<"Distance and predessor of vertex from source "<<s<<" : \n";
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" : "<<d[i]<<" , "<<p[i]<<endl;
  }*/
  ll ans;
  for (int i = 1; i <= n; i++) {
    if (i == dest) {
      ans = d[i];
      break;
    }
  }
  return ans;
}
int main(int argc, char **argv) {
  // n:no of vertices starting from 1 , m : no of edges
  clock_t start, end;
  //start=clock();

  string s = argv[1];
  int destination = 0;
  for (int i = 0; i < s.length(); i++)
    destination = destination * 10 + s[i] - '0';
  //cout<<dest<<endl;
  ifstream infile("dataset.txt");
  char a;
  int u, v, dist;
  //astar::node<unsigned> nodes[3000];
  start = clock();
  while (infile >> a >> u >> v >> dist) {
    //cout<<u<<" "<<v<<" "<<dist<<endl;
    addEdge(u, v, dist);
    n = max(n, max(u, v));
  }

  d = vector<int>(n + 5, INF);
  int source = 1;
  ll distance = dijkstra(source, destination);
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Source Node\tDestination Node\tDistance\t\tTime Taken(in ms)\n";
  cout << source << "\t\t\t" << destination << "\t\t";
  if (distance >= INF)
    cout << -1;
  else
    cout << distance;
  cout << "\t\t\t" /*<< "Time taken by program is : " */ << fixed
       << time_taken * 1000 << setprecision(10) << endl;
  //cout << "msec " << endl;
  cout << "\n\nNote:\n1.It is always guaranted to get optimal path using dijkstra's Algorithm.\n2.Distance=-1 means Path Doesn't Exists.\n" << endl;
}
