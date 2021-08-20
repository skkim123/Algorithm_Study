//11724
#include <iostream>

using namespace std;

void dfs(int graph[][1001],bool visited1[],int n1,int start);


int main(){
  int n,m;
  int a,b;
  int mygraph[1001][1001]={0,};
  bool visited[1001]={0,};

  int componum=0;

  cin >> n >> m;

  for(int i=1;i<=m;i++){
    cin >> a >> b;
      mygraph[a][b]=1;
      mygraph[b][a]=1;
  }


  for(int j=1;j<=n;j++){
      
    if(visited[j]==0){
        dfs(mygraph,visited,n,j);
        componum++;
    }
  }

  cout << componum;

  return 0;
}




void dfs(int graph[][1001],bool visited1[],int n1,int start){
  visited1[start]=1;

  for(int i=1;i<=n1;i++){
    if(graph[start][i]==1 && visited1[i]==0){
      dfs(graph,visited1,n1,i);
    }
  }

}
