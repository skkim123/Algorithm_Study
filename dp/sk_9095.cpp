//9095
#include <iostream>


using namespace std;



int main(){
   int number_of_case;
   cin >> number_of_case;
   
   for(int i=1;i<=number_of_case;i++){
       int num;
       cin >> num;
       
       int DP[12];
       DP[1] = 1;
       DP[2] = 2;
       DP[3] = 4;
       if(num<=3)
        cout << DP[num] << endl;
       else{
           for(int i=4;i<=num;i++){
               DP[i] = DP[i-1] + DP[i-2] + DP[i-3] ;
           }
           cout << DP[num] << endl;
       }
   }
    
    
 return 0;   
}
