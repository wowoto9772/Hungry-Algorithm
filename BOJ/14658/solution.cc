#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[103], b[103];

int main(){
    
    vector <int> x, y;
    int l, k;
    scanf("%*d %*d %d %d", &l, &k);
    
    for(int i=0; i<k; i++){
        scanf("%d %d", &a[i], &b[i]);
        x.push_back(a[i]);
        y.push_back(b[i]);
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    
    int r = 0;
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<y.size(); j++){
            int q = 0;
            for(int p=0; p<k; p++){
                if(x[i] <= a[p] && a[p] <= x[i]+l){
                    if(y[j] <= b[p] && b[p] <= y[j]+l){
                        q++;
                    }
                }
            }
            if(r < q)r = q;
        }
    }
    
    printf("%d\n", k-r);
    
}