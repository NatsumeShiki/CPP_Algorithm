// ��������Ϊ N
//  ������ A
// ��Ȼ������ M
//  �в���ָ�

// ��һ��ָ������ C l r d����ʾ�������е� l?r
//  �������� d
// ��

// �ڶ���ָ������ Q x����ʾѯ�������е� x
//  ������ֵ��

// ����ÿ��ѯ�ʣ����һ��������ʾ�𰸡�

// �����ʽ
// ��һ�а����������� N
//  �� M
// ��

// �ڶ��а��� N
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
// Q 4
// Q 1
// Q 2
// C 1 6 3
// Q 2
// ���������
// 4
// 1
// 2
// 5

/*
����״����Ļ���������˲�֣���l~r������ÿ�����������һ�������ȼ���ֱ�ӱ���ԭ����Ĳ�����飬��add(i, a[i] - a[i - 1])
��ô��Ӳ�����add(l, c), add(r + 1, -c)
��ѯ������sum(a)
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int a[N];
LL tr[N];
int n, m;

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x){
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        add(i, a[i] - a[i - 1]);
    }
    
    while(m--){
        char op;
        int a, b, c;
        cin >> op >> a;
        if(op == 'C'){
            scanf("%d%d", &b, &c);
            add(a, c), add(b + 1, -c);
        }else printf("%lld\n", sum(a));
    }
    
    return 0;
}