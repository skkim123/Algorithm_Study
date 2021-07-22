//11726
#include <iostream>


using namespace std;

int DP[1001];

int main(){
    int num;
    cin >> num;
    
    DP[1]=1;
    DP[2]=2;
    
    if(num<=2){
        cout << DP[num];
    }
    else{
        for(int i=3;i<=num;++i){
            DP[i] = (DP[i-1]+DP[i-2])%10007;
        }
        cout << DP[num];
    }
    
    
    
 return 0;   
}
