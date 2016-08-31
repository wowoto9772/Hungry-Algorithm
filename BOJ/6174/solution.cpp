#include <stdio.h>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int x[3053], y[3053], r[3053];

int rev[3053];

bool meet(int i, int j){
	int d_2 = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	if(d_2 == (r[i] + r[j]) * (r[i] + r[j]))return true;
	return false;
}

int gcd(int a, int b){

	int m = 1;

	while(m){
		m = a % b;
		a = b;
		b = m;
	}

	return a;

}

vector < vector <int> > lnk;

int main(){

	int n, x_t, y_t;
	scanf("%d %d %d", &n, &x_t, &y_t);

	lnk.resize(n+1);

	int s = -1, t = -1;

	for(int i=1; i<=n; i++){
		scanf("%d %d %d", &x[i], &y[i], &r[i]);

		if(x[i] == 0 && y[i] == 0)s = i;
		if(x[i] == x_t && y[i] == y_t)t = i;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j){
				if(meet(i, j))lnk[i].push_back(j);
			}
		}
	}


	queue <int> q;

	rev[s] = -1;
	q.push(s);

	while(!q.empty()){

		int f = q.front();q.pop();

		if(f == t)continue;

		for(int i=0; i<lnk[f].size(); i++){
			int g = lnk[f][i];
			if(rev[g])continue;
			rev[g] = f;
			q.push(g);
		}

	}


	double ans = 0;


	int it = t;
	while(it > 0){
		int i = it;
		int g = gcd(r[i], r[s]);

		int ri = r[i] / g, rs = r[s] / g;
		ans += (10000LL * rs) / (double)ri;
		it = rev[it];
	}


	printf("%lld\n", (ll)ans);

}
