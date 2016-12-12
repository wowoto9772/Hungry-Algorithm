#include <cstdio>

using namespace std;

using ll = long long;
const ll lmod = 1000000007LL;

int nxt[1000003];
int order[1000003]; 

ll color[1000003] = { 1, };

int main(){

	int n;
	ll k;
	scanf("%d %lld", &n, &k);

	color[1] = k;
	color[2] = (k*(k - 1)) % lmod;
	color[3] = (k*(k - 1)*(k - 2)) % lmod;

	for (int i = 4; i <= n; i++){
		color[i] = (k - 1) * color[i - 2];
		color[i] += (k - 2) * color[i - 1];
		color[i] %= lmod;
	}

	for (int i = 1; i <= n; i++){
		scanf("%d", &nxt[i]);
	}

	ll ans = 1;
	int top = 1;
	int pre = 0; // pre_processed

	for (int i = 1; i <= n; i++){

		if (order[i])continue;

		int len = 0;
		int cur = i;
		while (true){ // find cycle's length
			if (order[cur]){
				if (order[cur] < order[i])len = 0; // prev cycle
				else
				    len = top - order[cur]; // new cycle
				break;
			}
			else{
				order[cur] = top++;
				cur = nxt[cur];
			}
		}

		pre += len;
		ans *= color[len];
		ans %= lmod;
	}

	for (int i = 1; i <= n - pre; i++){ // not yet
		ans *= k - 1;
		ans %= lmod;
	}

	printf("%lld\n", ans);
}
