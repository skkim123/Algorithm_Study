//9461

#include <iostream>

using namespace std;


int main(){
    int num_of_testcase;
    int n;
    long long dp[101];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    
    cin >> num_of_testcase;
    
    for(int i=1;i<=num_of_testcase;i++){
        cin >> n;
        
        if(n<=5){
            cout << dp[n] << endl;
        }
        else{
            for(int j=6;j<=n;j++){
                dp[j] = dp[j-1]+dp[j-5];
            }
            
            cout << dp[n] << endl;
            
        }
        
        
    }
    
 return 0;   
}
