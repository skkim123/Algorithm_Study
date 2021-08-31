//2146

#include <iostream>
#include <queue>
#include <string.h>

#define MIN( x, y ) ( ( x  > y )? (y) : (x) )

using namespace std;

int arr[101][101]={0,};
bool initialvisit[101][101];
bool visited[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt=1;
int days=1;

queue< pair<int ,pair<int,int> > > q;

bool IsInside(int ny, int nx , int N);

void dfs(int i,int j,int N);

int main (){

  memset(initialvisit,false,sizeof(initialvisit));
  memset(visited,false,sizeof(visited));

  int N;

  cin >> N;


  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> arr[i][j];
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(!initialvisit[i][j] && arr[i][j]){
        dfs(i,j,N);
        cnt++;
      }
    }
  }

  //bfs
  int disc = -1;
  int z;
  int stopit = 0;
  int min = 999999;

  while(!q.empty()){
    z = q.front().first;

    if(disc > z) {
      if(stopit) {
        break;
      }
      days++;
    }
    

    int y = q.front().second.first;
    int x = q.front().second.second;

    q.pop();

    for(int k=0;k<4;k++){
      int ny = y + dy[k];
      int nx = x + dx[k];

      if(visited[ny][nx] && arr[ny][nx] != arr[y][x]){
        if(arr[ny][nx] > arr[y][x]){
          stopit =1;
          min = MIN(min,(2*days-2));
        }


        if(arr[ny][nx] < arr[y][x]){
          stopit =1;
          min = MIN(min,(2*days-1));
        }
      }

      if(  !arr[ny][nx] && !visited[ny][nx] && IsInside(ny,nx,N) ){

        q.push({z,{ny,nx}});
        visited[ny][nx] = true;
        arr[ny][nx] = z;
      }

    }

    disc = z;

  }

  cout << min;







  return 0;
}

void dfs(int i, int j,int N){
  initialvisit[i][j] = true;
  arr[i][j] = cnt;
  q.push( { cnt ,{i,j} } );
  visited[i][j] = true;

  for(int k=0;k<4;k++){
    int ny = i + dy[k];
    int nx = j + dx[k];

    if(  arr[ny][nx] && !initialvisit[ny][nx] && IsInside(ny,nx,N) ){
      dfs(ny,nx,N);
    }
  }
}

bool IsInside(int ny, int nx, int N){
  return (1<=nx && 1 <= ny && nx <= N && ny <= N);
}


