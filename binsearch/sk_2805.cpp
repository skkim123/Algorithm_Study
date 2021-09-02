//2805

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,temp;
vector<int> vec;

void Input();

long long mysum(int height);

int isitmax(int height);

int bin_search();

void Output();

int main(){
  Input();
  Output();
  return 0;
}

void Input(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> temp;
    vec.push_back(temp);
  }  
  sort(vec.begin(),vec.end());
}

long long mysum(int height){
  long long sum=0;
  for(int i=0;i<N;i++){
    if(vec[i]>height){
      sum+=(vec[i]-height);
    }
  }

  return sum;
}

int isitmax(int height){

  bool first = (mysum(height) >= M);
  bool second =  (mysum(height+1) < M);

  if(first && !second)    // too small
    return -1;
  else if(!first && second) // too big
    return 0;
  else if(first && second)  // muyaho
    return 1;
}

int bin_search(){
  int left  = 0;
  int right = vec.back();
  int mid;

  while(left<=right){
    mid = left + (right-left)/2;

    if(isitmax(mid)==1)
      return mid;
    else if(isitmax(mid)==0)
      right = mid -1;
    else if(isitmax(mid)==-1)
      left = mid +1;
  }

  return -1;
}

void Output(){
  int num = bin_search();
  if(num==-1)
    cout << "Something went wrong";
  else{
    cout << num;
  }
}
