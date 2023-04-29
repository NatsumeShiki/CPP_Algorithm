#include<bits/stdc++.h>
using namespace std;
typedef map<string,int> ys;
int n;
string s;
void work(ys &sav,int l,int r,int mul=1){
    if(l>r) return ;
    int tl=l;
    if(s[l]=='('){
        for(int tot=1;tot;){
            l++;
            if(s[l]=='(') tot++;
            if(s[l]==')') tot--;
        }
        if(l==r) work(sav,tl+1,r-1,mul);
        else{
            int num=0,nr=l;
            for(l++;isdigit(s[l]);l++) num=num*10+s[l]-'0';
            work(sav,tl+1,nr-1,mul*(num?num:1));
            work(sav,l,r,mul);
        }
    }
    else{
        string str; str+=s[l];
        for(l++;islower(s[l]);l++) str+=s[l];
        if(l>r){sav[str]+=mul;return ;}
        int num=0,nr=l;
        for(;isdigit(s[l]);l++) num=num*10+s[l]-'0';
        work(sav,tl,nr-1,mul*(num?num:1));
        work(sav,l,r,mul);
    }
}
void clac(string str,ys& m){
    stringstream ss(str);string item;
    while(getline(ss,item,'+')){
        int l=0,num=0,len=item.size();
        for(;isdigit(item[l]);l++) num=num*10+item[l]-'0';
        s=item.substr(l,len-l);
        work(m,0,len-l-1,num?num:1);
    }
}
bool judge(ys &left,ys &right){
    if(left.size()!=right.size()) return 0;
    for(auto i=left.begin(),j=right.begin();i!=left.end();i++,j++){
        if(i->first!=j->first||i->second!=j->second) return 0;
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string str,lstr,rstr;ys left,right;
        cin>>str;
        stringstream ss(str);
        getline(ss,lstr,'=');
        getline(ss,rstr);
        clac(lstr,left);
        clac(rstr,right);
        puts(judge(left,right)?"Y":"N");
    } 
    return 0;
}

/*
equation(){
  expr();
  if(scan == '=') expr();
}

expr(){
  coef();
  formula();
  if(scan == '+'){
    coef();
    formula();
  }
}

coef(){
  digits();
  if(scan == '')
}

digits(){
  digit();
}

digit(){
  判断是否为0~9数字
}

formula(){
  term();
  coef();
}

term(){
  element();
  if(scan == '('){
    forluma();
    if(scan == ')') error;
  }
}

element(){
  if(uppercase)
  if(lowercase)
}

*/