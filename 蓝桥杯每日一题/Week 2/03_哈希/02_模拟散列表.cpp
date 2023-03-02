// 维护一个集合，支持如下几种操作：

// I x，插入一个数 x
// ；
// Q x，询问数 x
//  是否在集合中出现过；
// 现在要进行 N
//  次操作，对于每个询问操作输出对应的结果。

// 输入格式
// 第一行包含整数 N
// ，表示操作数量。

// 接下来 N
//  行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，输出一个询问结果，如果 x
//  在集合中出现过，则输出 Yes，否则输出 No。

// 每个结果占一行。

// 数据范围
// 1≤N≤105

// −109≤x≤109
// 输入样例：
// 5
// I 1
// I 2
// I 3
// Q 2
// Q 5
// 输出样例：
// Yes
// No

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100003;
int n;
int h[N], e[N], ne[N], idx;

void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
        if(e[i] == x) return true;
        
    return false;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    while(n--){
        char op;
        int x;
        cin >> op >> x;
        if(op == 'I') insert(x);
        else {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2000003, INF = 0x3f3f3f3f;
int n;
int h[N];

int find(int x){
    int k = (x % N + N) % N;
    while(h[k] != INF && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int main(){
    cin >> n;
    memset(h, 0x3f, sizeof h);
    while(n--){
        char op;
        int x;
        cin >> op >> x;
        int k = find(x);
        if(op == 'I') h[k] = x;
        else {
            if(h[k] == x) puts("Yes");
            else puts("No");
        }
    }
    
    
    return 0;
}