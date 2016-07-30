#include <stdio.h>
#include <queue>
#define ll long long
#define nxt(i) ((i+1)%3)

using namespace std;

class ele {
public:
	int x;
	ll t;
	ele() {}
	ele(int a, ll b) { x = a, t = b; }

	bool operator<(const ele &A)const {
		return t > A.t;
	}
};

int o[3];

int main() {

	int n;
	ll l;
	scanf("%d %lld", &n, &l);

	long long ans = 0;

	priority_queue <ele> q;

	for (int i = 1; i <= n; i++) {
		char x;
		ll p;
		int d;
		scanf(" %c %lld %d", &x, &p, &d);

		x -= 'A';

		ans += l;
		if (d & 1) {
			ans -= p;
			o[x]++;
		}
		else {
			ans += p;
			q.emplace(x, p);
		}
	}

	printf("%lld\n", ans);

	int pre = -1;

	while (!q.empty()) {

		ele f = q.top(); q.pop();

		vector <ele> tmp;
		while (!q.empty()) {
			tmp.push_back(q.top()); q.pop();
			if (tmp.back().t != f.t) {
				q.emplace(tmp.back());
				tmp.pop_back();
				break;
			}
		}

		if (tmp.empty())o[nxt(f.x)]++;
		else { 
			// if collision, my direction
			// else, next direction
			tmp.push_back(f);
			for (int i = 0; i < tmp.size(); i++) {
				o[tmp[i].x]++;
			}
		}

	}

	for (int i = 0; i < 3; i++)printf("%d ", o[i]);

}