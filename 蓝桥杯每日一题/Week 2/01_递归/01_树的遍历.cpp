// 一个二叉树，树中每个节点的权值互不相同。

// 现在给出它的后序遍历和中序遍历，请你输出它的层序遍历。

// 输入格式
// 第一行包含整数 N
// ，表示二叉树的节点数。

// 第二行包含 N
//  个整数，表示二叉树的后序遍历。

// 第三行包含 N
//  个整数，表示二叉树的中序遍历。

// 输出格式
// 输出一行 N
//  个整数，表示二叉树的层序遍历。

// 数据范围
// 1≤N≤30
// ,
// 官方并未给出各节点权值的取值范围，为方便起见，在本网站范围取为 1∼N
// 。

// 输入样例：
// 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7
// 输出样例：
// 4 1 6 3 5 7 2

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 40;
int postorder[N], inorder[N];
unordered_map<int, int> l, r, pos;
int n;

int build(int il, int ir, int pl, int pr){
    int root = postorder[pr];
    int k = pos[root];
    if(il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if(ir > k) r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);
    return root;
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout << t << " ";
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> postorder[i];
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    
    return 0;
}