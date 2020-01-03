#include<stdio.h>
#include<math.h>
long long int fact(long long int num){
    long long int fact = 1;
    while(num!=1){
        fact = fact*num;
        num--;
    }
    return fact;
}
long long int Ndigits(long long int n){
    long long int count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    return count;
}
long long int sumDigits(long long int n,long long int digit){
    long long int sum=0;
    while(n!=0){
        sum=sum+pow(n%10,digit);
        n=n/10;
    }
    return sum;
}
long long int strong(long long int n){
    long long int sum=0;
    while(n!=0){
        sum=sum+fact(n%10);
        n=n/10;
    }
    return sum;
}
long long int reverse(long long int n){
    long long int reverse=0;
    while(n!=0){
        reverse=reverse*10+(n%10);
        n=n/10;
    }
    return reverse;
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int ans = Ndigits(n);
    long long int sum = sumDigits(n,ans);
    if(n==sum){
        printf("It is a Amstrong number\n");
    }
    else{
        printf("It is not a Amstrong number\n");
    }
    long long int reverse1= reverse(n);
    printf("%lld %lld %lld",ans,sum,reverse1);
    if(n==reverse1){
        printf("\nIt is a Palindrome");
    }
    else{
        printf("\nIt is not a palindrome");
    }
    long long int str = strong(n);
    if(str==n){
        printf("\n It is strong number");
    }
    else{
         printf("\n It is not a strong number");
    }

}