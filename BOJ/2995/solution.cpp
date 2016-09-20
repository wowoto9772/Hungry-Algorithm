#include <stdio.h>

#include <algorithm>

using namespace std;

class ele{
    public:

        int l, r;

        ele(){}
        ele(int _l, int _r){
            l = _l, r = _r;
        }

        bool operator<(const ele &A)const{

            if(l == A.l)return r > A.r;

            return l < A.l;

        }

};

int main(){

    int n;
    scanf("%d", &n);

    vector <ele> v(n);

    for(int i=0; i<n; i++)scanf("%d %d", &v[i].l, &v[i].r);

    sort(v.begin(), v.end());

    vector <int> ri(n, -1), dp(n);

    int top = 0;

    for(int i=0; i<n; i++){

        if(!top)dp[top++] = i;
        else{

            int l = 0, r = top-1, m, c;

            while(l <= r){

                m = (l+r) >> 1;

                c = dp[m];

                if(v[c].r >= v[i].r){
                    l = m + 1;
                }else{
                    r = m - 1;
                }

            }

            c = dp[m];

            if(v[c].r >= v[i].r)m++;

            dp[m] = i;

            if(m){
                ri[i] = dp[m-1];
            }

            top = max(m+1, top);

        }

    }

    printf("%d\n", top);

    int x = dp[top-1];

    vector <int> e;

    while(x != -1){
        e.push_back(x);
        x = ri[x];
    }

    for(int i=e.size()-1; i>=0; i--)printf("%d %d\n", v[e[i]].l, v[e[i]].r);

}
