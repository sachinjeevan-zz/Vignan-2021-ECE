#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return a>b?a:b;
}
int main()
{
    char str[1000];
    scanf("%s",str);
    int n=strlen(str);
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int i,j,k=1;
    while(1){
        i=0;
        j=k;
        if(i==0 && j==n){
            break;
        }
        while(j<n){
            if(str[i]==str[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
            i++;
            j++;
        }
        k++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    char ans[dp[0][n-1]+1];
    k=0;
    i=0;
    j=n-1;
    while(dp[i][j]!=0){
        if(str[i]==str[j]){
            ans[k]=str[i];
            k++;
            i++;
            j--;
        }
        else{
            if(dp[i][j-1]>=dp[i+1][j]){
                j--;
            }
            else{
                i++;
            }
        }
    }
    int t;
    if(dp[0][n-1]%2==0){
        t=k-1;
        while(t>=0){
            ans[k]=ans[t];
            t--;
            k++;
        }
        ans[k]='\0';
    }
    else{
        t=k-2;
        while(t>=0){
            ans[k]=ans[t];
            t--;
            k++;
        }
        ans[k]='\0';
    }
    printf("%s",ans);
}