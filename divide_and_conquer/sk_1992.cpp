//1992

#include <iostream>
#include <string>


using namespace std;
int N; 
char arr[65][65];

string getstring(char ch){
  string str(1,ch);
  return str;
}

void Input();
bool Isidentical(int y, int x, int width);
string Quadtree(int y, int x, int width );
void Solve(); 
void Output();

int main(){
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  Input();
  Solve();
  

  return 0;
}

void Input(){
  cin >> N;
  cin.ignore();
  string inputstr;
  for(int i=0;i<N;i++){
    getline(cin,inputstr);
    for(int j=0;j<N;j++){
      arr[i][j]=inputstr[j];
    }
  }
}

bool Isidentical(int y, int x, int width){
  int initial_point = arr[y][x];
  bool result = true;
  for(int i=y;i<y+width;i++){
    for(int j=x;j<x+width;j++){
      result = ( initial_point==arr[i][j]? result :false );
    }
  }
  return result;
}

string Quadtree(int y, int x, int width ){ // check : variables in declaration
  if(width==1) return getstring(arr[y][x]);
  else{
    if(Isidentical(y,x,width)){
      return getstring(arr[y][x]);
    }
    else{
      string str = "(";
      str+=Quadtree(y,x,width/2);
      str+=Quadtree(y,x+width/2,width/2);
      str+=Quadtree(y+width/2,x,width/2);
      str+=Quadtree(y+width/2,x+width/2,width/2);
      str+=")";
      return str;
    }
  }
}

void Solve(){
  cout << Quadtree(0,0,N);
}

