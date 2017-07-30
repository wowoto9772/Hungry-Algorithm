#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class BIT{
public:
	vector <long long> T;
	int S;
	
	BIT(int n) : S(n), T(n+1) {}

	void Update(int p, int v){
		while (p <= S){
			T[p] += v;
			p += p & (-p);
		}
	}

	long long Sum(int p){
		long long ret = 0;
		while (p > 0){
			ret += T[p];
			p -= p & (-p);
		}
        return ret;
	}
};

int e[1003];

int main(){

    int n, q;
    scanf("%d %d", &n, &q);
    
    BIT tree(n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &e[i]);
        tree.Update(i, e[i]);
    }
    
    while(q--){
        int t;
        scanf("%d", &t);
        
        if(t == 2){
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            printf("%lld\n", -tree.Sum(d) + tree.Sum(c-1) + tree.Sum(b) - tree.Sum(a-1));
        }else{
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", tree.Sum(y) - tree.Sum(x-1));
            tree.Update(x, -e[x]);
            tree.Update(y, -e[y]);
            swap(e[x], e[y]);
            tree.Update(x, e[x]);
            tree.Update(y, e[y]);
        }
    }

}