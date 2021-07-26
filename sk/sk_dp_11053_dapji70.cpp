// 11053
#include <iostream>

using namespace std;

int main(){
 
 int dp[1002],nums[1002];
 int size_of_seq;
 
 cin >> size_of_seq;
 
 for(int i=1;i<=size_of_seq;i++){
    cin >> nums[i]; 
 }
 
 for(int j=1;j<=size_of_seq;j++){
  int max_length = 0;
  
  
  for(int k=1;k<=j;k++){
     if(nums[k] < nums[j] && max_length < dp[k]){
         
        max_length = dp[k]; 
     }
  }
  max_length++;
  dp[j] = max_length;
 }
 
 int maxval=0;
 for(int p=1;p<=size_of_seq;p++){
    if(maxval < dp[p])
        maxval = dp[p];
     
 }
 
 cout << maxval;
 
 
 
 
 
  return 0;
}

// reference : namu wiki and several blog posts,,,, https://namu.wiki/w/%EC%B5%9C%EC%9E%A5%20%EC%A6%9D%EA%B0%80%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4
