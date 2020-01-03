#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};
int max(int a,int b){
    return a>b?a:b;
}
int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
int getBalance(struct Node* root){
    if(root==NULL)
    return 0;
    return height(root->left)-height(root->right);
}
struct Node* RightRotate(struct Node* root){
    struct Node* x = root->left;
    struct Node* y = x->right;
    x->right=root;
    root->left=y;
    root->height = 1+max(height(root->left),height(root->right));
    x->height = 1+max(height(x->left),height(x->right));
    return x;
}
struct Node* leftRotate(struct Node* root){
    struct Node* x = root->right;
    struct Node* y = x->left;
    x->left=root;
    root->right=y;
    root->height = 1+max(height(root->left),height(root->right));
     x->height = 1+max(height(x->left),height(x->right));
    return x;
}
struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    temp->height=1;
    return temp;
}
struct Node* inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct Node* insert(struct Node* root,int data){
    if(root==NULL){
        return newNode(data);
    }
    else if(data>root->data){
        root->right = insert(root->right,data);
    }
    else if(data<root->data){
        root->left = insert(root->left,data);
    }

    root->height = 1+max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if(balance>1 && data<root->left->data){
        return RightRotate(root);
    }
    if(balance<-1 && data>root->right->data){
        return leftRotate(root);
    }
    if(balance>1 && data>root->left->data){
        root->left = leftRotate(root->left);
        return RightRotate(root);
    }
    if(balance<-1 && data<root->right->data){
        root->right = RightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
int main(){
    struct Node* root=NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    inorder(root);
}