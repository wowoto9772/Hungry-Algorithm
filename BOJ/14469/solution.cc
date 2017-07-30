#include <cstdio>
#include <algorithm>

using namespace std;

class ele{
public:
    int a, c;
    bool operator<(const ele &A)const{
        if(a == A.a)return c < A.c;
        return a < A.a;
    }
}e[103];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &e[i].a, &e[i].c);
    }
    
    sort(e, e+n);
    
    int t = 0;
    for(int i=0; i<n; i++){
        if(e[i].a <= t)t += e[i].c;
        else{
            t = e[i].a + e[i].c;
        }
    }
    
    printf("%d\n", t);

}