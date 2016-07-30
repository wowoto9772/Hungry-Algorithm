#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long
const long long LIMIT = 1E18;

using namespace std;

vector <ll> G;
ll A[70] = { 1 }, B[70] = { 1 }, C[70] = { 1 };

int main(){
	ll a, b, c, k;
	int ta = 0, tb = 0, tc = 0;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
	ll lim = (LIMIT / a);

	for (int i = 1;; i++){
		if (LIMIT / A[i - 1] < a)break;
		A[i] = A[i - 1] * a;
		ta++;
	}
	for (int i = 1;; i++){
		if (LIMIT / B[i - 1] < b)break;
		B[i] = B[i - 1] * b;
		tb++;
	}
	for (int i = 1;; i++){
		if (LIMIT / C[i - 1] < c)break;
		C[i] = C[i - 1] * c;
		tc++;
	}
	for (int i = 0; i <= ta; i++){
		for (int j = 0; j <= tb; j++){
			if (LIMIT / A[i] < B[j])break;
			for (int k = 0; k <= tc; k++){
				if (LIMIT / (A[i] * B[j]) < C[k])break;
				G.push_back(A[i] * B[j] * C[k]);
			}
		}
	}

	sort(G.begin(), G.end());
	G.resize(distance(G.begin(), unique(G.begin(), G.end())));

	printf("%lld\n", G[k]);
}