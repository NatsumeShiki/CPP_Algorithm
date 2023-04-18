// 给定 n
//  个变量和 m
//  个不等式。其中 n
//  小于等于 26
// ，变量分别用前 n
//  的大写英文字母表示。

// 不等式之间具有传递性，即若 A>B
//  且 B>C
// ，则 A>C
// 。

// 请从前往后遍历每对关系，每次遍历时判断：

// 如果能够确定全部关系且无矛盾，则结束循环，输出确定的次序；
// 如果发生矛盾，则结束循环，输出有矛盾；
// 如果循环结束时没有发生上述两种情况，则输出无定解。
// 输入格式
// 输入包含多组测试数据。

// 每组测试数据，第一行包含两个整数 n
//  和 m
// 。

// 接下来 m
//  行，每行包含一个不等式，不等式全部为小于关系。

// 当输入一行 0 0 时，表示输入终止。

// 输出格式
// 每组数据输出一个占一行的结果。

// 结果可能为下列三种之一：

// 如果可以确定两两之间的关系，则输出 "Sorted sequence determined after t relations: yyy...y.",其中't'指迭代次数，'yyy...y'是指升序排列的所有变量。
// 如果有矛盾，则输出： "Inconsistency found after t relations."，其中't'指迭代次数。
// 如果没有矛盾，且不能确定两两之间的关系，则输出 "Sorted sequence cannot be determined."。
// 数据范围
// 2≤n≤26
// ，变量只可能为大写字母 A∼Z
// 。

// 输入样例1：
// 4 6
// A<B
// A<C
// B<C
// C<D
// B<D
// A<B
// 3 2
// A<B
// B<A
// 26 1
// A<Z
// 0 0
// 输出样例1：
// Sorted sequence determined after 4 relations: ABCD.
// Inconsistency found after 2 relations.
// Sorted sequence cannot be determined.
// 输入样例2：
// 6 6
// A<F
// B<D
// C<E
// F<D
// D<E
// E<F
// 0 0
// 输出样例2：
// Inconsistency found after 6 relations.
// 输入样例3：
// 5 5
// A<B
// B<C
// C<D
// D<E
// E<A
// 0 0
// 输出样例3：
// Sorted sequence determined after 4 relations: ABCDE.

// 0表示不确定，1表示能唯一确定，2表示矛盾  
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 26;
int n, m;
bool g[N][N], d[N][N]; // g用于保存两个符号之间的关系，如果g[i][j] = true，表示 i < j，否则表示二者还没有确定关系，d是g的备份，用于进行floyd
bool st[N]; // 在输出大小顺序的时候确定某个符号已经输出了

void floyd(){
    memcpy(d, g, sizeof d); // 将g数组拷贝到d数组中
    // 做floyd算法，最终可以得出传递闭包
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)  
                d[i][j] |= d[i][k] && d[k][j]; // 注意这里使用 |= ，如果已经是true就不用修改
}

int check(){
    for(int i = 0; i < n; i++)
        if(d[i][i]) // 如果d[i][i] 是true，就表示出现了 A < A 这种情况，说明是无解的，所以是返回2
            return 2;
    // 通过下面这个循环判断是否每两个符号之间的关系已经确定
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(!d[i][j] && !d[j][i])
                return 0; // 如果有没有确定的就返回0
                
    return 1; // 否则返回1，表示关系已经确定完了
}

char get_min(){
    for(int i = 0; i < n; i++)
        if(!st[i]){ // 如果第i个符号还没有输出
            bool flag = true; 
            for(int j = 0; j < n; j++)
                if(!st[j] && d[j][i]){ // 如果j还没有输出并且d[j][i]为true，表示i不是最小的
                    flag = false; // flag设置为false，跳出循环
                    break;
                }
            if(flag){ // 如果经过了上面这层循环flag还是true，表示i是当前还没有输出的最小值
                st[i] = true; // 标记它已经输出了
                return 'A' + i; // 返回这个符号
            }
        }
}

int main(){
    while(cin >> n >> m, n || m){
        memset(g, 0, sizeof g);
        int type = 0, t; // type一开始是0表示他们之间的关系还没有确定，t表示在第几轮确定关系
        for(int i = 1; i <= m; i++){
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            
            if(!type){ // 如果此时关系还没有确定
                g[a][b] = 1; // 保存 a < b
                floyd(); // 进行floyd
                type = check(); // 通过check函数判断他们之间的关系是否已经确定了
                if(type) t = i; // 如果已经确定了，保存轮数，并且后面的输入不会进入这个if中
            }
        }
        
        if(!type) puts("Sorted sequence cannot be determined.");
        else if(type == 2) printf("Inconsistency found after %d relations. \n", t);
        else {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for(int i = 0; i < n; i++) printf("%c", get_min()); // 每次查找最小的那个输出
            printf(".\n");
        }
    }
    
    return 0;
}

// 优化掉一维，不使用floyd
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 26;
int n, m;
bool d[N][N];
bool st[N];

int check(){
    for(int i = 0; i < n; i++)
        if(d[i][i])
            return 2;
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(!d[i][j] && !d[j][i])
                return 0;
                
    return 1;
}

char get_min(){
    for(int i = 0; i < n; i++)
        if(!st[i]){
            bool flag = true;
            for(int j = 0; j < n; j++)
                if(!st[j] && d[j][i]){
                    flag = false;
                    break;
                }
            if(flag){
                st[i] = true;
                return 'A' + i;
            }
        }
}

int main(){
    while(cin >> n >> m, n || m){
        memset(d, 0, sizeof d);
        int type = 0, t;
        for(int i = 1; i <= m; i++){
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            
            if(!type){
                d[a][b] = 1;
                for(int x = 0; x < n; x++){
                    if(d[x][a]) d[x][b] = 1; // a < b，那么如果 x < a，则有 x < b
                    if(d[b][x]) d[a][x] = 1; // a < b，那么如果 b < x，则有 a < x
                    for(int y = 0; y < n; y++)
                        if(d[x][a] && d[b][y]) // 如果x < a && b < y，因为a < b，所以必然有 x < y
                            d[x][y] = 1;
                }
                type = check();
                if(type) t = i;
            }
        }
        
        if(!type) puts("Sorted sequence cannot be determined.");
        else if(type == 2) printf("Inconsistency found after %d relations. \n", t);
        else {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for(int i = 0; i < n; i++) printf("%c", get_min());
            printf(".\n");
        }
    }
    
    return 0;
}