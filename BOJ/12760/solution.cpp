#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class ele {
public:
	
	ele() {}
	ele(int a, int b) { v = a, p = b; }

	int v, p;
	bool operator<(const ele &A)const {
		return v < A.v;
	}
};

int turn[103];
int pts[103];
int men[103];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	priority_queue <ele> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int v;
			scanf("%d", &v);
			q.emplace(v, i);
		}
	}

	int cur = 0;

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		if (men[f.p] == cur) {

			if (turn[cur] < f.v) {
				turn[cur] = f.v;
				pts[f.p]++;
				cur++;
			}
			else if (turn[men[f.p]] == f.v) {
				pts[f.p]++;
			}

		}
		else{
			if(turn[men[f.p]] == f.v)pts[f.p]++;
		}

		men[f.p]++;
	}
	
	int mpt = 0;
	vector <int> ans;

	for (int i = 1; i <= n; i++) {
		if (mpt < pts[i]) {
			mpt = pts[i];
			ans.clear();
			ans.push_back(i);
		}else if(mpt == pts[i]){
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);

}