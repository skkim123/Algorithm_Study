// 11055
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
  int max = 0;
  
  
  for(int k=1;k<=j;k++){
     if(nums[k] < nums[j] && max < dp[k]){
         
        max = dp[k]; 
     }
  }
  dp[j] = max+nums[j];
 }
 
 int maxval=0;
 for(int p=1;p<=size_of_seq;p++){
    if(maxval < dp[p])
        maxval = dp[p];
     
 }
 
 cout << maxval;
 
 
 
 
 
  return 0;
}
