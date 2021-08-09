//2011

#include <iostream>
#include <string>

using namespace std;


int main () {
    
    string a;
    int pwd[5001];
    long long dp[5001];
    int err = 0;
    
    pwd[0] = 100000;
    
    cin >> a;
    
    for (int i = 1; i <= (int)a.size(); i++) {
	     pwd[i] = a[i-1] - '0'; //pwd : 1 to a.size()
	}
    
    for(int j=1;j<=(int)a.size();j++){
        if(j==1){
            if(pwd[1]== 0){
                err =1;
                break;
            }
            else{
                dp[1]=1;
            }
        }
            
        else{
            if(pwd[j]==0 && (pwd[j-1]==0 || (pwd[j-1]>=3 && pwd[j-1]<=9) )   ){
                err =1;
                break;
            }
            else if(pwd[j-1]==0 && pwd[j]>=1 && pwd[j]<=9 ){
                if(j==3){
                    dp[3]=1;
                }
                else{
                    dp[j] = dp[j-3];
                }
            }
            else if(pwd[j]==0 && (pwd[j-1] == 1 || pwd[j-1] == 2) ){
                if(j==2)
                    dp[2]=1;
                else{
                    dp[j] = dp[j-2];
                }
            }
            else if(    (pwd[j-1] ==1 && pwd[j]>=1 && pwd[j]<=9) ||  (pwd[j-1] ==2 && pwd[j]>=1 && pwd[j]<=6)    ){
                
                if(j==2){
                    dp[2]=2;
                }
                else{
                 dp[j] = (dp[j-1] + dp[j-2])%1000000;
                }
            }
            else if(pwd[j-1] ==2 && pwd[j]>=7 && pwd[j]<=9 ){
                if(j==2)
                    dp[2]=1;
                else{
                    dp[j]= dp[j-2];
                }
                
            }
            else if(pwd[j-1]>=3 && pwd[j-1]<=9 && pwd[j] >=1 && pwd[j]<=9){
                if(j==2){
                    dp[2]=1;
                }
                else{
                    dp[j]= dp[j-1];
                }
            }
        }
        
    }
    
    if(err==1){
        cout << 0;
    }
    else{
        cout << dp[(int)a.size()]%1000000;
    }
    
    
    
 return 0;   
}
