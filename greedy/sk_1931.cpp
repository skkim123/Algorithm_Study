//1931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long N,START,END;
vector<pair<long long,long long>> vec; 

bool compare(pair<long long,long long> pair1 , pair<long long,long long> pair2);

void Input();
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();
  return 0;
}

bool compare(pair<long long,long long> pair1 , pair<long long,long long> pair2){
  if(pair1.first!=pair2.first) return (pair1.first<pair2.first);
  else{
    return pair1.second<pair2.second;
  }
}

void Input(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> START >> END;
    vec.push_back(make_pair(START,END));
  }
  sort(vec.begin(),vec.end(),compare);
}

void Solve(){
  int cnt =0 ; // last 증가 시 마다 +1
  long long last = -1;

  for(int i=0;i<N;i++){
    if (vec[i].second<last){
      last = vec[i].second;
    }
    else if(vec[i].first>=last){
      cnt++;
      last = vec[i].second;
    }
  }
  cout << cnt;
}