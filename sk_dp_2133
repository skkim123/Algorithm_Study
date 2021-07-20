#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int numarray[100];

int number_of_cases(int num);

int main(){
    numarray[0] = 1;
    numarray[2] = 3;
    
    int input;
    cin >> input;
    
    cout << number_of_cases(input);
    
    
    
    return 0;
}

int number_of_cases(int num) {
    
    if(num%2 == 1)
        return 0;
    else {
        if(numarray[num] != 0){
            return numarray[num];
        }
        
        else {
            int result =0;
            
            for(int i = num-2 ; i>=0 ;i-=2) 
                result += (2*number_of_cases(i));
            
            result += number_of_cases(num-2);
            numarray[num] = result;
            return result;
        }
        
        
    }
    
}
