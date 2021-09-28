//1517
// merge sort 로 해결한다는 아이디어 답지보고 앎.
//https://blog.naver.com/ndb796/221227934987 merge sort 코드도 거의 그대로 씀.
#include <iostream>

using namespace std;
int N;
int arr[500001]; // start at index 0
int sorted[500001];
long long swapcnt=0;

void Input();
void Merge(int left,int mid,int right);
void Mergesort(int left,int right);
void Solve();
// void printtest();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Input();
  Solve();
  // printtest();

  return 0;
}

void Input(){
  cin >> N;
  for(int i=0;i<N;i++) cin >> arr[i];
}

void Mergesort(int left,int right){
  if(left < right){
    int mid = (left + right)/2;
    Mergesort(left,mid);
    Mergesort(mid+1,right);
    Merge(left,mid,right);
  }
}

void Merge(int left,int mid,int right){
  int i = left; // pointing to front index in first mergesort result
  int j = mid+1; // pointing to front index in second mergesort result
  int k = left;  // 대충 왼쪽부터 k-1까지 sorted[]에 정렬되었다는 뜻.

  while(i<=mid && j<=right){ // don't cross the line!!!
    if(arr[i]<=arr[j]){ // i 우승!
      sorted[k] = arr[i];
      i++;
    }
    else{
      swapcnt+=(long long)(mid-i+1);
      sorted[k] = arr[j]; // j 우승! -> 이 때 swapcnt 증가합니다.
      j++;
    }
    k++; // sorted[]에 멤버 하나 더 추가요
  } // 둘 중 하나가 먼저 끝남
  // 나머지 애들 sorted에 집어넣기
  if(i>mid){ // 첫 번째 mergesort result 먼저 끝나버림
    for(int t =j;t<=right;t++){
      sorted[k] = arr[t];
      k++;
    }
  }
  else{ // 두 번 째
    for(int t=left;t<=mid;t++){
      sorted[k] = arr[t];
      k++;
    }
  }
  //insert
  for(int t =left ;t<=right;t++){
    arr[t] = sorted[t];
  }
}

void Solve(){
  Mergesort(0,N-1);
  cout << swapcnt;
}

// void printtest(){
//   for(int i=0;i<N;i++) cout << arr[i] << '\n';
// }