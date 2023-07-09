// ��������Ϊ N
//  ������ A
// ���Լ� M
//  ��ָ�ÿ��ָ���������������֮һ��

// 1 x y����ѯ���� [x,y]
//  �е���������Ӷκͣ��� maxx��l��r��y
// {��i=lrA[i]
// }��
// 2 x y���� A[x]
//  �ĳ� y
// ��
// ����ÿ����ѯָ����һ��������ʾ�𰸡�

// �����ʽ
// ��һ���������� N,M
// ��

// �ڶ��� N
//  ������ A[i]
// ��

// ������ M
//  ��ÿ�� 3
//  ������ k,x,y
// ��k=1
//  ��ʾ��ѯ����ʱ��� x>y
// ���뽻�� x,y
// ����k=2
//  ��ʾ�޸ġ�

// �����ʽ
// ����ÿ����ѯָ�����һ��������ʾ�𰸡�

// ÿ����ռһ�С�

// ���ݷ�Χ
// N��500000,M��100000
// ,
// ?1000��A[i]��1000
// ����������
// 5 3
// 1 2 -3 4 5
// 1 2 3
// 2 2 -1
// 1 3 2
// ���������
// 2
// -1

/*
1.�����޸� pushup
2.��ѯ �����ڵ�����ֶκ�
struct node{
  int l, r;  �������Ҷ˵�
  int tmax;  ��������ֶκ�
  int lmax;  ���ǰ׺��
  int rmax;  ����׺��
  int sum;   �����
}

tmax = max(leftson.tmax, rightson.tmax, leftson.rmax + rightson.lmax) 
������������Ӷκ���������������ӵ���������Ӷκͣ��Һ��ӵ���������Ӷκͣ����ӵ������׺�ϼ����Һ��ӵ����ǰ׺��
lmax = max(leftson.lmax, leftson.sum + rightson.lmax)
�������ǰ׺����������������ӵ����ǰ׺�ͣ����ӵ�����ͼ����Һ��ӵ����ǰ׺��
*/
#include<iostream>
#include<cstring>
using namespace std;

using namespace std;
const int N = 500010;
int n, m;
int w[N];
struct node{
    int l, r;
    int sum, lmax, rmax, tmax;
}tr[N * 4];

void pushup(node &u, node &l, node &r){ // ����u�����Ӻ��Һ��ӣ��޸�u��ֵ
    u.sum = l.sum + r.sum; // u������͵������ӵ�����ͼ����Һ��ӵ������
    u.lmax = max(l.lmax, l.sum + r.lmax); // u��ǰ׺�͵������ӵ�ǰ׺�ͺ���������ͼ����Һ���ǰ׺�͵Ľϴ�ֵ
    u.rmax = max(r.rmax, r.sum + l.rmax); // u�ĺ�׺�͵����Һ��ӵ���׺�ͺ��Һ�������ͼ������Ӻ�׺�͵Ľϴ�ֵ
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax); // u����������Ӷκ͵������ӵ���������Ӷκͺ��Һ��ӵ���������Ӷκͺ����ӵ�ǰ׺�ͼ��Һ��ӵĺ�׺�͵����ֵ
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){ // ����
    if(l == r) tr[u] = {l, r, w[r], w[r], w[r], w[r]}; // ���l����r��ֱ�Ӹ���u�Ľ��
    else{
        tr[u] = {l, r}; // ����u�����Ҷ˵�
        int mid = l + r >> 1; // ȡ�е�
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // ���½���
        pushup(u); // �ٸ������Һ��Ӹ���u
    }
}

int modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v}; // ����ҵ�������㣬ֱ�Ӹ���
    else{
        int mid = tr[u].l + tr[u].r >> 1; // ��ȡu���е�
        if(x <= mid) modify(u << 1, x, v); // ���x�����ӣ��޸�����
        else modify(u << 1 | 1, x, v); // ���x���Һ��ӣ��޸��Һ���
        pushup(u); // �޸ĸ��ڵ�
    }
}

node query(int u, int l, int r){ // ��ѯl��r�����ڵ���������Ӷκ�
    if(tr[u].l >= l && tr[u].r <= r) return tr[u]; // ���u�ڵ�����Ҷ˵���l��r֮�䣬����u�ڵ�
    else{
        int mid = tr[u].l + tr[u].r >> 1; // ��ȡu�ڵ���е�
        if(r <= mid) return query(u << 1, l, r); // ���rС�ڵ���mid�����ѯ�ķ�Χ���������У��ݹ�����
        else if(l > mid) return query(u << 1 | 1, l, r); // ���l����mid�����ѯ�ķ�Χ�����Һ����У��ݹ��Һ���
        else{ // ����Ȱ������ӣ��ְ����Һ���
            auto left = query(u << 1, l, r); // ��ȡleft�ڵ�
            auto right = query(u << 1 | 1, l, r); // ��ȡright�ڵ�
            node res; // ���
            pushup(res, left, right); // �޸�res��ֵ
            return res; // ���ؽ��
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]); // ����һ��ʼÿ���±�洢��ֵ
    build(1, 1, n);
    
    int k, x, y;
    while(m--){
        scanf("%d%d%d", &k, &x, &y);
        if(k == 1){
            if(x > y) swap(x, y);
            printf("%d\n", query(1, x, y).tmax);
        }else modify(1, x, y);
    }
    
    return 0;
}