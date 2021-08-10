//11052

#include <iostream>

using namespace std;

#define MAX(a,b) ( (a > b) ? (a) : (b) )

int main(){
    
    int n;
    int price[1001];
    long long dp[1001][1001] = {0, };
    
    cin >> n;
    
    for(int k=1;k<=n;k++){
        cin >> price[k];
    }
    

    
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){
            if(i<j){
                dp[i][j] = dp[i][i];
            }    
            else{
                dp[i][j] = MAX( dp[i][j-1] , price[j]+dp[i-j][j] );
            }
        }
    }
    
    cout << dp[n][n];
    
    
    
    
 return 0;   
}
