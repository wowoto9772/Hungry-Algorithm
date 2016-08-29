#include <stdio.h>
#include <set>

using namespace std;

#define ll long long

ll e[503][503];

ll row[503], col[503];

ll dig[2];

int main(){

	int n;
	scanf("%d", &n);

	ll x = 0;

	int a, b;

	for(int i=1; i<=n; i++){

		ll k = 0;

		bool zero = false;

		for(int j=1; j<=n; j++){
			scanf("%lld", &e[i][j]);
			k += e[i][j];
			if(e[i][j] == 0)zero = true, a = i, b = j;
			row[i] += e[i][j];
			col[j] += e[i][j];
		}

		if(!zero){
			x = k;
		}
	}

	if(n == 1)printf("1");
	else{

		e[a][b] = x - row[a];
		row[a] += e[a][b];
		col[b] += e[a][b];

		bool imp = false;

		for(int i=1; i<=n; i++){
			dig[0] += e[i][i];
			dig[1] += e[i][n+1-i];
		}

		if(e[a][b] > 1e+18 || e[a][b] < 1)imp = true;

		set <ll> cc;

		for(int i=1; i<=n; i++){
			cc.insert(row[i]);
			cc.insert(col[i]);
		}

		cc.insert(dig[0]);
		cc.insert(dig[1]);

		if(cc.size() != 1 || imp)printf("-1");
		else{
			printf("%lld\n", e[a][b]);
		}

	}

}
