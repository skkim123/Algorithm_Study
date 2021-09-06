//1167

#include <iostream>
#include <vector>

#define MAX(a,b) ( (a>b)? a : b )


using namespace std;

int V,thisnode,neighbor,dist;
vector< pair<int,int> > vec[100001]; // pair(number , distance)
int visited1[100001]={0,}; // distance 
int visited2[100001]={0,}; // 

int maxdist=0;
int maxindex=1;


void Input();

void dfs(int visited[],int start,int prev,int realstart);


void searchmax ( int visited[]);

void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();



  return 0;
}

void Input(){
  cin >> V;
  for(int i=1;i<=V;i++){
    cin >> thisnode;
    while(1){
      cin >> neighbor;
      if(neighbor==-1){
        break;
      }
      cin >> dist;
      vec[thisnode].push_back(make_pair(neighbor,dist));
      vec[neighbor].push_back(make_pair(thisnode,dist));
    }
  }
}

void dfs(int visited[],int start,int prev,int realstart){
 visited[start] = prev;

 for(int i=0;i<(int)(vec[start].size());i++){
   if(!visited[ vec[start][i].first ] && vec[start][i].first != realstart){
     dfs(visited,vec[start][i].first,vec[start][i].second+prev,realstart);
   }
 }
}

void searchmax (int visited[]){

  for(int i=1;i<=V;i++){
    if(visited[i] > maxdist){
      maxdist = visited[i];
      maxindex = i;
    }
  }
}

void Solve(){
  dfs(visited1,1,0,1);
  searchmax(visited1);

  int nodeone = maxindex;

  maxdist = 0;

  dfs(visited2,nodeone,0,nodeone);
  searchmax(visited2);

  cout << maxdist;

}
