//11727
#include <iostream>


using namespace std;

int DP[1001];

int main(){
    int num;
    cin >> num;
    
    DP[1]=1;
    DP[2]=3;
    
    for(int i=3;i<=num;i++){
        DP[i] = (DP[i-1]+2*DP[i-2])%10007;
    }
    cout << DP[num];
    
    
    
 return 0;   
}

// hihi
