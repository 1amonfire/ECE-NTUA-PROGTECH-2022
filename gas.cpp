#include <iostream>      
#include <cstdio>      
#include <map>      
#include <vector>      
    
using namespace std;      
    
struct cost{      
  int km;      
  int town;      
};      
    
bool possibleroad(int A, int C,  int B, vector<int> &road, map<int ,vector<cost>> roadmap, int *visited){      
  road.push_back(A);       
  visited[A] = 1;         
  for(auto const& it: roadmap[A]){          
    if (it.km > C || visited[it.town]) continue;      
    else {             
      if (it.town == B) {      
        road.push_back(it.town);       
        return true;      
      }      
      if (possibleroad(it.town, C, B, road, roadmap, visited)) return true;      
    }        
  }      
  road.pop_back();      
  return false;      
}      
    
int getrefills(int tank, vector<int> &road, map<int, map<int, int>> &roadhelp){    
  int refills = 1;    
  int C = tank;    
  for (vector<int>::iterator it = road.begin(); it != road.end()-1; ++it){    
    C = C - roadhelp[*it][*(it+1)];    
    if(C < 0) {C = tank - roadhelp[*it][*(it+1)]; refills++;}    
  }    
  if(C < 0) { refills++;}    
  return refills;    
}    
    
int main(){      
  int N, M, U, V, L, Q, A, B, C;      
  cost diesel1, diesel2;      
  cin >> N >> M;      
  map<int ,vector<cost>> roadmap;      
  map<int, map<int, int>> roadhelp;    
    
  for(int i=0; i<M; ++i){      
    scanf("%d%d%d", &U, &V, &L);      
    diesel1.km = diesel2.km = L;      
    diesel1.town = V;      
    diesel2.town = U;      
    roadmap[U].push_back(diesel1);      
    roadmap[V].push_back(diesel2);      
    roadhelp[V][U] = L;    
    roadhelp[U][V] = L;    
    
  }      
  cin >> Q;      
  for(int i=0; i<Q; ++i){      
    scanf("%d%d%d", &A, &B, &C);    
    int  fill = 1;      
    int *f = &fill;      
    int visited[N];      
    bool refill = false;      
    for(int i=0; i<N; ++i) visited[i] =0;      
    vector<int> road;      
    if(possibleroad(A, C, B, road, roadmap, visited)) {      
      cout << "POSSIBLE: " << getrefills(C, road, roadhelp)  <<" fill(s),";      
      for(vector<int>::iterator it = road.begin(); it != road.end(); ++it) {      
        cout << " " << *it;      
      }      
      cout << endl;      
    }      
    else cout << "IMPOSSIBLE" << endl;      
  }   
}     
