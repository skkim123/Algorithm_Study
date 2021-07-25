#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int DP[1000001];


int min3(int a , int b, int c);
int min2(int a, int b);


int main(){
    int input;
    
    cin >> input;
    
    
    
    for(int i=2;i<=input;i++){
        if( (i%2 != 0) & (i%3 != 0)){
            DP[i] = DP[i-1]+1; // DP[1] =0
        }
        else if((i%2 == 0) & (i%3==0) ){
            DP[i] = min3(DP[i-1],DP[i/2],DP[i/3])+1;
        }
        else if( (i%2 == 0) & (i%3 != 0)      ){
            DP[i] = min2(DP[i-1],DP[i/2])+1;
        }
        else{
            DP[i] = min2(DP[i-1],DP[i/3])+1;
        }
    }
    
    cout << DP[input];
    
    
    
   
    
    return 0;
}

int min3(int a , int b, int c){
    int num =a;
    if(num>b)
        num = b;
    if(num>c)
        num = c;
        
    return num;
    
}

int min2(int a, int b){
    int num =a;
    if(num>b)
        num =b;
    return num;
}


 // reference : https://jaemin8852.tistory.com/170 kamsa hap nida
