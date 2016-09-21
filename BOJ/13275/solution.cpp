#include <stdio.h>
 
#include <string.h>
 
#include <algorithm>
 
using namespace std;
 
char S[100003];
char T[200003];
int A[100003];
int B[200003];
 
int main(){
 
    int n;
    scanf("%s", S+1);

    n = strlen(S+1);
 
    int p = 0, r = 0;
 
    // for odd length
 
    for(int i=1; i<=n; i++){
 
        if(i <= r)A[i] = min(A[2*p-i], r-i);
        else
            A[i] = 0;
 
        while(i-A[i]-1 > 0 && i+A[i]+1 <= n && S[i-A[i]-1] == S[i+A[i]+1])A[i]++;
 
        if(r < i+A[i])r = i+A[i], p = i;
 
    }
 
 
    // for even length
 
    p = r = 0;
 
    for(int i=1; i<=n; i++){
        T[2*i-1] = '#';
        T[2*i] = S[i];
    }

    T[2*n+1] = '#';
 
    int m = 2 * n + 1;
 
    for(int i=1; i<=m; i++){
 
        if(i <= r)B[i] = min(B[2*p-i], r-i);
        else
            B[i] = 0;
 
        while(i-B[i]-1 > 0 && i+B[i]+1 <= m && T[i-B[i]-1] == T[i+B[i]+1])B[i]++;
 
        if(r < i+B[i])r = i+B[i], p = i;
 
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        
        ans = max(ans, A[i] * 2 + 1);
        
    }

    for(int i=1; i<=m; i++){

        ans = max(ans, B[i]);

    }

    printf("%d\n", ans);
  
}
