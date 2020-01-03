#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int i=1,temp,j;
    while(i<n){
        temp=arr[i];
        j=i-1;
        while(j>=0){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                j--;
                
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
        i++;
    }
    for(i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
}