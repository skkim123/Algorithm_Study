//10844
#include <iostream>


using namespace std;



int main(){
    
    int input;
    int output = 0 ;
    cin >> input;
    
    int arr[11][101];//0~9,1~100 
    
    for(int i=0;i<=9;i++){
        arr[i][0]=0;
        arr[i][1]=1;
    }
    arr[0][1] = 0;
    
    for(int j=2;j<=input;j++){
        
        arr[0][j] = arr[1][j-1]% 1000000000;
        for(int k=1;k<=8;k++){
            arr[k][j] = (arr[k-1][j-1]% 1000000000 + arr[k+1][j-1]% 1000000000)% 1000000000;
        }
        
        arr[9][j] = arr[8][j-1]% 1000000000;
    }
    
    
    for(int a=0;a<=9;a++){
        output+=arr[a][input];
        output = output % 1000000000;
    }
    cout <<(output % 1000000000);

 return 0;   
}
