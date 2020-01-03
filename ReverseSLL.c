#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main()
{
struct Node* head = (struct Node*)malloc(sizeof(struct Node));
struct Node* temp = head;
long long int n;
scanf("%lld",&n);
for(long long int i=0;i<n;i++){
    scanf("%lld",&(temp->data));
    if(i!=n-1){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    temp->next = newNode;
    temp=temp->next;
    }
    else{
        temp->next=NULL;
    }

}
temp=head;
struct Node* prev=NULL;
struct Node* right= temp->next;
while(right!=NULL){
    temp->next = prev;
    prev=temp;
    temp=right;
    right=temp->next;
}
temp->next=prev;
head=temp;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}

}