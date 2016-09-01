#include <stdio.h>


#include <vector>

using namespace std;

class bipartite_matching {
	public:

		int n;
		vector <bool> vst;
		vector <int> le, ri;
		vector < vector <bool> > lnk;

		bipartite_matching(int _n) { // zero_base

			n = _n;

			vst.resize(n);
			le.resize(n);
			ri.resize(n);
			lnk.resize(n);

			for (int i = 0; i < n; i++) {
				le[i] = ri[i] = -1;
				lnk[i].resize(n);
			}

		}

		void addEdge(int s, int a) {
			lnk[s][a] = true;
		}

		bool augmenting(int c) {

			if (vst[c])return false;

			vst[c] = true;

			for (int i = 0; i < n; i++) {
				if (lnk[c][i]) {
					if (ri[i] == -1 || augmenting(ri[i])) {
						ri[i] = c;
						le[c] = i;
						return true;
					}
				}
			}

			return false;

		}

		int solve() {

			int ret = 0;

			for (int i = 0; i < n; i++) {
				if (ri[i] == -1) { // not matched
					for (int j = 0; j < n; j++)vst[j] = false;
					ret += augmenting(i);
				}
			}

			return ret;

		}

};

char str[103][103];

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int m, n;
		scanf("%d %d", &m, &n);

		for(int i=1; i<=m; i++){
			scanf("%s", str[i]+1);
		}

		bipartite_matching btm(m+n+1);

		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				if(str[i][j] == '1')btm.addEdge(i, m+j);
			}
		}

		printf("Case #%d: %d\n", ++tc, btm.solve());

	}

}
