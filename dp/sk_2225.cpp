//2225

#include <iostream>

using namespace std;

int main(){
    
    int n,k;
    long long sum;
    cin >> n >> k;
    
    long long dp[201][201];
    
    for(int i=1;i<=n;i++){
        dp[i][1] = 1;
    }
    
    for(int a=1;a<=k;a++){
        dp[0][a] = 1;
    }
    
    for(int j=2;j<=k;j++){
        for(int p=1;p<=n;p++){
            sum =0;
            for(int b=p;b>=0;b--){
                sum += dp[b][j-1];
                sum = sum%1000000000;
            }
            dp[p][j] = sum;
        }
    }
    
    cout << dp[n][k]%1000000000;
    
    return 0;
}
