//11729

#include <iostream>
#include <cmath>

using namespace std;

int N;

void Input();
void move(int babels,int start,int end);
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();
  return 0;
}


void Input(){
  cin >> N;
}


void move(int babels,int start,int end){ 
  if(babels==1) cout << start << " " << end << "\n";
  else{
    int another_one = (6/start)/end;
    move(babels-1,start,another_one);
    cout << start << " " << end << "\n";
    move(babels-1,another_one,end);
  }
}

void Solve(){
  cout << ((int)pow(2,N) -1) << "\n";
  move(N,1,3);
}