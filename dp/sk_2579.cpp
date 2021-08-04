//2579
#include <iostream>

using namespace std;

#define MAX(a,b) ((a>b) ? (a):(b))


int main(){
   
    int stairs;
    int scores[301] = {0,};
    int dp[301] = {0,};
    cin >> stairs;
    
    for(int i=1;i<=stairs;i++){
        cin >> scores[i];
    }
    
    if (stairs >= 1)
        dp[1] = scores[1];
        
    if(stairs >= 2)
        dp[2] = scores[1] + scores[2];
    
    if(stairs >= 3){
        dp[3] =  scores[3] + MAX(scores[1],scores[2]);
    }
    
    if(stairs >=4){
         // stairs>=4
        for(int j=4;j<=stairs;j++){
            dp[j]=MAX( dp[j-2]  , scores[j-1] + dp[j-3]   ) +scores[j];       
            
        }
    }
    
    
    cout << dp[stairs];
    
    
    
    
    return 0;
}
