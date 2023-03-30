#include<iostream>
#include<cstring>
using namespace std;

bool check(char str[]){
  int cnt = 0; // 记录栈中数据个数
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == 'I') cnt++; // 如果该位是入栈，则栈中的数据+1
    else{ // 否则
      if(!cnt) return false; // 如果出栈的时候栈中数据为0，不合法，返回false
      cnt--; // 如果栈中有数据，数据个数-1
    }
  }
  if(cnt) return false; // 操作完之后栈中还有数据，返回false 
  return true; // 到这一步说明出栈过程中栈中都有数据，并且最终栈为空
}

int main(){
  char str[100];
  cin >> str;
  cout << check(str) << endl;

  return 0;
}