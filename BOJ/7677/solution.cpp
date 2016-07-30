#include <stdio.h>
#include <map>

#define ll long long
#define mod 10000

using namespace std;

map <ll, ll> F;

ll fibonacci(ll a)
{
	if (a < 2) return 1;
	if (F[a]) return F[a];
	return F[a] = (fibonacci((a + 1) / 2)*fibonacci(a / 2) + fibonacci((a - 1) / 2)*fibonacci((a - 2) / 2)) % mod;
}

int main() {

	int a;
	while (scanf("%d", &a) == 1 && a > -1) {
		if (!a)printf("0\n");
		else {
			printf("%d\n", fibonacci(a - 1));
		}
	}

}