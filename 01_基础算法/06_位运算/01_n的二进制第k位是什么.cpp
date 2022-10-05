// 1. 先把这个数右移k位
// 2. 然后把这个数按位与1，就得到了这个数

#include<iostream>
using namespace std;

int main(){
  int n = 15;
  for(int k = 3; k >= 0; k--) cout << (n >> k & 1);
  return 0;
}