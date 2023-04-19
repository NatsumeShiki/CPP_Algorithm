#include<iostream>
#include<fstream>
using namespace std;

int main(){
  FILE *fo1, *fo2;
  fo1 = fopen("output.txt", "r");
  fo2 = fopen("output1.txt", "r");
  
  int a, b;
  while(true){
    a = fgetc(fo1);
    b = fgetc(fo2);
    // cout << a << " " << b << endl;
    if(a == EOF || b == EOF) break;
    if(a != b){
      cout << a << " " << b << endl; 
    }
  }
  fclose(fo1);
  fclose(fo2);

  return 0;
}