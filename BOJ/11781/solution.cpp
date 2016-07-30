#include <stdio.h>
#include <limits.h>

#include <vector>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

bool eff[5003][5003];
bool chk[5003];

ll d[5003];
ll t1, t2;

ll stay(ll ts, ll ta, int s, int a){
	if (!eff[s][a] || t2 <= ts || ta <= t1)return ta;
	else{

		ll le = max(ts, t1);
		ll ri = min(ta, t2);

		ll intime = ri - le;

		ll dist = (ta - ts);
		dist -= (le - ts);
		dist -= intime / 2; // moving distance until ri

		ll ret = ri;
		ll rem = t2 - ri;

		ll m = min(rem, dist * 2);
		ret += m;

		dist -= m / 2;

		ret += dist; // go until t2

		return ret;

	}

}

class ele{
public:
	int a;
	ll c;
	ele(){}
	ele(int a_, ll c_){ a = a_, c = c_; }
	bool operator<(const ele &A)const{
		return c > A.c;
	}
};

int main(){

	int n, m;
	scanf("%d %d %lld %lld", &n, &m, &t1, &t2);

	t1 *= 2;
	t2 *= 2;

	vector < vector < ele > > lnk;

	lnk.resize(n + 1);

	for (int i = 1; i <= m; i++){

		int a, b, d, rd;
		ll c;

		scanf("%d %d %lld %d %d", &a, &b, &c, &d, &rd);

		c *= 2;

		lnk[a].emplace_back(b, c);
		lnk[b].emplace_back(a, c);

		if (d)eff[a][b] = true;
		if (rd)eff[b][a] = true;

	}

	for (int i = 2; i <= n; i++)d[i] = LLONG_MAX;

	priority_queue <ele> q;
	q.emplace(1, 0LL);

	while (!q.empty()){

		ele pp = q.top(); q.pop();

		if (chk[pp.a])continue;

		chk[pp.a] = true;

		for (int i = 0; i < lnk[pp.a].size(); i++){
			ele psh = lnk[pp.a][i];

			if (chk[psh.a])continue;

			ll ncst = stay(pp.c, pp.c + psh.c, pp.a, psh.a);
			if (d[psh.a] > ncst){
				psh.c = d[psh.a] = ncst;
				q.emplace(psh);
			}
		}

	}

	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(ans, d[i]);
	}

	printf("%lld", ans / 2);

	if (ans % 2)printf(".5");

	printf("\n");

}