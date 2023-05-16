// 有 N
//  个盘子，每个盘子上写着一个仅由小写字母组成的英文单词。

// 你需要给这些盘子安排一个合适的顺序，使得相邻两个盘子中，前一个盘子上单词的末字母等于后一个盘子上单词的首字母。

// 请你编写一个程序，判断是否能达到这一要求。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含整数 N
// ，表示盘子数量。

// 接下来 N
//  行，每行包含一个小写字母字符串，表示一个盘子上的单词。

// 一个单词可能出现多次。

// 输出格式
// 如果存在合法解，则输出”Ordering is possible.”，否则输出”The door cannot be opened.”。

// 数据范围
// 1≤N≤105
// ,
// 单词长度均不超过1000

// 输入样例：
// 3
// 2
// acm
// ibm
// 3
// acm
// malform
// mouse
// 2
// ok
// ok
// 输出样例：
// The door cannot be opened.
// Ordering is possible.
// The door cannot be opened.

// 在每个单词上，将第一个字母和最后一个字母连接一条有向边，然后判断是否存在欧拉路径
#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;
int n;
int din[N], dout[N], p[N]; // 保存点的入度数，出度数，和父节点
bool st[N]; // 保存字母是否使用过了

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    char str[1010];
    
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(st, 0, sizeof st);
        for(int i = 0; i < 26; i++) p[i] = i; // 将父节点设置为自己
        
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            int len = strlen(str);
            int a = str[0] - 'a', b = str[len - 1] - 'a';
            st[a] = st[b] = true; // a和b两个字母使用过了
            dout[a]++, din[b]++; // a->b a的出度加1，b的入度加1
            p[find(a)] = find(b); // 将a的祖宗节点设置为b
        }
        
        int start = 0, end = 0;
        bool success = true;
        for(int i = 0; i < 26; i++) // 枚举每一个字母
            if(din[i] != dout[i]){ // 如果这个点入度不等于出度
                if(din[i] == dout[i] + 1) end++; // 入度比出度多1，表明是终点
                else if(din[i] + 1 == dout[i]) start++; // 出度比入度多1，表明是起点
                else{
                    success = false; // 否则，说明出度和入度相差大于1，无欧拉路径
                    break;
                }
            }
        
        if(success && !(!start && !end || start == 1 && end == 1)) success = false; // 如果起点和终点个数都为0或者起点和终点个数都为1，则表明存在欧拉路径，否则不存在
        
        int rep = -1;
        for(int i = 0; i < 26; i++) // 判断是否所有使用过的字母都在一个连通块中
            if(st[i]){
                if(rep == -1) rep = find(i); // 如果是第一个字母，则把连通块设置为它的祖宗节点
                else if(rep != find(i)){ // 后面的每个字母，如果不在一个连通块中，无欧拉回路
                    success = false;
                    break;
                }
            }
    
        if(success) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    
    return 0;
}