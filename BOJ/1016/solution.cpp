#include <stdio.h>

#include <vector>
#include <queue>

using namespace std;

long long P[100000];
long long A[650000];
bool p[1100000];

long long ab(long long a){ return a < -a ? -a : a; }

int main()
{
	int nxt, top = 0, top2 = 0;

	queue <long long> Q;
	queue <int> S;

	for (long long i = 2; i*i < 1100000; i++){
		nxt = i;
		if (!p[i]){
			Q.push(i*i);
			P[top++] = i*i;
			S.push(top2);
			A[top2++] = i*i;
			for (int j = i + i; j < 1100000; j += i)p[j] = true;
		}
	}
	for (long long i = nxt + 1; i < 1100000; i++){
		if (!p[i]){
			Q.push(i*i);
			P[top++] = i*i;
			S.push(top2);
			A[top2++] = i*i;
		}
	}

	long long max = 1000001000000;

	while (!Q.empty()){
		long long qf = Q.front();
		int sf = S.front();
		Q.pop(), S.pop();
		for (int i = sf + 1; i < top; i++){
			long long k = -qf * P[i];
			if (ab(k) <= max){
				A[top2++] = k;
				Q.push(k), S.push(i);
			}
			else{
				break;
			}
		}
	}

	long long n, m;
	while (scanf("%lld %lld", &n, &m) == 2){
		long long ans = m - n + 1;
		for (int i = 0; i < top2; i++){
			if (ab(A[i]) <= m){
				long long k = (m / A[i]) - (n-1) / A[i];
				ans -= k;
			}
		}
		printf("%d\n", ans);
	}
}