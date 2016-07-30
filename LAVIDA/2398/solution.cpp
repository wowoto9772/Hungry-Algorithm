#include <stdio.h>

bool iP(int a){
	if (a == 2)return true;
	else if (a == 1 || !(a % 2))return false;
	else{
		for (int i = 3; i*i <= a; i += 2){
			if (!(a%i))return false;
		}return true;
	}
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b){
			int k = a;
			a = b;
			b = k;
		}

		int c = 0;

		b -= 12;

		for (int i = a; i <= b; i++){
			if (i>2 && !(i % 2))continue;
			if (!iP(i))continue;
			if (!iP(i+6))continue;
			if (!iP(i+12))continue;
			c++;
			printf("%d: %d-%d-%d\n", c, i, i + 6, i + 12);
		}

		if (!c)printf("No Sexy Prime Triplets!\n");
	}
}