// 11054
#include <iostream>

using namespace std;

int main(){
 
 int dp1[1002],dp2[1002],nums[1002];
 int size_of_seq;
 
 cin >> size_of_seq;
 
 for(int i=1;i<=size_of_seq;i++){
    cin >> nums[i]; 
 }
 
 for(int j=1;j<=size_of_seq;j++){
  int max_length1 = 0;
  
  
  for(int k=1;k<=j;k++){
     if(nums[k] < nums[j] && max_length1 < dp1[k]){
         
        max_length1 = dp1[k]; 
     }
  }
  max_length1++;
  dp1[j] = max_length1;
 }
 
 
 
 for(int j=size_of_seq;j>=1;j--){
  int max_length2 = 0;
  
  
  for(int k=size_of_seq;k>=j;k--){
     if(nums[k] < nums[j] && max_length2 < dp2[k]){
         
        max_length2 = dp2[k]; 
     }
  }
  max_length2++;
  dp2[j] = max_length2;
 }
 
 
 
 
 
 
 
 
 /////
 
 int maxval=0;
 for(int p=1;p<=size_of_seq;p++){
    if(maxval < dp1[p]+dp2[p]-1)
        maxval = dp1[p]+dp2[p]-1;
     
 }
 
 cout << maxval;
 
 
 
 
 
  return 0;
}

