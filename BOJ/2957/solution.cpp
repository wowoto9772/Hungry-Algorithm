#include <stdio.h>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

class tree{
public:
	int l, r;
}T[300003];

ll C[300003];

int main(){

	int n;
	scanf("%d", &n);

	int root = 0;
	scanf("%d", &root);
	printf("0\n");

	set <int> t;
	t.insert(root);

	ll c = 0;
	for (int i = 2; i <= n; i++){
		int v;
		scanf("%d", &v);

		set <int> ::iterator le = t.lower_bound(v);
		set <int> ::iterator ri = t.upper_bound(v);
		if (le != t.begin())le--;
		if (ri == t.end()){
			if ((*le) < v){
				T[(*le)].r = v;
			}
			else{
				T[(*le)].l = v;
			}
			C[v] = C[(*le)] + 1;
		}
		else{
			if (!T[(*ri)].l && T[(*le)].r) {
				T[(*ri)].l = v;
				C[v] = C[(*ri)] + 1;
			}
			else if (!T[(*le)].r && T[(*ri)].l){
				T[(*le)].r = v;
				C[v] = C[(*le)] + 1;
			}
			else if (!T[(*le)].r && !T[(*ri)].l){
				while (true){}
				// 왜... 이 경우가 없는 거지...
			}
		}

		c += C[v];

		t.insert(v);

		printf("%lld\n", c);
	}

}