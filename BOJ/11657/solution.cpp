#include <stdio.h>
#include <limits.h>
#include <vector>

using namespace std;

class ele{
public:
	int s, a, c;
	ele(){}
	ele(int s_, int _a, int _c){
		s = s_, a = _a, c = _c;
	}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	vector < ele > lnk;

	for (int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		lnk.emplace_back(a, b, c);
	}

	int d[503];
	bool neg = false; // is negative cycle;
	for (int i = 2; i <= n; i++)d[i] = INT_MAX;

	d[1] = 0;

	for (int i = 0; i < n; i++){ // O(V*E)
		for (int j = 0; j < lnk.size(); j++){
			if (d[lnk[j].s] == INT_MAX)continue;
			if (d[lnk[j].a] > d[lnk[j].s] + lnk[j].c){
				d[lnk[j].a] = d[lnk[j].s] + lnk[j].c;
				if (i == n - 1)neg = true;
			}
		}
	}

	if (neg)printf("-1\n");
	else{
		for (int i = 2; i <= n; i++){
			printf("%d\n", (d[i] == INT_MAX ? -1 : d[i]));
		}
	}
}