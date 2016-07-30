#include <stdio.h>

#include <vector>
#include <queue>

using namespace std;

long long P[30000];
long long A[50000];
bool p[110000];

long long ab(long long a){ return a < -a ? -a : a; }

int main()
{
	int nxt, top = 0, top2 = 0;

	queue <long long> Q;
	queue <int> S;

	for (long long i = 2; i*i < 110000; i++){
		nxt = i;
		if (!p[i]){
			Q.push(i*i);
			P[top++] = i*i;
			S.push(top2);
			A[top2++] = i*i;
			for (int j = i + i; j < 110000; j += i)p[j] = true;
		}
	}
	for (long long i = nxt + 1; i < 110000; i++){
		if (!p[i]){
			Q.push(i*i);
			P[top++] = i*i;
			S.push(top2);
			A[top2++] = i*i;
		}
	}

	int max = 2000000000;

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

	long long n;
	while (scanf("%lld", &n) == 1){
		long long l = n, r = max, m;
		long long s;
		while (l <= r){
			m = (l + r) / 2;
			
			long long ans = m;
			for (int i = 0; i < top2; i++){
				if (ab(A[i]) <= m){
					long long k = m / A[i];
					ans -= k;
				}
			}
			if (ans < n)l = m + 1;
			else if (ans > n)r = m - 1;
			else{
				s = m;
				r = m - 1;
			} // s != m s 출력 / s == m m 출력 걍 s출력
		}
		printf("%d\n", s);
	}
}