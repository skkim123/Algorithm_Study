//11047
#include <iostream>

using namespace std;
int N,K,leftmoney,cnt=0;
int value[11];

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
  cin >> N >> K;
  for(int i =1;i<=N;i++){
    cin >> value[i];
  }
  leftmoney = K;
}

void Solve(){
  for(int i=N;i>=1;i--){
    while(leftmoney>=value[i]){
      leftmoney-=value[i];
      cnt++;
    }
  }
  cout << cnt;
}