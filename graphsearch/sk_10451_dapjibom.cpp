//10451
#include <iostream>
#include <cstring>

using namespace std;

void dfs(int graph[][1001],bool visit[],int start,int perm);

int main(){
  int T;
  cin >> T;

  while(T--){
    int mygraph[1001][1001]={0,};
    int permnum,a;
    bool visited[1001];
    memset(visited,false,sizeof(visited)); //initialize
    
    cin >> permnum;

    for(int i=1;i<=permnum;i++){
      cin >> a;
      mygraph[i][a]=1;
      mygraph[a][i]=1;
    }
    int num=0;
    for(int j=1;j<=permnum;j++){
      if(!visited[j]){
        dfs(mygraph,visited,j,permnum);
        num++;
      }
    }

    cout << num << endl;

  }

  return 0;
}

void dfs(int graph[][1001],bool visit[],int start,int perm){
  visit[start] = true;

  for(int i=1;i<=perm;i++){
    if(graph[start][i]==1 && !visit[i]){  
      dfs(graph,visit,i,perm);
    }
  }
  return;
}


//reference : https://kyunstudio.tistory.com/125
