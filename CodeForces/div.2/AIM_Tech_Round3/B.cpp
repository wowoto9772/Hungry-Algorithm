#include <stdio.h>
#include <algorithm>

using namespace std;

int p[100003];

int main(){

	int n, s;
	scanf("%d %d", &n, &s);

	for(int i=0; i<n; i++){
		scanf("%d", &p[i]);
	}

	sort(p, p+n);

	if(n == 1)printf("0");
	else{
		int ans = abs(s-p[0]) + (p[n-2]-p[0]);
		ans = min(ans, min(abs(p[n-1]-s), abs(s-p[1])) + (p[n-1]-p[1]));
		ans = min(ans, abs(p[n-2]-s) + (p[n-2]-p[0]));
		printf("%d", ans);
	}

}
