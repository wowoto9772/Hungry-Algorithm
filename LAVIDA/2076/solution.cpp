#include <stdio.h>
#include <vector>

using namespace std;

#define ll long long

bool is[10000003] = { true, true, };
vector <ll> p(664579);

int main()
{
	int nxt;
	int top = 0;
	for (int i = 2; i*i <= 10000000; i++){
		nxt = i;
		if (is[i])continue;
		for (int j = i*i; j <= 10000000; j += i){
			is[j] = true;
		}
		p[top++] = (i);
	}
	for (int i = nxt + 1; i <= 10000000; i++)if (!is[i])p[top++] = i;

	ll q;
	while (scanf("%lld", &q) == 1 && q){
		/*
		x + x+1 + x+2 + ... x+p-1 = x+p + x+p+1 + ... + x+p+q-1
		----------p--------------   -------------q-------------

		(2x+p-1)p/2 = (2x+2p+q-1)q/2

		2(q-p)x = p^2-p-q^2+q-2pq

		x = (1 - (p+q)) / 2 + pq/(p-q)
		*/

		/*
		x = (p-q)*(1-(p+q)) + 2pq
		---------------------
		2(p-q)
		2x = (1-(p+q)) + 2 pq/(p-q)

		p-q = m

		2q*(q+m)/m = 2q^2/m + 2q

		2x = (1-(2q+m)) + 2q^2/m + 2q
		2x = 1-m + 2q^2/m + 2q

		i) m Â¦¼ö 2q^2/m È¦¼ö
		ii) m È¦¼ö 2q^2/m Â¦¼ö
		*/

		ll rq = q;

		vector <ll> dq, c;
		for (int i = 0; i < p.size() && p[i] * p[i] <= q; i++){ // 2 * q * q
			if (q%p[i])continue;
			else{
				dq.push_back(p[i]);
				c.push_back(0);
				while (!(q%p[i])){
					q /= p[i];
					c[c.size() - 1]++;
				}
				c[c.size() - 1] *= 2LL;
			}
		}

		if (q != 1){
			dq.push_back(q), c.push_back(2);
		}

		q = rq;

		// add 2
		if (q % 2 == 0){
			c[0]++;
		}
		else{
			dq.push_back(2);
			c.push_back(1);
		}


		ll ans = 0;
		ll k = 1;

		// assume m = 2k
		for (int i = 0; i < dq.size(); i++){
			if (dq[i] == 2)continue;
			k *= (c[i] + 1);
		}
		ans = k;
		// assume m = 2k+1
		k = 1;
		for (int i = 0; i < dq.size(); i++){
			if (dq[i] == 2)continue;
			k *= (c[i] + 1);
		}
		ans += k;


		printf("%lld\n", ans);
	}
}