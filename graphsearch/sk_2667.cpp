//2667
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dfs(int myarr[][25],int i,int j,bool visit[][25],int n);

int real_dfs(int myarr[][25],int i,int j,bool visit[][25],int n);


int main(){

  int N;
  cin >> N;

  int arr[25][25] = {0,};
  bool visited[25][25];
  vector<int> danjinum;
  memset(visited,false,sizeof(visited)); 

  for(int i=0;i<N;i++){
    string numstr;
    cin >> numstr;
    for(int j=0;j<N;j++){
      arr[i][j] = numstr[j]-'0';
    }
  }

  for(int a=0;a<N;a++){
    for(int b=0;b<N;b++){
      if((!visited[a][b]) && (arr[a][b]==1)){
        danjinum.push_back(real_dfs(arr,a,b,visited,N));
      }
    }
  }
  sort(danjinum.begin(),danjinum.end());

  cout << danjinum.size() << endl;
  for(int d=0;d<(int)(danjinum.size());d++){
    cout << danjinum[d] << endl;
  }

  return 0;
}

int real_dfs(int myarr[][25],int i,int j,bool visit[][25],int n){
  int ret = dfs(myarr,i,j,visit,n);
  return ret;
}

int dfs(int myarr[][25],int i,int j,bool visit[][25],int n){
  int ret=1;
  visit[i][j] = true;

  vector< pair<int,int> > adj;

  if(i!=0){
    adj.push_back(make_pair(i-1,j));
  }
  if(i!=(n-1)){
    adj.push_back(make_pair(i+1,j));
  }
  if(j!=0){
    adj.push_back(make_pair(i,j-1));
  }
  if(j!=(n-1)){
    adj.push_back(make_pair(i,j+1));
  }

  for(int t=0;t<(int)(adj.size());t++){
    if(!visit[adj[t].first][adj[t].second] && myarr[adj[t].first][adj[t].second]==1)
      ret+=dfs(myarr , adj[t].first , adj[t].second , visit , n );
  }
  return ret;
}
