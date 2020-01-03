#include<stdio.h>
#include<math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    int flag=1;
    if(n<=1){
        flag=0;
    }
    else if(n>3 && (n%2==0 || n%3==0)){
        flag=0;
    }
    long long int k=1;
    long long int a=6*k+1,b=6*k-1;
    while(flag==1 && b<=sqrt(n)){
        if(n%a==0 || n%b==0){
            flag=0;
        }
        k++;
        a=6*k+1;
        b=6*k-1;
    }
    if(flag==1){
        printf("Prime");
    }
    else{
        printf("Not a Prime");
    }
}