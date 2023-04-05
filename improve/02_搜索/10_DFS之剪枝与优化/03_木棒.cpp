// 乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过 50
//  个长度单位。

// 然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。

// 请你设计一个程序，帮助乔治计算木棒的可能最小长度。

// 每一节木棍的长度都用大于零的整数表示。

// 输入格式
// 输入包含多组数据，每组数据包括两行。

// 第一行是一个不超过 64
//  的整数，表示砍断之后共有多少节木棍。

// 第二行是截断以后，所得到的各节木棍的长度。

// 在最后一组数据之后，是一个零。

// 输出格式
// 为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。

// 数据范围
// 数据保证每一节木棍的长度均不大于 50
// 。

// 输入样例：
// 9
// 5 2 1 5 2 1 5 2 1
// 4
// 1 2 3 4
// 0
// 输出样例：
// 6
// 5

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 70;
int n;
int w[N], sum, length; // sum保存所有木棍长度
bool st[N];

bool dfs(int u, int s, int start){ // u表示枚举到了第几根木棒，s是当前木棒的长度，start表示枚举到了第几根木棍
    if(u * length == sum) return true; // 枚举到了第u根木棍，如果所有木棍长度加起来等于sum，就说明length可以拼接成功，返回true
    if(s == length) return dfs(u + 1, 0, 0); // 如果这个木棒长度已经到了length，就取进行下一根木棒的拼接
    
    // 剪枝：按照组合数方式枚举
    for(int i = start; i < n; i++){
        if(st[i]) continue;
        if(s + w[i] > length) continue;
        
        st[i] = true; // 把第i根木棍拼接到u上
        if(dfs(u, s + w[i], i + 1)) return true;
        st[i] = false;
        
        // 如果是木棒的第一根木棍失败了，则返回false，表示这个方案是行不通的
        if(!s) return false;
        // 如果是木棒的最后一根木棍失败了，则返回false，表示这个方案是行不通的
        if(s + w[i] == length) return false;
        
        // 如果当前木棍加到当前木棒中失败了，则略过后面所有长度相等的木棍
        int j = i;
        while(j < n && w[j] == w[i]) j++;
        i = j - 1;
    }
    
    return false;
}

int main(){
    while(cin >> n, n){
        memset(st, 0, sizeof st);
        sum = 0;
        
        for(int i = 0; i < n; i++){
            cin >> w[i];
            sum += w[i];
        }
        
        // 优化搜索顺序：从长的木棍开始枚举，减少分支数量
        sort(w, w + n); 
        reverse(w, w + n);
        
        length = 1;
        while(true){
            if(sum % length == 0 && dfs(0, 0, 0)){ // 总长度必须可以整除以length
                cout << length <<endl;
                break;
            }
            length++;
        }
    }
    
    return 0;
}