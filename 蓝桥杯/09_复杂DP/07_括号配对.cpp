// Hecy 又接了个新任务：BE 处理。

// BE 中有一类被称为 GBE。

// 以下是 GBE 的定义：

// 空表达式是 GBE
// 如果表达式 A 是 GBE，则 [A] 与 (A) 都是 GBE
// 如果 A 与 B 都是 GBE，那么 AB 是 GBE
// 下面给出一个 BE，求至少添加多少字符能使这个 BE 成为 GBE。

// 注意：BE 是一个仅由(、)、[、]四种字符中的若干种构成的字符串。

// 输入格式
// 输入仅一行，为字符串 BE。

// 输出格式
// 输出仅一个整数，表示增加的最少字符数。

// 数据范围
// 对于所有输入字符串，其长度小于100。

// 输入样例：
// [])
// 输出样例：
// 1

/*
动态规划
  状态表示f[i][j]
    集合：所有将[i,j]变成合法括号序列的方案的集合
    属性：最小值
  状态计算：分成两大类，根据题目给出的2、3条件分类，即第一种是形如 (A) [A]这样子包在一个括号里面的，第二种是形如 AB 这样的
    第一类：1.如果str[i]和str[j]可以匹配，就是f[i + 1][j - 1]
           2. 如果必须有i，但是没有j，无法表示出来，但是它是包含在方案f[i][j-1]里面的，题目求得是最小值，所以可以重复
           3. 如果必须有j，但是没有i，跟上面一样，用f[i + 1][j]表示
           4. 如果str[i]和str[j]无法匹配，就是 f[i + 1][j - 1] + 2，它是包含在3里面的，所以可以忽略
    第二类：str[i] ~ str[j] 包含多对括号是 ()[]... 这样的形式，将它分成两半， i ... k | k+1 ... j，那么就枚举k求f[i][k]和f[k+1][j]的较小值

*/
#include<iostream>
using namespace std;

const int N = 110, INF = 1e8;
int n;
int f[N][N];

bool is_match(char l, char r){ // 两个字符是否匹配
    if(l == '(' && r == ')') return true;
    if(l == '[' && r == ']') return true;
    return false;
}

int main(){
    string s;
    cin >> s;
    n = s.size();
    
    for(int len = 1; len <= n; len++) // 枚举长度
        for(int i = 0; i + len - 1 < n; i++){ // 枚举左端点
            int j = i + len - 1; // 计算右端点
            f[i][j] = INF; // 要取最小值，所以先设置为最大值
            if(is_match(s[i], s[j])) f[i][j] = f[i + 1][j - 1]; // 先看左右两边是否匹配，第一类1
            f[i][j] = min(f[i][j], min(f[i][j - 1], f[i + 1][j]) + 1); // 第二类 2 3
            
            for(int k = i; k < j; k++) // 第二类
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
        
    cout << f[0][n - 1] << endl; // 将[0][n-1]变成合法序列需要最小的次数
    
    return 0;
}