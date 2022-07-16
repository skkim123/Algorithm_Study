//1654


// hehe
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K,N,temp,sum=0;
vector<int> vec;

void input();
int num( int amount );
int findit( int amount);
int bin_search ();
void solve();




int main(){
  input();
  solve();
  


  return 0;
}




void input(){
  cin >> K >> N;

  for(int i=1;i<=K;i++){
    cin >> temp;
    sum +=temp;
    vec.push_back(temp);
  }

  sort(vec.begin(),vec.end());
}


int num( int amount ){
  int summ =0 ;
  for(int i=0;i<K;i++){
    summ+=(vec[i]/amount);
  }
  return summ;
}

int findit(int amount){
  if(   num(amount)>=N && num(amount+1)>=N    ) // amount too small
    return -1;
  else if( num(amount) < N && num(amount+1) < N   )  // amount too big
    return 0;
  else if( num(amount) >= N && num(amount+1) < N   )  // muyaho
    return 1;
}



int bin_search (){
  int left = 1;
  int right = vec.back();
  int mid;

  while(left<=right){
    mid = left + (right - left)/2;

    if(findit(mid)==1){
      return mid;
    }
    else if(findit(mid)==0){
      right = mid-1;
    }
    else if(findit(mid)==-1){
      left = mid + 1 ;
    }
  }
  return -1;
}


void solve(){
  int result = bin_search();
  if (result==-1)
    cout << "Something went wrong";
  else{
    cout << result;
  }
}
 
