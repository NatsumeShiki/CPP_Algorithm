// 给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

// 注意：

// 数据保证给定的表达式合法。
// 题目保证符号 - 只作为减号出现，不会作为负号出现，例如，-1+2,(2+2)*(-(1+1)+2) 之类表达式均不会出现。
// 题目保证表达式中所有数字均为正整数。
// 题目保证表达式在中间计算过程以及结果中，均不超过 231−1。
// 题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 5/3=1，对于小于 0 的结果向上取整，例如 5/(1−4)=−1。
// C++和Java中的整除默认是向零取整；Python中的整除//默认向下取整，因此Python的eval()函数中的整除也是向下取整，在本题中不能直接使用。
// 输入格式
// 共一行，为给定表达式。

// 输出格式
// 共一行，为表达式的结果。

// 数据范围
// 表达式的长度不超过 105。

// 输入样例：
// (2+2)*(1+1)
// 输出样例：
// 8

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

stack<int> num; // 存放数字的栈
stack<char> op; // 存放符号的栈

void eval(){
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if(c == '+') x = a + b;
    else if(c == '-') x = a - b;
    else if(c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main(){
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 定义符号的优先级
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        auto c = str[i];
        if(isdigit(c)){ // 如果c是数字字符
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j])) // 这个循环是如果这个数是多位的数，可以获得它
                x = x * 10 + str[j++] - '0';
            i =  j - 1; // j此时是在符号为，所以要让i走到j-1的位置，因为这一轮循环结束后i会自增变成那个符号的位置
            num.push(x); // 把这个数放到num的栈中
        }
        else if(c == '(') op.push(c); // 如果这个字符是左括号，直接放进op中
        else if(c == ')'){ // 如果这个符号是有括号，直到遇到左括号为止，都一直进行eval运算
            while(op.top() != '(') eval();
            op.pop(); // 最后把这个左括号删掉
        }else{
            while(op.size() && pr[op.top()] >= pr[c]) eval();
            // 如果这个字符是符号，就看是否栈顶符号的优先级大于这个字符，如果大于就立刻进行eval运算，否则就存进op
            op.push(c);
        }
    }
    while(op.size()) eval(); // 直到op栈为空，一直进行eval运算
    cout << num.top() << endl; // 最后输出数字栈的顶，就是答案
    return 0;
}