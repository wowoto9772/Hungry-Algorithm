#include <stdio.h>
#define min(a, b) (a) < (b) ? (a) : (b)

#define ll long long

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		ll x, y;
		scanf("%lld %lld", &x, &y);

		ll a = 0, z;
		while (x + y >= 12 && x >= 5){
			z = min(x / 5, y / 7);
			if (z){
				a += z;
				x -= z * 5, y -= z * 7;
			}
			else{
				if (y){
					x -= 12 - y;
					a++;
					y = 0;
				}
				else{
					a += x / 12;
					x %= 12;
				}
			}
		}

		printf("%lld\n", a);
	}
}