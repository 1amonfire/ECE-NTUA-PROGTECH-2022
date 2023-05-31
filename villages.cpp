#include <iostream>  
#include <cstdio>  
  
using namespace std;  
  
int main(){  
  
  int N, M, K, A, B, groups;  
  int r1, r2, r2help;  
  int h1, h2;  
  cin >> N >> M >> K;  
  
  groups = 0;  
  groups = N;  
  int villages[N+1];  
  for(int i=1; i<=N; i++)  
    villages[i] = i;  
  
  for(int i=0; i<M; ++i){  
    scanf ("%d%d", &A , &B);  
    h1 = h2 = 0;  
    r1 = villages[A];  
    r2 = villages[B];  
  
    while ( villages[r1] !=r1)      { h1++; r1 = villages[r1];    }  
    while ( villages[r2] !=r2)  { h2++; r2help = r2; r2 = villages[r2]; villages[r2help] = r1;}  
    if   (villages[r1] != r2) groups--;  
    if   (h1>h2)              villages[r1] = r2;  
    else                      villages[r2] = r1;  
  }  
  
  if(groups - K <=0) cout << "1\n";  
  else cout << (groups - K) << endl;  
  
}  
