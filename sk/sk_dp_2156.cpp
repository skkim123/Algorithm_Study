// 2156
#include <iostream>
#define MAX(a,b) ( (a>b) ? (a) : (b) )

using namespace std;

int main()
{
  int number_of_cases;
  int wine[2][10003]; //start at index 3
  int amount_of_wine[10003];
  
  cin >> number_of_cases;
  
  // 0 _w
  // 1 ww
  wine[0][1] = 0;
  wine[1][1] = 0;
  wine[0][2] = 0;
  wine[1][2] = 0;
  
  for(int k=3;k<=number_of_cases+2;k++){
      cin >> amount_of_wine[k];
  }
  
  for(int i=3;i<=number_of_cases+2;i++){
      wine[0][i] = MAX( MAX(wine[0][i-2],wine[1][i-2]), MAX(wine[0][i-3],wine[1][i-3]) ) + amount_of_wine[i];
      wine[1][i] = wine[0][i-1]+amount_of_wine[i];
  }
  
  cout << MAX( MAX(wine[0][number_of_cases+2],wine[1][number_of_cases+2]), MAX(wine[0][number_of_cases+1],wine[1][number_of_cases+1]) );
  
    
  return 0;
}
