// 小 A
//  和小 B
//  在玩一个游戏。

// 首先，小 A
//  写了一个由 0
//  和 1
//  组成的序列 S
// ，长度为 N
// 。

// 然后，小 B
//  向小 A
//  提出了 M
//  个问题。

// 在每个问题中，小 B
//  指定两个数 l
//  和 r
// ，小 A
//  回答 S[l?r]
//  中有奇数个 1
//  还是偶数个 1
// 。

// 机智的小 B
//  发现小 A
//  有可能在撒谎。

// 例如，小 A
//  曾经回答过 S[1?3]
//  中有奇数个 1
// ，S[4?6]
//  中有偶数个 1
// ，现在又回答 S[1?6]
//  中有偶数个 1
// ，显然这是自相矛盾的。

// 请你帮助小 B
//  检查这 M
//  个答案，并指出在至少多少个回答之后可以确定小 A
//  一定在撒谎。

// 即求出一个最小的 k
// ，使得 01
//  序列 S
//  满足第 1?k
//  个回答，但不满足第 1?k+1
//  个回答。

// 输入格式
// 第一行包含一个整数 N
// ，表示 01
//  序列长度。

// 第二行包含一个整数 M
// ，表示问题数量。

// 接下来 M
//  行，每行包含一组问答：两个整数 l
//  和 r
// ，以及回答 even 或 odd，用以描述 S[l?r]
//  中有偶数个 1
//  还是奇数个 1
// 。

// 输出格式
// 输出一个整数 k
// ，表示 01
//  序列满足第 1?k
//  个回答，但不满足第 1?k+1
//  个回答，如果 01
//  序列满足所有回答，则输出问题总数量。

// 数据范围
// N≤109,M≤5000
// 输入样例：
// 10
// 5
// 1 2 even
// 3 4 odd
// 5 6 even
// 1 6 even
// 7 10 odd
// 输出样例：
// 3

// 带边权写法
/*
边权d[x]为0，表示x与fa[x]奇偶性相同，为1表示x与fa[x]奇偶性不同
路径压缩是，对x到树根路径上的所有边权做xor运算，即可得到x与树根的奇偶关系
对于每个问题，设在离散化后l-1和r的值分别为x和y，设t表示该问题的回答，0表示偶数个，1表示奇数个
先检查x和y是否在同一个集合中，经过get函数后，如果d[x] xor d[y] != t，该关系与回答矛盾，可以确定撒谎
如果不在一个集合中，如果将p连接到q的子节点上，则d[p] = d[x] xor d[y] xor t
*/
#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 20010;
int n, m;
int p[N], d[N];
unordered_map<int, int> S; // 用于离散化

int get(int x){
    if(S.count(x) == 0) S[x] = ++n;
    return S[x];
}

int find(int x){
    if(x != p[x]){
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    } 
    return p[x];
}

int main(){
    cin >> n >> m;
    n = 0;
    for(int i = 0; i < N; i++) p[i] = i; // 将父节点设置为自己
    
    int res = m; // res默认设置为m，当没有矛盾时结果就是回答的次数
    for(int i = 1; i <= m; i++){
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);
        
        int t = 0; // 如果是偶数，则答案就是0
        if(type == "odd") t = 1; // 如果是奇数，答案是1
        
        int pa = find(a), pb = find(b); // 获取祖宗节点
        if(pa == pb){ // 如果在一个连通块中
            if(d[a] ^ d[b] != t){ // 如果d[a] ^ d[b]不等于t，存在矛盾
                res = i - 1; // 得到结果，break
                break;
            }
        }else{ // 否则
            p[pa] = pb; // 设置pa的父节点为pb 
            d[pa] = d[a] ^ d[b] ^ t; // 获取d[pa]
        }
    }
    
    cout << res << endl;
    
    return 0;
}

// 扩展域写法
/*
将每个变量x拆成两个节点x(odd)和x(even)，其中x(odd)表示sum[x]是奇数，x(even)表示sum[x]是偶数，把这两个节点称为x的奇数域和偶数域
对每个问题，设在离散化后l-1和r的值分别是x和y，设t表示该问题的回答，0代表偶数个，1代表奇数个
1.若t=0，则合并x(odd)和y(odd)，x(even)和y(even)
2.若t=1，则合并x(odd)和y(even)，x(even)和x(odd)
在合并之前要检查是否存在矛盾。
若两个变量x和y对应的x(odd)和y(odd)在一个集合中，则二者奇偶性相同
若两个变量x和y对应的x(odd)和y(even)在一个集合中，则二者奇偶性不同
*/
#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 40010, Base = N / 2;
int n, m;
int p[N];
unordered_map<int, int> S;

int get(int x){
    if(S.count(x) == 0) S[x] = ++n;
    return S[x];
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    n = 0;
    for(int i = 0; i < N; i++) p[i] = i;
    
    int res = m;
    for(int i = 1; i <= m; i++){
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b); // 获取离散化后对应的值
        
        if(type == "even"){ // 如果l到r之间有偶数个1
            if(find(a + Base) == find(b)){ // 那么如果a的奇数域和b的偶数域在一个连通块中，就存在矛盾
                res = i - 1;
                break;
            }
            p[find(a)] = find(b); // 没有矛盾，则a的奇数域和b的奇数域合并
            p[find(a + Base)] = find(b + Base); //a的偶数域和b的偶数域合并
        }else{ // 如果l到r之间有奇数个1
            if(find(a) == find(b)){ // 那么如果a的奇数域和b的奇数域在一个连通块中，就存在矛盾
                res = i - 1;
                break;
            }
            p[find(a + Base)] = find(b); // 没有矛盾，则a的奇数域和b的偶数域合并
            p[find(a)] = find(b + Base); //a的偶数域和b的奇数域合并
        }
    }
    
    cout << res << endl;
    
    return 0;
}