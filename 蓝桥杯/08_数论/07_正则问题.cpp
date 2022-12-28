// 考虑一种简单的正则表达式：

// 只由 x ( ) | 组成的正则表达式。

// 小明想求出这个正则表达式能接受的最长字符串的长度。

// 例如 ((xx|xxx)x|(x|xx))xx 能接受的最长字符串是： xxxxxx，长度是6。

// 输入格式
// 一个由x()|组成的正则表达式。

// 输出格式
// 输出所给正则表达式能接受的最长字符串的长度。

// 数据范围
// 输入长度不超过100，保证合法。

// 输入样例：
// ((xx|xxx)x|(x|xx))xx 
// 输出样例：
// 6

/*
((xx|xxx)x|(x|xx))xx 
                         &
               |                 xx
        &             |
   |        x     x       xx
xx   xxx
想成一颗二叉树，就算直到要这么做但是完全写不出来y总这样的代码
*/
#include<iostream>
using namespace std;

int k;
string str;

int dfs(){
    int res = 0;
    while(k < str.size()){
        if(str[k] == '('){ // 处理 (......)
            k++; // 跳过 '('
            res += dfs();
            k++; // 跳过 ')'
        }else if(str[k] == '|'){
            k++; // 跳过 '|'
            res = max(res, dfs());
        }else if(str[k] == ')'){
            break;
        }else{
            k++; // 跳过 'x'
            res++;
        }
    }
    return res;
}

int main(){
    cin >> str;
    cout << dfs() << endl;
    
    return 0;
}