// ��ʦ����С�ɿ�һ��ά�����е���������С�ɿ�ϣ������������ɡ�

// �г�Ϊ N
//  �����У�������Ϊ a1,a2,��,aN
// ��

// ���������ֲ�����ʽ��

// �������е�һ����ȫ����һ��ֵ��
// �������е�һ����ȫ����һ��ֵ��
// ѯ�������е�һ�����ĺͣ����ڴ𰸿��ܴܺ���ֻ����������ģ P
//  ��ֵ��
// �����ʽ
// ��һ���������� N
//  �� P
// ��

// �ڶ��к��� N
//  ���Ǹ�����������������Ϊ a1,a2,��,aN
// ��

// ��������һ������ M
// ����ʾ����������

// �ӵ����п�ʼÿ������һ������������Ĳ���������������ʽ��

// ���� 1
// ��1 t g c����ʾ���������� t��i��g
//  �� ai
//  ��Ϊ ai��c
// ��
// ���� 2
// ��2 t g c����ʾ���������� t��i��g
//  �� ai
//  ��Ϊ ai+c
// ��
// ���� 3
// ��3 t g��ѯ���������� t��i��g
//  �� ai
//  �ĺ�ģ P
//  ��ֵ��
// ͬһ����������֮����һ���ո������ÿ�п�ͷ��ĩβû�ж���ո�

// �����ʽ
// ��ÿ������ 3
// ���������������г��ֵ�˳���������һ��һ��������ʾѯ�ʽ����

// ���ݷ�Χ
// 1��N,M��105
// ,
// 1��t��g��N
// ,
// 0��c,ai��109
// ,
// 1��P��109
// ����������
// 7 43
// 1 2 3 4 5 6 7
// 5
// 1 2 5 5
// 3 2 4
// 2 3 7 9
// 3 1 3
// 3 4 7
// ���������
// 2
// 35
// 8
// ��������
// ��ʼʱ����Ϊ {1,2,3,4,5,6,7}
// ��

// ������ 1
//  �β���������Ϊ {1,10,15,20,25,6,7}
// ��

// �Ե� 2
//  �β�������Ϊ 10+15+20=45
// ��ģ 43
//  �Ľ���� 2
// ��

// ������ 3
//  �β���������Ϊ {1,10,24,29,34,15,16}
// ��

// �Ե� 4
//  �β�������Ϊ 1+10+24=35
// ��ģ 43
//  �Ľ���� 35
// ��

// �Ե� 5
//  �β�������Ϊ 29+34+15+16=94
// ��ģ 43
//  �Ľ���� 8
// ��

/*
�������Ҫ������������ǣ��ֱ���mul��add
������Ҫ���۵��ǣ����u�ڵ�ͬʱ��mul��add��������ǣ�����Ҫ�Ƚ����ĸ�������
����ȼӺ�ˣ�����˵(((x + a) * b) + c) * d����ͬʱ������������ǣ�Ҫ�ڽ��мӺͳ˵Ĳ������ܸ���
����ȳ˺�ӣ�����˵(x * a + b) * c + d����ô������� x * ac + bc + d���ȽϷ��㣬��˲������ַ���

��Ŀ���޸������֣�Ϊ�˺ϲ���Ϊһ�֣����������ַ���
����ǳ� *c + d, d = 0����ô x * c + d = x * c
����Ǽ� *c + d, c = 1����ô x * c + d = x * 1 + d = x + d
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 100010;
int n, m, p;
int w[N];
struct node{
    int l, r;
    int sum, add, mul;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p; // ��������������ĺ�
}

// ��u�ڵ���г˺ͼ�����
void eval(node &t, int add, int mul){
    t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p; // �ȳ˺��
    t.mul = (LL)t.mul * mul % p; // �޸Ľڵ��mul����ǣ�(x * a + b) * c + d = x * ac + bc * d������t��mul�����ֻ��Ҫ����c
    t.add = ((LL)t.add * mul + add) % p; // �޸Ľڵ��add����ǣ���Ҫ�ȳ˺��
}

void pushdown(int u){ // ���޸������ӽڵ��sum�������
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1; // ���u�������
}

void build(int u, int l, int r){ // ����
    if(l == r) tr[u] = {l, r, w[l], 0, 1}; 
    else{
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul){ // �޸Ĳ���
    if(tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul); // �������ȫ���ǣ�ֱ���޸�sum�������
    else{
        pushdown(u); // �Ƚ�u����������´���
        int mid = tr[u].l + tr[u].r >> 1; // �޸�������
        if(l <= mid) modify(u << 1, l, r, add, mul);
        if(r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u); // �����޸�sum
    }
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum = query(u << 1, l, r);
    if(r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
    return sum;
}

int main(){
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    
    scanf("%d", &m);
    while(m--){
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1){
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }else if(t == 2){
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }else printf("%d\n", query(1, l, r));
    }
    
    
    return 0;
}