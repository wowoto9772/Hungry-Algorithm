#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// Author : wowoto9772

class BIT{
public:
	vector <int> T;
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


int main(){

    int n;
    scanf("%d", &n);

    vector <int> v(n), p(n);

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
        p[i] = v[i];
    }

    sort(p.begin(), p.end());

    BIT tree(n);

    for(int i=0; i<n; i++){
        int e = lower_bound(p.begin(), p.end(), v[i]) - p.begin();
        tree.Update(++e, 1);
        printf("%d\n", tree.Sum(n) - tree.Sum(e-1));
    }

}
