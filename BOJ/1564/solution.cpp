#include <cstdio>

using namespace std;
using ll = long long;

bool p[1000003];
int P[100003];
int A[100003];
int top;

int main()
{

    int nxt;
    for (int i = 2; i*i < 1000000; i++){
        nxt = i;
        if (!p[i]){
            P[top++] = i;
            for (int j = i + i; j <= 1000000; j += i)p[j] = true;
        }
    }for (int i = nxt + 1; i <= 1000000; i++)if (!p[i])P[top++] = i;

    int n;
    scanf("%d", &n);

    for (int i = 0; P[i] <= n && i < top; i++){
        ll k = 1;
        for (int j = 1; k <= n; j++){
            k *= P[i];
            A[i] += n / k;
        }
    }

    int ans = A[0] < A[2] ? A[0] : A[2];
    A[0] -= ans;
    A[2] -= ans;

    ll m = 1;
    bool big = false;

    for (int i = 0; i < top && P[i] <= n; i++){
        if (A[i]){
            for (int j = 1; j <= A[i]; j++){
                m *= P[i];
                if(m >= 100000){
                    m %= 100000;
                    big = true;
                }
            }
        }
    }

    if(big)printf("%05lld\n", m);
    else
        printf("%lld\n", m);
}
