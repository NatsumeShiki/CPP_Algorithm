#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string str;
  cin >> str;
  for(int i = 0; i < strlen(str); i++){
  	if(str[i] == '0') cout << '1';
    else cout << '0';
  }
	
	return 0;
}