#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

class ele{
public:
    int x, y;
    ele(){}
    ele(int _x, int _y){
        x = _x, y = _y;
    }
    
    bool operator<(const ele &A)const{
        if(y == A.y)return x < A.x;
        return y < A.y;
    }
};

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    multiset <int> my;
    
    for(int i=0; i<n; i++){
        int v;
        scanf("%d", &v);
        my.insert(v);
    }
    
    vector < ele > your;
    
    for(int i=0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        your.emplace_back(x, y);
    }
    
    sort(your.begin(), your.end());
    
    int c = 0;
    for(int i=0; i<your.size(); i++){
        multiset<int>::iterator p = my.lower_bound(your[i].x);
        if(p == my.end())continue;
        else{
            if(*p <= your[i].y){
                c++;
                my.erase(p);   
            }
        }
    }
    
    printf("%d\n", c);
    
}