// ����һ������Ϊ N
//  ������ A
// ���Լ� M
//  ��ָ�ÿ��ָ���������������֮һ��

// C l r d����ʾ�� A[l],A[l+1],��,A[r]
//  ������ d
// ��
// Q l r����ʾѯ�������е� l?r
//  �����ĺ͡�
// ����ÿ��ѯ�ʣ����һ��������ʾ�𰸡�

// �����ʽ
// ��һ���������� N,M
// ��

// �ڶ��� N
//  ������ A[i]
// ��

// ������ M
//  �б�ʾ M
//  ��ָ�ÿ��ָ��ĸ�ʽ����Ŀ������ʾ��

// �����ʽ
// ����ÿ��ѯ�ʣ����һ��������ʾ�𰸡�

// ÿ����ռһ�С�

// ���ݷ�Χ
// 1��N,M��105
// ,
// |d|��10000
// ,
// |A[i]|��109
// ����������
// 10 5
// 1 2 3 4 5 6 7 8 9 10
// Q 4 4
// Q 1 10
// Q 2 4
// C 3 6 3
// Q 2 4
// ���������
// 4
// 55
// 9
// 15

/*
�����޸������ѯ��ʹ�������
������ͬʱ����һ��ֵʱ���޸������add������pushdown�������Խ������ӽڵ㶼����һ����
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, m;
int a[N];
struct node{
    int l, r;
    LL sum, add;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){ // �����ʱroot������ǲ�Ϊ0
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add; // ��root����������µݸ������ӽڵ㣬�޸��ӽڵ������ǣ������޸��ӽڵ������ڵ�sum
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0; 
    }
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, a[l], 0};
    else{
        tr[u]  = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d){
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d; // ����������sumÿ�����ۼ���d
        tr[u].add += d; // �޸������
    }
    else{
        pushdown(u); // �Ƚ�u����������´��ݣ�Ȼ���������޸�
        int mid = tr[u].l + tr[u].r >> 1; 
        if(l <= mid) modify(u << 1, l, r, d);
        if(r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u); // �Ƚ�u����������´���
    int mid = tr[u].l + tr[u].r >> 1;
    LL res = 0;
    if(l <= mid) res += query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    
    while(m--){
        char op[2];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C'){
            scanf("%d", &d);
            modify(1, l, r, d);
        }else{
            printf("%lld\n", query(1, l, r));
        }
    }
    
    return 0;
}