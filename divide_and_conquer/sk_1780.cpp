//1780

#include <iostream>
#define MAXNUM 3000

using namespace std;

int N;
int arr[MAXNUM+1][MAXNUM+1];
int n1=0; // -1
int n2=0; // 0
int n3=0; // 1

void Input();
void  search( int y,int x ,int width );
void Output();


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  search(0,0,N);
  Output();


  return 0;
}


void Input(){
  cin >> N;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> arr[i][j];
    }
  }
}

void search( int y,int x ,int width ){
  if(width==1){
    if(arr[y][x]==-1) n1++;
    else if(arr[y][x]==0)  n2++;
    else if(arr[y][x]==1)  n3++;
    return;
  }

  

  int num = width/3;
  int haha;
  bool iden=true;

  for(int i=y;i<y+width;i++){
    for(int j=x;j<x+width;j++){
      if(i==y && j==x) haha = arr[i][j];
      else{
        if(haha!=arr[i][j]) iden = false;
      }
    }
  }
  if(iden){
    if(haha==-1) n1++;
    if(haha==0)  n2++;
    if(haha==1)  n3++;
  }
  else if(!iden){
    for(int a=0;a<3;a++){
      for(int b=0;b<3;b++){
        search(y+(a*num),x+(b*num),num);
      }
    }
  }
}

void Output(){
  cout << n1 << endl;
  cout << n2 << endl;
  cout << n3;
}

