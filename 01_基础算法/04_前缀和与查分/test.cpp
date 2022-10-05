#include<iostream>
using namespace std;

int main(){
  int arr[] = {90, 75, 95, 87, 93, 92, 89, 87, 95, 90, 90, 79, 84, 90, 72, 90, 86, 62, 82, 85, 80, 88};
  float b[] = {4.5, 1, 4.5, 2, 2.5, 3, 1, 2, 1, 1.5, 0.5, 1, 1, 2, 6, 1.5, 2, 2, 1.5, 2, 2.5, 3};

  float a = 0;
  float c = 0;
  for(int i = 0; i < 22; i++){
    a += arr[i] * b[i];
    c += b[i];
  }
  cout << a << endl;
  cout << b << endl;

  return 0;
}