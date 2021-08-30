//1707

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int bfs(int start, vector<int> myarr[], int visit[]);

int main(){
  int v,e,k,a,b;

  cin >> k;

  while(k--){
    cin >> v >> e;
    vector<int> arr[v+1]; // 0 , 1 to v
    int visited[20001]={0,};  // 0 : not visited , 1: blue , -1: red
   
   

    for(int i=1;i<=e;i++){
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }


    /////////// hoxy...?
    // for(int i=1;i<=v;i++){
    //   sort(arr[i].begin(),arr[i].end());
    // }
    ///////////

    int err=0;
    for(int i=1;i<=v;i++){
      if(!visited[i]){
        if(bfs(i,arr,visited)){
          err=1;
          break;
        }
      }
    }

    if(err == 1)
      cout << "NO" << endl;
    else{
      cout << "YES" << endl;
    }


  }



  return 0;
}

int bfs(int start, vector<int> myarr[], int visit[]){
  queue<int> q;
  int num;
  int color=1;
  q.push(start);
  visit[start]= color; // 

  while(!q.empty()){
    num = q.front();
    q.pop();

    color = (-1) * visit[num];

    for(int j=0;j< (int)(myarr[num].size()) ;j++){
      if(visit[myarr[num][j]]==((-1) * color)){ 
            return 1;
      }
      if(!visit[myarr[num][j]]){
        visit[myarr[num][j]] = color;
        q.push(myarr[num][j]);
      }
    }
  }
  return 0;
}


