//4963
#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int cnt=0;

void dfs(int graph[][51],bool visit[][51],int i,int j,int W1,int H1);

int main(){

  int W,H;
  int mygraph[51][51];
  bool visited[51][51];


  while(1){
    memset(mygraph,0,sizeof(mygraph));
    memset(visited,false,sizeof(visited));
    cnt =0;
    cin >> W >> H;
    if(W==0 && H == 0) break;
    for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
        cin >> mygraph[i][j];
      }
    }

    for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
        if(!visited[i][j] && mygraph[i][j]){
          dfs(mygraph,visited,i,j,W,H);
          cnt++;
        }
      }
    }

    cout << cnt << endl;
  }



  return 0;
}


void dfs(int graph[][51],bool visit[][51],int i,int j,int W1,int H1){
  visit[i][j]=true;

  //  0 1 2 
  //  3   4
  //  5 6 7

  pair<int,int> adjnum[8] = { {i-1,j-1},{i-1,j},{i-1,j+1},{i,j-1},{i,j+1},{i+1,j-1},{i+1,j},{i+1,j+1}   };
  int adj[8];
  for(int a=0;a<8;a++) adj[a]=1; // index 0~7

  if(i==1) adj[0]=adj[1]=adj[2]=0;
  if(i==H1) adj[5]=adj[6]=adj[7]=0;
  if(j==1)  adj[0]=adj[3]=adj[5]=0;
  if(j==W1) adj[2]=adj[4]=adj[7]=0;

  for(int a=0;a<8;a++){
    if(adj[a] &&  graph[adjnum[a].first][adjnum[a].second] && !visit[adjnum[a].first][adjnum[a].second]){
      dfs(graph,visit,adjnum[a].first,adjnum[a].second,W1,H1);
    }
  } 


  return;
}
