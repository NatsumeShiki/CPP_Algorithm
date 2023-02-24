// 有 N
//  个元素，编号 1,2..N
// ，每一对元素之间的大小关系是确定的，关系具有反对称性，但不具有传递性。

// 注意：不存在两个元素大小相等的情况。

// 也就是说，元素的大小关系是 N
//  个点与 N×(N−1)2
//  条有向边构成的任意有向图。

// 然而，这是一道交互式试题，这些关系不能一次性得知，你必须通过不超过 10000
//  次提问来获取信息，每次提问只能了解某两个元素之间的关系。

// 现在请你把这 N
//  个元素排成一行，使得每个元素都小于右边与它相邻的元素。

// 你可以通过我们预设的 bool 函数 compare 来获得两个元素之间的大小关系。

// 例如，编号为 a
//  和 b
//  的两个元素，如果元素 a
//  小于元素 b
// ，则 compare(a,b) 返回 true，否则返回 false。

// 将 N
//  个元素排好序后，把他们的编号以数组的形式输出，如果答案不唯一，则输出任意一个均可。

// 数据范围
// 1≤N≤1000
// 输入样例
// [[0, 1, 0], [0, 0, 0], [1, 1, 0]]
// 输出样例
// [3, 1, 2]

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> res;
        res.push_back(1);
        for(int i = 2; i <= N; i++){
            int l = 0, r = res.size() - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(compare(res[mid], i)) l = mid;
                else r = mid - 1;
            }
            res.push_back(i);
            for(int j = res.size() - 2; j > l; j--) swap(res[j], res[j + 1]);
            if(compare(i, res[l])) swap(res[l], res[l + 1]);
        }
        return res;
    }
    
};