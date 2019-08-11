#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll p[103];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	priority_queue <ll> q;
	set <ll> chk;

	for (int i = 0; i < n; i++){
		scanf("%lld", &p[i]);
		q.push(-p[i]);
	}

	sort(p, p + n);

	ll maxValue = p[n-1];

	int c = 0;
	while (!q.empty()){
		ll f = -q.top(); q.pop();
		++c;

		if (c == k){
			printf("%lld\n", f);
			break;
		}

		for (int i = 0; i < n; i++){
			ll v = f * p[i];

			if (q.size() >= k-c && maxValue < v)continue;
			if (v > (1LL<<31))break;

			if (chk.find(v) == chk.end()){
				if (maxValue < v){
					maxValue = v;
				}
				q.push(-v);
				chk.insert(v);
			}
		}
	}
}
