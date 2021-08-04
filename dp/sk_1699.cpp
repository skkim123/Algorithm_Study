//1699

#include <iostream>
#include <cmath>

#define MIN(a,b) ( (a<b) ? (a) : (b) )

using namespace std;


int main(){
    
    int num;
    cin >> num;
    
    int dp[100001]={0,};
    
    for(int i=1;i<=num;i++){
        
        if(sqrt(i) - (double)floor(sqrt(i)) == 0.0){
            dp[i]=1;
        }
        
        else{
            int min = 999999;
            int n = floor(sqrt(i));
            
            for(int j=n;j>=1;j--){
                min = MIN(dp[i - (j*j)],min);
            }
            
            dp[i] = min + 1;
        
        
        }
    }
    
    cout << dp[num];
    
    
    
    
    return 0;
}
