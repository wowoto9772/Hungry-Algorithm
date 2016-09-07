#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

vector < vector <int> > lnk;

ll dp3[5003][3]; // triple

int chk[5003];

ll dy(int c, int m){
	
	if(m == 3)return 1;

	ll &ret = dp[c][m];

	if(ret != -1)return ret;

	ret = 0;

	for(int i=0; i<lnk[c].size(); i++){
		
		int n = lnk[c][i];

		if(p[c] == n)continue;

		p[n] = c;

		ret += dy(n, m+1);


	}

	return ret;

}

int main(){

	int t;
	scanf("%d", &t);


	int tc = 0;


	while(t--){

		lnk.clear();

		int n, m;
		scanf("%d %d", &n, &m);

		lnk.resize(n+1);

		for(int i=1; i<=m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			lnk[a].push_back(b);
			lnk[b].push_back(a);
		}

		for(int i=1; i<=n; i++){
			chk[i] = 0;
			for(int j=1; j<3; j++)dp[i][j] = -1;
		}

		ll tot = n * (n-1) * (n-2) / 3;

		// two and remain



		// remove triple

		for(int i=1; i<=n; i++){
			tot -= dy(i, 1);
		}

		printf("Case #%d: %lld\n", ++tc, tot);

	}

}
