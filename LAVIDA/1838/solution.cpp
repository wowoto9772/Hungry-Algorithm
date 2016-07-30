#include <stdio.h>
#include <limits.h>

#define min(a,b) a < b ? a : b

int nxt(int c){
	int r = 0;
	while (c){
		int a = c % 10;
		r += a*a;
		c /= 10;
	}return r;
}

int ans(int n, int m){
	if (n == m)return 2;
	int p = 0;
	if (n > 810)p++;

	bool chk[81 * 11] = { 0 };
	int top = 0, a[81 * 11] = { 0 };
	int c = n;
	while (true){
		if (c <= 810){
			if (chk[c])break;
			chk[c] = true;
			a[c] = ++top;
		}
		c = nxt(c);
	}

	bool chk2[81 * 11] = { 0 };
	c = m;

	int ans = INT_MAX, x = 0;
	
	while (true){
		x++;
		if (c <= 810){
			if (chk[c])ans = ans < x + a[c] ? ans : x + a[c];
			if (chk2[c])break;
			chk2[c] = true;
		}
		c = nxt(c);
	}

	if(ans < INT_MAX)ans += p;

	if (ans == INT_MAX)ans = 0;
	return ans;
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m){
		printf("%d %d %d\n", n, m, min(ans(n, m), ans(m, n)));
	}
}