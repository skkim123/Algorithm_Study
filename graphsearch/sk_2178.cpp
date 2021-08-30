//2178

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

int mygraph[101][101];
bool visited[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int N, int M);

int main(){
  memset(visited,false,sizeof(visited));
  int N,M;
  cin >> N >> M;

  for(int i=1;i<=N;i++){
    string str;
    cin >> str;
    for(int j=1;j<=M;j++){
      mygraph[i][j]=str[j-1]-'0';
    }

  }

  bfs(N,M);

  cout << mygraph[N][M];

  return 0;
}

void bfs(int N,int M){
  pair<int,int> start = {1,1};
  queue<pair<int,int>> q;

  q.push(start);
  visited[start.first][start.second] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second; // [y][x]
    q.pop();

    for(int i=0;i<4;i++){
      int ny = y + dy[i];
      int nx = x + dx[i]; 

      if( 1<=ny && ny <=N && 1<=nx && nx <=M && mygraph[ny][nx] ==1 && !visited[ny][nx] ){
        visited[ny][nx] = true;
        mygraph[ny][nx] = mygraph[y][x] + 1;

        q.push({ny,nx});
      }
    }
    
  }
}
