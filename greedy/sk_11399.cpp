//11399
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,num;
vector<int> vec;

void Input();
void Solve();


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();

  return 0;
}

void Input(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(),vec.end());
}

void Solve(){
  int sum=0;
  for(int i=0;i<N;i++){
    sum += (vec[i] * (N-i));
  }
  cout << sum;
}