// ����һ���Ǹ��������� a
// ����ʼ����Ϊ N
// ��

// �� M
//  �����������������ֲ������ͣ�

// A x����Ӳ�������ʾ������ĩβ���һ���� x
// �����еĳ��� N
//  ���� 1
// ��
// Q l r x��ѯ�ʲ���������Ҫ�ҵ�һ��λ�� p
// ������ l��p��r
// ��ʹ�ã�a[p] xor a[p+1] xor �� xor a[N] xor x
//  ������������ֵ��
// �����ʽ
// ��һ�а����������� N��M
// ������������������ʾ��

// �ڶ��а��� N
//  ���Ǹ���������ʾ��ʼ������ A
// ��

// ������ M
//  �У�ÿ������һ����������ʽ������������

// �����ʽ
// ÿ��ѯ�ʲ������һ����������ʾѯ�ʵĴ𰸡�

// ÿ����ռһ�С�

// ���ݷ�Χ
// N,M��3��105,0��a[i]��107
// ��

// ����������
// 5 5
// 2 6 4 3 6
// A 1 
// Q 3 5 4 
// A 4 
// Q 5 7 0 
// Q 3 6 6 
// ���������
// 4
// 5
// 6

#include<iostream>
#include<cstring>
using namespace std;

const int N = 600010, M = N * 25;
int n, m;
int s[N];
int tr[M][2], max_id[M];
int root[N], idx;

void insert(int i, int k, int p, int q){
    if(k < 0){
        max_id[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if(p) tr[q][v ^ 1] = tr[p][v ^ 1];
    tr[q][v] = ++idx;
    insert(i, k - 1, tr[p][v], tr[q][v]);
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int query(int root, int C, int L){
    int p = root;
    for(int i = 23; i >= 0; i--){
        int v = C >> i & 1;
        if(max_id[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];
        else p = tr[p][v];
    }
    
    return C ^ s[max_id[p]];
}

int main(){
    scanf("%d%d", &n, &m);
    
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);
    
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
        root[i] = ++idx;
        insert(i, 23, root[i - 1], root[i]);
    }
    
    char op[2];
    int l, r, x;
    while(m--){
        scanf("%s", op);
        if(*op == 'A'){
            scanf("%d", &x);
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n, 23, root[n - 1], root[n]);
        }else{
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r - 1], s[n] ^ x, l - 1));
        }
    }
    
    return 0;
}