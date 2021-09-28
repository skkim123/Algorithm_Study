//1783
#include <iostream>
#include <math.h>

using namespace std;

int N,M;

void Input();
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();
  return 0;
}

void Input(){
  cin >> N >> M;
}

void Solve(){
  if(N==1) cout << 1;
  else if(N==2){
 // 1 1 2 2 3 3 4 4
    if(M>=7) cout << 4;
    else{
      cout << ceil( ((double)M) /2);
    }
  }
  else{ // N>=3
    if(M>=7) cout << (M-2);
    else if(M<=3) cout << M;
    else{
      cout << 4;
    }
    
  }
}