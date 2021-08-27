//7576

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int cnt=0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int mato[][1001],bool visit[][1001],int M,int N);

int main(){
  int M,N;
  int tomato[1001][1001];
  bool visited[1001][1001];
  memset(visited,false,sizeof(visited));

  cin >> M >> N;//M:garo N;sero
  int minusone=0;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin >> tomato[i][j];
      if(tomato[i][j]==-1)  minusone++;
    }
  }

  bfs(tomato,visited,M,N);
  
  int discrim =0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      discrim+=tomato[i][j];
    }
  }

  if(discrim!=(M*N)-(2*minusone))
    cout << -1;
  else{
    cout << cnt;
  }



  return 0;
}






void bfs(int mato[][1001],bool visit[][1001],int M,int N){
  vector<pair<int,int>> start;
  queue<pair<int,int>> q;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      if(mato[i][j] == 1){
        start.push_back(make_pair(i,j));
        visit[i][j] = true;
      }
      
    }
  }
  for(int i=0;i<(int)start.size();i++){
    q.push(start[i]);
  }
  q.push(make_pair(-1,-1)); //detection


  while(!q.empty()){
    pair<int,int> pair1 = q.front();
    q.pop();
    int y = pair1.first; 
    int x = pair1.second;

    if(x == -1 && y== -1){
      if(q.empty()) break;


        cnt++;
        q.push(make_pair(-1,-1));
        continue;
    }

    for(int i=0;i<4;i++){
      int nx= x+ dx[i];
      int ny= y +dy[i];

      if(1<=nx && nx<=M && 1<=ny && ny <=N){
        if(!visit[ny][nx] && mato[ny][nx]==0){
          q.push(make_pair(ny,nx));
          visit[ny][nx] = true;
          mato[ny][nx]=1;
        }
      }

    }

  
  }


}

