#include <stdio.h>
#include <memory.h>
#include <vector>
#define ll long long

using namespace std;

int N;
ll ans;

vector < vector <int> > L;
vector < vector <int> > C;

int d[10003], x[10003];

void v(int c, int w){
	d[c] = w;
	for (int j = 0; j < L[c].size(); j++){
		int n = L[c][j];
		if (d[n] != -1)continue;
		v(n, w + C[c][j]);
		x[c] += x[n];
	}
	x[c]++;
}

bool g[10003];
void s(int c){
	for (int i = 0; i < L[c].size(); i++){
		int n = L[c][i];
		if (g[n])continue;
		g[n] = true;

		int a = N - x[n], b = x[n];
		ll k = C[c][i] * a - C[c][i] * b;
		if (ans + k < ans){
			ans = ans + k;
		}

		s(L[c][i]);
	}
}

int main(){
	while (scanf("%d", &N) == 1 && N){
		L.resize(N), C.resize(N);
		for (int i = 1; i < N; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			L[a].push_back(b);
			L[b].push_back(a);
			C[a].push_back(c);
			C[b].push_back(c);
		}

		memset(d, 0xff, sizeof(d));
		memset(x, 0, sizeof(x));
		memset(g, 0, sizeof(g));

		v(0, 0);
		ans = 0;
		for (int i = 0; i < N; i++)ans += d[i];
		
		g[0] = true;
		s(0);

		printf("%lld\n", ans);

		for (int i = 0; i < N; i++)L[i].clear(), C[i].clear();
	}
}