#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    char color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data,char a,struct Node* parent){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->color = a;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
}
struct Node* insertFixUp(struct Node* root,struct Node* z){
   
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct Node* insert(struct Node* root,int data){
    struct Node* temp=root;
    struct Node* z=root;
    struct Node* parent=NULL;
    if(root==NULL){
        root=newNode(data,'B',parent);
        return root;
    }
    else{
    while(1){
        if(data>temp->data){
            if(temp->right!=NULL){
                parent=temp;
                temp=temp->right;
            }
            else{
                temp->right=newNode(data,'R',parent);
                z=temp->right;
                break;
            }
        }
        else{
            if(temp->left!=NULL){
                parent = temp;
                temp=temp->left;
            }
            else{
                temp->left = newNode(data,'R',parent);
                z=temp->left;
                break;
            }
        }
    }
    //insertFixUp(root,z);
    }
}
int main(){
    struct Node* root = NULL;
    root = insert(root,60);
    insert(root,50);
    insert(root,40);
    insert(root,80);
    insert(root,70);
    insert(root,55);
    inorder(root);
}