//9465
#include <iostream>


using namespace std;

#define MAX(a,b) ( (a>b) ? (a) : (b) )



int main(){
    int number_of_case;
    cin >> number_of_case;
    
    int n;
    int arr[2][100003]; // 0 0 .....
                        // 0 0 .....
                        
    arr[0][1]=0;
    arr[0][2]=0;
    arr[1][1]=0;
    arr[1][2]=0;
    
    
    for(int i=1;i<=number_of_case;i++){
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> arr[0][j+2];
        }
        for(int k=1;k<=n;k++){
            cin >> arr[1][k+2];
        }
        
        for(int p=1;p<=n;p++){
            arr[0][p+2] =MAX(arr[1][p+1],arr[1][p])+arr[0][p+2];
            arr[1][p+2] =MAX(arr[0][p+1],arr[0][p])+arr[1][p+2];
        }
        
         cout << MAX(arr[0][n+2],arr[1][n+2]) <<endl;
        
    }
    
   
    
   
 return 0;   
}

// reference : https://chanhuiseok.github.io/posts/baek-9/
