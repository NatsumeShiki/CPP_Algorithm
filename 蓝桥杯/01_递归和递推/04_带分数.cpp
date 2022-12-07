// 100 可以表示为带分数的形式：100=3+69258714
// 还可以表示为：100=82+3546197
// 注意特征：带分数中，数字 1∼9 分别出现且只出现一次（不包含 0）。

// 类似这样的带分数，100 有 11 种表示法。

// 输入格式
// 一个正整数。

// 输出格式
// 输出输入数字用数码 1∼9 不重复不遗漏地组成带分数表示的全部种数。

// 数据范围
// 1≤N<106
// 输入样例1：
// 100
// 输出样例1：
// 11
// 输入样例2：
// 105
// 输出样例2：
// 6

// 方法一：自己写出来的方法
// 就是把1-9全排列，然后把这所有的方案都各自分成三段，为a, b, c，然后计算k是否等于 a + b / c ，如果成立，就将成功的方案加1
#include<iostream>
using namespace std;

const int N = 10;
int num[N]; // 保存全排列的一种方案
bool st[N]; // 保存某个数是否已经使用过
int n = 9, cnt = 0, k; // k就是从控制台读取的数，cnt表示所有成立的方案数

int get(int l, int r){
    int x = 0;
    for(int i = l; i <= r; i++) x = x * 10 + num[i];
    return x;
}

void dfs(int u){
    if(u > n){ // 如果u>n，就表示这是一种全排列的方式
        for(int i = 1; i <= n - 2; i++){ // 下面这个两重循环相当于两个挡板，把它分成三段，分别表示a, b, c
            for(int j = i + 1; j <= n - 1; j++){
                // 通过get函数把它们变成三个整型
                int a = get(1, i);
                int b = get(i + 1, j);
                int c = get(j + 1, n);
                // 判断是否符合题目的要求，如果符合就让cnt自增，表示这是一种可行的方案
                if(b % c == 0 && a + b / c == k) cnt++;
            }
        }
    }
    
    // 下面这个就是枚举每个数来获取一种全排列
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            st[i] = true;
            num[u] = i;
            dfs(u + 1);
            
            st[i] = false;
        }
    }
}

int main(){
    cin >> k;
    dfs(1);
    cout << cnt << endl;
    return 0;
}

// 方法二
// 思路：枚举a，然后在这个a的基础上再枚举c，n = a + b / c，可以得到 b = n * c - a * c，然后在a和c的基础上获得b，然后判断是否满足所有的条件，如果所有
// 的条件都成立，就让这个ans自增，表示这是一种可行的方案   上面说的要满足的条件：1-9所有的数都只用了且只用一遍
#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;
int n;
bool st[N], backup[N];
int ans;

bool check(int a, int c){
    int b = n * c - a * c; // 获取b
    
    if(!a || !b || !c) return false; // 如果a或b或c是等于0的，直接返回
    
    memcpy(backup, st, sizeof st); // 先把st备份一份，引入如果这个方案是不成立的，必须得保证st是不变的
    while(b){ // 这个循环是把b的所有位枚举，查看是否在a或c中已经使用过了
        int x = b % 10; // 获取最后面一位
        b /= 10; // 然后把最后一位删掉
        if(!x || backup[x]) return false; // 如果这个x等于0或者x已经在a或c中使用过了，就返回
        backup[x] = true; // 如果没使用过，就把它设置成使用了
    }
    // 随后，下面这个循环是判断是否所有的数都使用过了，如果有没使用的，就返回说明不满足条件
    for(int i = 1; i <= 9; i++)
        if(!backup[i])
            return false;
    // 如果走到这一步，表示这是一种可行的方案，返回true
    return true;
}

// 这个是确定了a，然后枚举c
void dfs_c(int a, int c){
    if(check(a, c)) ans++; // 把当前的a和c带入，查看是否满足条件，如果满足就让ans自增
    // 从1-9选择数，加到c的后面，同样c乘以10之后再加上
    for(int i = 1; i <= 9; i++)
        if(!st[i]){
            st[i] = true;
            dfs_c(a, c * 10 + i); // 然后在这个c的基础上进入下次递归
            st[i] = false;
        }
}

void dfs_a(int a){
    if(a >= n) return; // 如果a是大于n的，肯定是不成立的，所以return
    if(a) dfs_c(a, 0); // 如果a不为0，那么就在a的基础上枚举c
    
    // 下面是枚举a
    for(int i = 1; i <= 9; i++)
        if(!st[i]){ // 从1-9中选择，查看是否用了某个数，如果没用就把它加到a的后面，需要先让a乘以10再加上
            st[i] = true; // 选择了就把他设置为true
            dfs_a(a * 10 + i); // 然后在这个a的基础上进入下一次递归，来获取下一个a
            st[i] = false; // 恢复原状
        }
}

int main(){
    cin >> n;
    dfs_a(0); // 一开始让a等于0
    
    cout << ans << endl;
    return 0;
}