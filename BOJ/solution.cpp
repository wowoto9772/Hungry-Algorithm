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

bool chk[303][303];

int main(){

	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);

	for(int i=1; i<=n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		chk[x][y] = true;
	}

	bipartite_matching btm(r+c+1);

	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(!chk[i][j]){
				btm.addEdge(i, r+j);
			}
		}
	}

	printf("%d\n", btm.solve());

}
