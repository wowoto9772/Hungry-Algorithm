#include <stdio.h>
#include <algorithm>

using namespace std;

int t[4];
int s[1003][4];
int c[4][4];

int cnt[4];

int main(){

	int t[] = {0, 1, 2, 3};

	int n;
	scanf("%d", &n);

	int k = 3;

	for(int i=1; i<=n; i++){

		int a;
		scanf("%d", &a);

		cnt[a]++;

		for(int j=1; j<=k; j++){
			s[i][j] = s[i-1][j] + (a == j);
		}

	}

	int ans = n;

	int l = 0, r = 0;

	for(int i=1; i<=k; i++){

		l = r + 1;
		r += cnt[t[i]];
		for(int j=1; j<=k; j++){
			c[j][t[i]] = s[r][j] - s[l-1][j]; // l to r
		}

	}

	int _2ex = 0, _3ex = 0;

	for(int i=1; i<k; i++){
		for(int j=i+1; j<=k; j++){
			int cur = min(c[i][j], c[j][i]);
			_2ex += cur;
			c[i][j] -= cur;
			c[j][i] -= cur;
		}
	}

	for(int i=1; i<k; i++){
		for(int j=i+1; j<=k; j++){
			_3ex += c[i][j] + c[j][i];
		}
	}

	_3ex = _3ex * 2 / 3;

	ans = min(ans, _2ex + _3ex);

	printf("%d\n", ans);

}
