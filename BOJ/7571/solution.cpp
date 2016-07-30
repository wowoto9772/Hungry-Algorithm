/*
#include <stdio.h>
#include <algorithm>

using namespace std;

int X[10003], Y[10003];

int A(int a){ return a < -a ? -a : a; }

int main(){
int n;
scanf("%d", &n);

for (int i = 1; i <= n; i++){
scanf("%d %d", &X[i], &Y[i]);
}

sort(X + 1, X + 1 + n);
sort(Y + 1, Y + 1 + n);

int s = n / 2;
long long ans = 0;

for (int i = 1; i <= n; i++){
ans += A(X[i] - X[s]) + A(Y[i] - Y[s]);
}

printf("%lld\n", ans);
}
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int X[100003], Y[100003];

int A(int a){ return a < -a ? -a : a; }

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++){
		scanf("%d %d", &X[i], &Y[i]);
	}

	sort(X, X + m);
	sort(Y, Y + m);

	int s = m / 2;
	long long ans = 0;

	for (int i = 0; i < m; i++){
		ans += A(X[i] - X[s]) + A(Y[i] - Y[s]);
	}

	printf("%lld\n", ans);
}