#include <iostream>

using namespace std;

void Input();
void Solve();

int N,M,K,cnt=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();

  return 0;
}

void Input(){
  cin >> N >> M >> K;
}

void Solve(){
  int num = N+M;
  while( (N>=2) && (M>=1) && (num>=(K+3))  ){
    N-=2;
    M-=1;
    num-=3;
    cnt++;
  }
  cout << cnt;
}