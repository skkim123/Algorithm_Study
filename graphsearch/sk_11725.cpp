//11725
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;



int N,n1,n2;
vector<int> vec[100001]; // 0 , 1~100000
int parent[100001]={0,};
bool visited[100001];

void Input();

void dfs(int num,int parent);

void Setting();
void Output();

int main(){

  Input();
  Setting();
  Output();



  return 0;
}

void Input(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(visited,false,sizeof(visited));
  cin >> N;
  for(int i=1;i<=100000;i++){
    vec[i].push_back(-1);
  }
  for(int i=1;i<=(N-1);i++){
    cin >> n1;
    cin >> n2;

    vec[n1].push_back(n2);
    vec[n2].push_back(n1);
  }
}

void dfs(int num,int myparent){
  visited[num] = true;
  parent[num] = myparent;

  for(int i=1;i<(int)(vec[num].size());i++){
    if(!visited[  vec[num][i]   ]){
      dfs(vec[num][i], num);
    }
  }
}

void Setting(){
  dfs(1,-1);
}

void Output(){
  for(int i=2;i<=N;i++){
    cout << parent[i] << '\n';
  }
}



