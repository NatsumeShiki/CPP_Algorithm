#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    string str = "1";
    while(--n){
        int cnt = 0;
        string s = str;
        str = "";
        for(int i = 0; i < s.size(); i++){
            if(!cnt){
                cnt++;
            }else if(s[i] == s[i - 1]){
                cnt++;
            }else{
                str += cnt;
                str += s[i - 1];
                cnt = 0;
            }
        }
        str += cnt;
        str += s[s.size() - 1];
    }
    cout << str << endl;
    return 0;
}