//1744

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,num;
int minuscnt=0;
int zerocnt=0;
vector<int> vec;

void Input();
void Solve();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();

  return 0;
}

void Input(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    if(num<0) minuscnt+=1;
    vec.push_back(num);
  }
  sort(vec.begin(),vec.end(),greater<int>() );
}

void Solve(){
  int X,Y,sum=0; //X>=Y

  if(minuscnt%2==0){
    while( vec.size()>0 && vec.back()<0){
      X = vec.back();
      vec.pop_back();
      Y = vec.back();
      vec.pop_back();
      sum+=(X*Y);
    }
    while(vec.size()>0 && vec.back()==0){
      vec.pop_back();
    }
    while(vec.size()>=2){
      X = vec.front();
      vec.erase(vec.begin());
      Y = vec.front();
      vec.erase(vec.begin());
      if(X==1 || Y==1) sum+=(X+Y);
      else{sum+=(X*Y);}
    }
    while(vec.size()>0){
      sum += vec.front();
      vec.erase(vec.begin());
    }
    cout << sum;
  }


  else if(minuscnt%2==1){ 
    for(int i=1; i<=(minuscnt-1)/2;i++){
      X = vec.back();
      vec.pop_back();
      Y = vec.back();
      vec.pop_back();
      sum+=(X*Y);
    }
    X = vec.back();
    vec.pop_back();

    if(vec.size()!=0){
      Y = vec.back();
      if(Y==0){
        while(vec.back()==0){
          vec.pop_back();
        } 
        while(vec.size()>=2){
          X = vec.front();
          vec.erase(vec.begin());
          Y = vec.front();
          vec.erase(vec.begin());
          if(X==1 || Y==1) sum+=(X+Y);
          else{sum+=(X*Y);}
        }
        while(vec.size()>0){
          sum += vec.front();
          vec.erase(vec.begin());
        }

      }
      else if(Y>=1){
        sum+=X;
        while(vec.size()>=2){
          X = vec.front();
          vec.erase(vec.begin());
          Y = vec.front();
          vec.erase(vec.begin());
          if(X==1 || Y==1) sum+=(X+Y);
          else{sum+=(X*Y);}
        }
        while(vec.size()>0){
          sum += vec.front();
          vec.erase(vec.begin());
        }
      }
    }

    else if(vec.size()==0) {
      sum+=X;
    }
    cout << sum;
  }
  
}