//10610

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N,index_of_zero;
int arr[100001]; // use index 1 ~ N
string str="";


void Input();
bool Zeroexist();
bool multiple_of_three();
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();

  return 0;
}


void Input(){
  cin >> str;
  N = (int)str.size();
  arr[0] = -1;
  for(int i =1 ;i<=N;i++){
    arr[i] = str[i-1]-'0';
  }
}

bool Zeroexist(){
  for(int i=1;i<=N;i++){
    if(arr[i]==0) {
      index_of_zero = i;
      return true;
    }
  }
  return false;
}

bool multiple_of_three(){
  int sum =0;
  for(int i=1;i<=N;i++) sum+=arr[i];
  return (sum%3==0);
}

void Solve(){
  if(!Zeroexist() || !multiple_of_three()) cout << -1;
  else{
    sort(arr,arr+(N+1));

    for(int i=N;i>=1;i--){
      cout << arr[i];
    }
  }
}





