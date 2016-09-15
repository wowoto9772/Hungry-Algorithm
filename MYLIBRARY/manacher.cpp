#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

int S[1000003];
int T[2000003];
int A[1000003];
int B[2000003];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)scanf("%d", &S[i]);

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
        T[2*i-1] = S[i];
        if(i != n)T[2*i] = '#';
    }

    int m = 2 * n - 1;

    for(int i=1; i<=m; i++){

        if(i <= r)B[i] = min(B[2*p-i], r-i);
        else
            B[i] = 0;

        while(i-B[i]-1 > 0 && i+B[i]+1 <= m && T[i-B[i]-1] == T[i+B[i]+1])B[i]++;

        if(r < i+B[i])r = i+B[i], p = i;

    }

    int q;
    scanf("%d", &q);

    while(q--){

        int a, b;
        scanf("%d %d", &a, &b);

        if(a > b)swap(a, b);

        int c = b-a+1;

        if(c&1){
            int k = (a+b)>>1;
            if(A[k] >= (c>>1))printf("1\n");
            else
                printf("0\n");
        }else{
            a = a*2-1;
            b = b*2-1;

            int k = (a+b)>>1;

            int c = b - k;

            if(B[k] >= c)printf("1\n");
            else
                printf("0\n");
        }

    }

}

// O(n), find longest palindrome !
