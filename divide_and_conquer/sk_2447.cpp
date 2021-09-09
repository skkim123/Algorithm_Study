//2447

#include <iostream>
#include <string.h>

#define MAX 7000

using namespace std;
int N;
char arr[MAX][MAX];

void Input();
void Paintstars(int y, int x , int width);
void Output();



int main(){
  memset(arr,' ',sizeof(arr));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Paintstars(0,0,N);
  Output();

  return 0;
}

void Input(){
  cin >> N;
}

void Paintstars(int y, int x , int width){
  if(width==3){
    arr[y][x]=arr[y][x+1]=arr[y][x+2]='*';
    arr[y+1][x]=arr[y+1][x+2]='*';
    arr[y+2][x]=arr[y+2][x+1]=arr[y+2][x+2]='*';
  }
  else{
    int new_width = width/3;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(i==1 && j==1){
          continue;
        }
        Paintstars(y+new_width*i,x+new_width*j,new_width);
      }
    }

  }
}


void Output(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << arr[i][j];
    }
    cout << "\n";
  }
}