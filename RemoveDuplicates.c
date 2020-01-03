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
struct Node* prev=temp;
while(temp->next!=NULL){
    struct Node* comp = temp->next;
    prev=temp;
    while(comp!=NULL){
        if(temp->data == comp->data){
            if(comp->next==NULL){
                prev->next = NULL;
            }
            else{
                prev->next = comp->next;
            }
        }
        prev=comp;
        comp=comp->next;
    }
    temp=temp->next;
}
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
}