#include <iostream>
#include <string>
#include <vector>


#define MAX 10000
#define times2minus1(x) (2*x -1)

using namespace std; 
int N,num=0; // num=> number of stars in left/right line segment
int width; // 2N-1
vector<char> charvec[MAX]; // charvec[i] => ith row .. not using 0th row ,0th column
void Input();
void Initial_setting();
void Sizeup();
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
  width = times2minus1(N);
}

void Initial_setting(){
  // fill 0th column and row (not using)
  for(int i=0;i<=width+1;i++) charvec[0].push_back('x');
  for(int j=1;j<=width;j++) charvec[j].push_back('x');

  // first triangle
  charvec[1].push_back(' ');
  charvec[1].push_back(' ');
  charvec[1].push_back('*');
  charvec[1].push_back(' ');
  charvec[1].push_back(' ');

  charvec[2].push_back(' ');
  charvec[2].push_back('*');
  charvec[2].push_back(' ');
  charvec[2].push_back('*');
  charvec[2].push_back(' ');
  for(int i=0;i<5;i++) charvec[3].push_back('*');
  num=3;
}

void Sizeup(){


  for(int i=1;i<=num;i++){
    for(int j=1;j<=times2minus1(num);j++){
      charvec[num+i].push_back(charvec[i][j]);
    }
  }
  for(int i=1;i<=num;i++){
    charvec[num+i].push_back(' ');
    for(int j=1;j<=times2minus1(num);j++){
      charvec[num+i].push_back(charvec[i][j]);
    }
  }
  for(int i=1;i<=num;i++){
    vector<char>::iterator iter = charvec[i].begin();
    charvec[i].insert(iter+1,num,' ');
  }
  for(int i=1;i<=num;i++) {
    for(int j=1;j<=num;j++) charvec[i].push_back(' ');
  }

  num*=2;
}

void Solve(){
  Initial_setting();
  while(num!=N){
    Sizeup();
  }
  //sizeup loop end
  for(int i=1;i<=N;i++){
    for(int j=1;j<=times2minus1(N);j++){
      cout << charvec[i][j];
    }
    cout << '\n';
  }
}

