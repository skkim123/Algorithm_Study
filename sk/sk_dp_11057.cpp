//11057
#include <iostream>


using namespace std;



int main(){
    
   int input;
   cin >> input;
   int arr[11][1001];
   
   for(int i=0;i<=9;i++)
       arr[i][1] = 1;
       
    for(int j=2;j<=input;j++){
        for(int k=0;k<=9;k++){
            int sum=0;
            for(int z=0;z<=k;z++)
                sum += arr[z][j-1];
            arr[k][j] = sum%10007;
        }
    }
    
    int output=0;
    for(int y=0;y<=9;y++){
        output += arr[y][input];
        output = output%10007;
    }
    cout << output%10007;
   

 return 0;   
}
