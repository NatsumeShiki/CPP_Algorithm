#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int key;
    struct node* lchild, *rchild;
}BSTNode;

void DispLeaf(BSTNode* b){
    if(b != NULL){
        printf(" %d", b->key);
        if(b->lchild != NULL || b->rchild != NULL){
            printf("(");
            DispLeaf(b->lchild);
            if(b->rchild != NULL) printf(",");
            DispLeaf(b->rchild);
            printf(")");
        }
    }
}

BSTNode* InsertBST(BSTNode* bt, int k){
    if(bt == NULL){
        bt = (BSTNode *)malloc(sizeof(BSTNode));
        bt->key = k, bt->lchild = bt->rchild = NULL;
    }else if(k < bt->key) bt->lchild = InsertBST(bt->lchild, k);
    else if(k > bt->key) bt->rchild = InsertBST(bt->rchild, k);
    return bt;
}

BSTNode *CreateBST(int a[], int n){
    BSTNode *bt = NULL, *root = NULL;
    int i = 0;
    while(i < n){
        printf("第%d步，插入%d:", i + 1, a[i]);
        bt = InsertBST(bt, a[i]);
        if(root == NULL) root = bt;
        DispLeaf(root);
        puts("");
        i++;
    }
    return root;
}

BSTNode* SearchBST(BSTNode* bt, int k){
    printf("%d ", bt->key);
    if(bt == NULL || bt->key == k) return bt;
    if(k < bt->key) return SearchBST(bt->lchild, k);
    else SearchBST(bt->rchild, k);
}

BSTNode* SearchBST1(BSTNode* bt, int k){
    BSTNode* p = bt;
    int s[10], cnt = 0;
    while(p != NULL){
        s[cnt++] = p->key;
        if(p->key == k) break;
        else if(k < p->key) p = p->lchild;
        else p = p->rchild;
    }
    for(int i = cnt - 1; i >= 0; i--) printf("%d ", s[i]);
    puts("");
    return p;
}

BSTNode* DeleteBST(BSTNode* bt, int k){
    if(bt == NULL) return bt;
    BSTNode* p = bt, *f = NULL;
    while(p != NULL){
        if(p->key == k) break;
        f = p;
        if(k <p->key) p = p->lchild;
        else p = p->rchild;
    }
    if(p == NULL) return bt;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == bt) bt = NULL;
        else {
            if(f->lchild == p) f->lchild = NULL;
            else f->rchild = NULL;
        }
        free(p);
    }else if(p->rchild == NULL){
        if(f == NULL) bt = bt->lchild;
        else{
            if(f->lchild = p->lchild) f->lchild = p->lchild;
            else f->rchild = p->lchild;
        }
        free(p);
    }else if(p->lchild == NULL){
        if(f == NULL) bt = bt->rchild;
        else{
            if(f->lchild == p) f->lchild = p->rchild;
            else f->rchild = p->rchild;
        }
        free(p);
    }else{
        BSTNode* q = p->lchild;
        f = p;
        while(q->rchild != NULL){
            f = q;
            q = q->rchild;
        }
        p->key = q->key;
        if(q == f->lchild) f->lchild = q->lchild;
        else f->rchild = q->lchild;
        free(q);
    }
    return bt;
}

void DestoryBST(BSTNode *bt){
    free(bt);
}

int main(){
    int a[10] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
    puts("(1)创建一颗BST树:");
    BSTNode *root = NULL;
    root = CreateBST(a, 10);
    printf("(2)BST:");
    DispLeaf(root);
    puts("");
    puts("(3)bt是一颗BST");
    printf("(4)查找6关键字(递归，顺序):");
    SearchBST(root, 6);
    puts("");
    printf("(5)查找6关键字(非递归，逆序):");
    SearchBST1(root, 6);
    puts("(6)删除操作:");
    printf("原 BST:");
    DispLeaf(root);
    puts("");
    printf("删除结点4:");
    root = DeleteBST(root, 4);
    DispLeaf(root);
    puts("");
    printf("删除结点5:");
    root = DeleteBST(root, 5);
    DispLeaf(root);
    puts("");
    puts("(7)销毁BST");

    return 0;
}
