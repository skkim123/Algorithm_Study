//2331

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int a,p;
  cin >> a >> p;
  vector<int> vec;
  int ans;

  vec.push_back(a); // index 0 => a (1st)
  for(;;){
    string str =to_string(vec.back() );
    int sum=0;
    for(int i=0;i<(int)str.size();i++){
        
      sum+= pow((str[i]-'0'),p);
    }
    auto it = find(vec.begin(),vec.end(),sum);
    if(it!=vec.end()){
      ans =it-vec.begin();
      break;
    }
    vec.push_back(sum);
  }
  cout << ans;


  return 0;
}
