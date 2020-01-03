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
long long int key;
scanf("%lld",&key);
temp=head;
struct Node* prev=NULL;
while(temp!=NULL){
if(temp->data == key){
    if(temp==head){
        head = temp->next;
    }
    else if(temp->next == NULL){
        prev->next = NULL;
    }
    else{
        prev->next = temp->next;
    }
}
prev=temp;
temp=temp->next;
}
temp=head;
while(temp!=NULL){
    printf("%lld ",temp->data);
    temp=temp->next;
}
}