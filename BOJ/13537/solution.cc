#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define le(p) (p<<1)
#define ri(p) (le(p)|1)

vector < vector <int> > tree;
void update(int x, int p, int il, int ir, int v){
    if(p < il || ir < p)return ;
    tree[x].push_back(v);
    if(il != ir){
        int m = (il+ir) >> 1;
        update(le(x), p, il, m, v);
        update(ri(x), p, m+1, ir, v);
    }
}

int query(int x, int xl, int xr, int il, int ir, int v){
    if(xr < il || ir < xl){
        return 0;
    }
    else if(il <= xl && xr <= ir){
        return tree[x].end() - upper_bound(tree[x].begin(), tree[x].end(), v);
    }else{
        int m = (xl + xr)>>1;
        return query(le(x), xl, m, il, ir, v) + query(ri(x), m+1, xr, il, ir, v);
        
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    int s = 1;
    while(s < n)s <<= 1;
    
    tree.resize(s<<1);
    
    for(int i=0; i<n; i++){
        int e;
        scanf("%d", &e);
        update(1, i, 0, n-1, e);
    }
    
    for(int i=1; i<s; i++)sort(tree[i].begin(), tree[i].end());
    
    int q;
    scanf("%d", &q);
    
    while(q--){
        int il, ir, v;
        scanf("%d %d %d", &il, &ir, &v);
        il--, ir--;
        printf("%d\n", query(1, 0, n-1, il, ir, v));
    }
    
}