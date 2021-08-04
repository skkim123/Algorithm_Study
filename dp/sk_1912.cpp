// 1912
#include <iostream>

using namespace std;

#define MIN -2100000000

int main(){
    int size_of_seq;
    int nums[100002],dp[100002];
    
    cin >> size_of_seq;
    
    for(int i=1;i<=size_of_seq;i++){
        cin >>nums[i]; 
    }
    nums[0] = MIN;
    
    for(int j=1;j<=size_of_seq;j++){
        // decide dp[j]
        if(dp[j-1]>=0)
            dp[j] = dp[j-1]+nums[j];
        else{
            dp[j] = nums[j];
        }
    }
    
    int max = nums[1];
    for(int k=1;k<=size_of_seq;k++){   // find max value
        if(max < dp[k])
            max = dp[k];
    }
    
    cout << max ;
 
  return 0;
}

