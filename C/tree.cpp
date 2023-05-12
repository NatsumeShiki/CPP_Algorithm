#include<iostream>
#include<cstring>
using namespace std;

const int MaxSize = 100;

struct BTNode{
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
};

void CreateBTree(BTNode * &b, string str){
    BTNode *stk[MaxSize], *p = NULL;
    int top = -1, k = 0, j = 0;
    char ch = str[j];
    b = NULL;
    while(ch != '\0'){
        switch(ch){
            case '(': top++; stk[top] = p; k = 1; break;
            case ')': top--; break;
            case ',': k = 2; break;
            default:
                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if(b == NULL) b = p;
                else {
                    switch(k){
                        case 1: stk[top]->lchild = p; break;
                        case 2: stk[top]->rchild = p; break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

void DispBTree(BTNode *b){
    printf("%c ", b->data);
    if(b->lchild) DispBTree(b->lchild);
    if(b->rchild) DispBTree(b->rchild);
}

void postorder(BTNode *b){
    BTNode* stk1[MaxSize], *stk2[MaxSize];
    int top1 = -1, top2 = -1;
    BTNode* p = b;
    if(p == NULL) return;
    top1++;
    stk1[top1] = p;
    while(top1 > -1){
        p = stk1[top1];
        top1--;
        top2++;
        stk2[top2] = p;
        if(p->lchild != NULL){
            top1++;
            stk1[top1] = p->lchild;
        }
        if(p->rchild != NULL){
            top1++;
            stk1[top1] = p->rchild;
        }
    }
    while(top2 > -1) printf("%c ", stk2[top2--]->data);
}

void DestoryBTree(BTNode * &b){
    free(b);
}

void solve(){
    BTNode *b;
    char exp[MaxSize];
    // string exp;
    puts("请输入用括号表示法输入的一个二叉树:");
    scanf("%s", exp);
    // exp = "A(B(,C(D,E)),F(G(,H),))";
    CreateBTree(b, exp);
    printf("二叉树遍历为:");
    DispBTree(b);
    puts("");
    printf("后序遍历序列为:");
    postorder(b);
    puts("");
    DestoryBTree(b);
}

int main(){
    
//     #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);
//   #endif

  solve();

    return 0;
}
