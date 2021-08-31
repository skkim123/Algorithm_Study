//1991

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;



int NUM;


void preorder(int root);
void inorder(int root);
void postorder(int root);

pair<int,int> arr[27]; // 0 , 1 to 26

int main(){  
  cin >> NUM;

  char temp;
  char left;
  char right;

  for(int i=1;i<=NUM;i++){
    cin >> temp >> left >> right;

    arr[((int)temp) - 64].first = (left =='.'? -1:((int)left)-64   );
    arr[((int)temp) - 64].second = (right =='.'? -1:((int)right)-64   );
  }
  
  preorder(1);
  printf("\n");
  inorder(1);
  printf("\n");
  postorder(1);
  printf("\n");

  


  return 0;
}

void preorder(int root){
  cout << (char)(root+64);
  if(arr[root].first != -1) preorder(arr[root].first);
  if(arr[root].second != -1) preorder(arr[root].second);
}

void inorder(int root){
  if(arr[root].first != -1) inorder(arr[root].first);
  cout << (char)(root+64);
  if(arr[root].second != -1) inorder(arr[root].second);

}

void postorder(int root){

  if(arr[root].first != -1) postorder(arr[root].first);
  if(arr[root].second != -1) postorder(arr[root].second);
  cout << (char)(root+64);

}
