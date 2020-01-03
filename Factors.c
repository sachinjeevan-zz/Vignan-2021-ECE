#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,k=0;
    scanf("%lld",&n);
    long long int lim=sqrt(n);
    long long int arr[lim],count=0,sum=0;
    for(long long int i=1;i<=lim;i++){
        if(n%i==0){
            printf("%d ",i);
            sum=sum+i;
            count++;
            if(i!=(n/i)){
                arr[k]=n/i;
                k++;
                count++;
                sum=sum+(n/i);
            }
        }
    }
    k=k-1;
    while(k>=0){
        printf("%d ",arr[k]);
        k--;
    }
    printf("\n%d\n%d",count,sum);
}