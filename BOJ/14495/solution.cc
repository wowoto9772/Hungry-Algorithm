#include <cstdio>

using namespace std;
using ll = long long;

ll p[118] = { 0, 1, 1, 1, };

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 4; i <= n; i++)p[i] = p[i - 1] + p[i - 3];

	printf("%lld\n", p[n]);

}