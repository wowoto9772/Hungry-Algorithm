#include <stdio.h>
#include <algorithm>

using namespace std;

double s[101];

int main()
{
	int n, m, k, a;
	double b;
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			scanf("%d %lf", &a, &b);
			if(s[a] < b)s[a] = b;
		}
	}

	sort(s+1, s+n+1);

	double ans = 0;
	for(int i=n; i>=1 && k; i--){
		ans += s[i];
		k--;
	}
	printf("%.1lf\n", ans);
}
