#include <iostream>  
#include <cstdio>  
#include <map>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
class Graph {  
  public:    
    Graph(int V)               { vertices = V ; adj = new vector<int>[V]; }  
    ~Graph()                   { delete []adj;             }  
    void addEdge(int u, int v) { adj[u].push_back(v);      }  
    bool cycle (vector<int> &path) const{  
      bool endofcycle = false;  
      int visited[vertices];  
      for(int i=0; i < vertices; ++i) visited[i] = 0;  
      for (int i = 0; i<vertices; ++i){      
        if(cyclehelp(path, visited, endofcycle, adj[i])) {reverse(path.begin(), path.end()); return true;}  
      }  
      return false;   
    }  
  
  private:  
    vector<int> *adj;  
    int vertices;  
    bool cyclehelp(vector<int> &path, int *visited, bool &endofcycle, vector<int> adjhelp ) const{  
      for(auto const& it : adjhelp){  
        if(visited[it] == 2) return false;  
        if(visited[it] == 1){ visited[it] = 3; path.push_back(it); return true;}  
        visited[it] = 1;  
        if(cyclehelp(path, visited, endofcycle, adj[it])){  
          if(visited[it] == 3)  endofcycle = true;   
          else if(!endofcycle) path.push_back(it);   
          return true;}  
        visited[it] = 2;  
      }  
      return false;  
    }  
};  
  
  
  
#ifndef CONTEST  
int main() {  
  int V, E;  
  cin >> V >> E;  
  Graph g(V);  
  for (int i = 0; i < E; ++i) { int u, v; cin >> u >> v; g.addEdge(u, v); }  
  vector<int> path;    
  bool c = g.cycle(path);  
  if(c) {  
    cout << "CYCLE: ";  
    for(int i = 0; i < path.size(); ++i)   
      cout << path[i] << (i == path.size()-1 ? "\n" : " ");  
  } else {  
    cout << "NO CYCLE"<<endl;  
  }  
}  
#endif
