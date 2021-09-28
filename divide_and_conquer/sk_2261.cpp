//2261
#include <iostream>


using namespace std;
int N,n1,n2;
int arr[20002][20002]={0,}; // => y+10001:1~20001  x +10001 : 1~20001
bool Hassamepoint = false;
long long min_square = 9999999999;

void Input();
void Inspect();
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  if(!Hassamepoint){

  }
  else{
    cout << 0;
  }
  return 0;
}


void Input(){
  cin >> N;
  for(int i=1;i<=N;i++) {
    cin >> n1; //x coord
    cin >> n2; //y coord
    if(n1 == n2) Hassamepoint = true;
    arr[n2+10001][n1+10001] = 1;
  }
}

void Inspect(){ // 1이 N개인 거 미리 main 함수에서 확정

}

void Solve(){

}

