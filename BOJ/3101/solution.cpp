#include <stdio.h>

#define ll long long
#define min(a, b) (a < b ? a : b)

/*
2 7 16 29
5 9 13 (2 ... 2k-2)
*/

ll odd[200003];
ll even[200003];
char str[300003];

int main(){
	ll n, k;
	scanf("%lld %lld", &n, &k);

	int add = 1;
	odd[1] = 1;
	for (int i = 3; i <= n+1; i += 2){ // (x, y) : x+y odd (left bot + 1)
		odd[i] = odd[i-2] + add;
		//even[i - 1] = odd[i] - 1;
		add += 4;
	}
	odd[2*n+1] = n*n + 1;	
	add = 3;
	//even[2*n] = n*n
	for (int i = 2 * n - 1; i > n+1; i -= 2){
		odd[i] = odd[i+2] - add;
		//even[i-1] = odd[i] + 1
		add += 4;
	}

	even[0] = 0;
	add = 1;
	for (int i = 2; i <= n; i += 2){
		even[i] = even[i - 2] + add;
		add += 4;
	}
	even[2 * n + 2] = n*n - 1;
	add = -1;
	for (int i = 2 * n; i > n; i -= 2){
		even[i] = even[i + 2] - add;
		add += 4;
	}

	int x = 1, y = 1;
	scanf("%s", str);

	ll ans = 1;
	for (int i = 0; i < k; i++){
		if (str[i] == 'D')x++;
		else if (str[i] == 'U')x--;
		else if (str[i] == 'L')y--;
		else if (str[i] == 'R')y++;

		if ((x + y) % 2){
			ans += odd[x + y] + min(x-1, n-y);
		}
		else{
			int c = 0;
			ans += even[x + y] - min(x-1, n-y);
		}
	}

	printf("%lld\n", ans);
}