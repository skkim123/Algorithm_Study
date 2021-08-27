//9466

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int start,int myarr[],bool visit[],int* cyclevertexptr);

int main(){

  int TESTCASE;
  cin >> TESTCASE;

  while(TESTCASE--){
    int N;
    int cyclevertex=0;

    cin >> N;

    bool visited[100001]; // 0 , 1~ 100000
    int arr[100001]={0,}; // 
    memset(visited,false,sizeof(visited));

    for(int i=1;i<=N;i++){
      cin >> arr[i];
    }
    for(int i=1;i<=N;i++){
      if(!visited[i]){
        dfs(i,arr,visited,&cyclevertex);
      }
    }
    cout << N - cyclevertex << endl;
  }

  return 0;
}

void dfs(int start,int myarr[],bool visit[],int* cyclevertexptr) {
  vector<int>tempvisit;

  int now = start;

  while(!visit[myarr[now]]){
    visit[now]=true;
    tempvisit.push_back(now);
    now= myarr[now];
  }
  visit[now] = true; // 1개일때 체크!
  tempvisit.push_back(now);

  auto iter1 = find(tempvisit.begin(),tempvisit.end(),now);
  auto iter2 = find(tempvisit.begin(),tempvisit.end(),myarr[now]);
  if(iter2 != tempvisit.end() ){
    int num = iter1 - iter2 + 1;
     *cyclevertexptr += num;
  }
  else{ //no cycle
    return;
  }

}
  
