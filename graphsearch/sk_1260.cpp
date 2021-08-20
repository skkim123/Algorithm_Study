//1260
#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void dfs( int graph[][1001],bool visited[],int n1,int v1);
void bfs( int graph[][1001],bool visited[],int n1, int v1);



int main(){

  int n,m,v;
  int mygraph[1001][1001]={0,};
  bool visited1[1001]; //dfs
  bool visited2[1001]; //bfs
  cin >> n >> m >> v;
  
  int a,b;
  for(int i=1;i<=m;i++){
    cin >> a >> b;
    mygraph[a][b]=1;
    mygraph[b][a]=1;
  }

  dfs(mygraph,visited1,n,v);
  cout << endl;
  bfs(mygraph,visited2,n,v);


  return 0;
}



void dfs( int graph[][1001],bool visited[],int n1,int v1){
   visited[v1]=1;
   cout << v1 << " ";
   
   int num = v1;
   for(int i=1;i<=n1;i++){
     
     if(graph[num][i]==1 && visited[i]==0){
       dfs(graph,visited,n1,i);
     }

   }
   


}

void bfs( int graph[][1001],bool visited[],int n1, int v1){
  queue<int> q;

  int num = v1;
  visited[v1]=1;
  cout << v1 << " ";

  while(num!=0){
      for(int i=1;i<=n1;i++){
        if(graph[num][i]==1 && visited[i]==0){
          visited[i]=1;
          q.push(i);
          cout << i << " ";
        }
      
      }
      num = q.front();
      q.pop();
  }

}
