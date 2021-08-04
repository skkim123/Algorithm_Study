//2193
#include <iostream>


using namespace std;



int main(){
    
   int input;
   cin >> input;
   
   long long arr[2][91];
   
   arr[0][1] =0;
   arr[1][1] =1;
   
   for(int i=2;i<=input;i++){
      arr[0][i] = arr[0][i-1] + arr[1][i-1];
      arr[1][i] = arr[0][i-1];
   }
   
   long long output = arr[0][input] + arr[1][input];
    cout << output;
 return 0;   
}

// USE long long !! 
