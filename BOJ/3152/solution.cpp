#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main(){

    vector <ll> st;
    st.push_back(1LL);

    ll p, n[4];
    scanf("%lld", &p);

    for(int i=0; i<4; i++)scanf("%lld", &n[i]);

    ll limit = max({n[0], n[1], n[2], n[3]});

    for(int i=0; i<st.size(); i++){
        ll e = st[i];
        if(e*p >= limit)break;
        st.push_back(e*p);
        if(e*p+1 >= limit)break;
        st.push_back(e*p+1);
    }

    printf("%d\n", (int)st.size());

    for(int x=0; x<4; x++){

        ll c = n[x];
        int d = 0;

        for(int i=0; d < 2 && i<st.size()-1; i++){
            for(int j=i+1; d < 2 && j<st.size(); j++){
                if(st[i] + st[j] > c)break;
                else if(st[i] + st[j] == c){
                    d++;
                    break;
                }
            }
        }

        printf("%d ", d == 1);

    }

}
