#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <int> getTree(int v){
    vector <int> t;
    while(v){
        t.push_back(v&1);
        v >>= 1;
    }
    while(t.size() < 31)t.push_back(0);
    reverse(t.begin(), t.end());
    return t;
} // 2^31-1

set <int> node;

int e[100003];
int k[32];

int main(){

    k[30] = 1;
    for(int i=29; i>=0; i--)k[i] = k[i+1] << 1;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &e[i]);
        node.insert(e[i]);
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        vector <int> my = getTree(e[i]);
        int v = 0;
        for(int j=0; j<my.size(); j++){
            int g = 1^my[j];
            if(g)v |= k[j];
            set <int> ::iterator it = node.lower_bound(v);

            if(it == node.end() || ((*it) & v) != v){
                if(g){
                    v ^= k[j];
                    it = node.lower_bound(v);
                }
            }

            ans = max(ans, e[i] ^ (*it));
        }
    }

    printf("%d\n", ans);

}
