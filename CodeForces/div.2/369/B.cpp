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

	p[n] = s;

	sort(p, p+1+n);

	int x = 0;

	for(int i=0; i<=n; i++){
		if(p[i] == s){
			x = i;
			break;
		}
	}


	long long ri = 0;

	int y = s;
	int z = 0;

	for(int i=x+1; i<=n && z+1 < n; i++){
		ri += p[i] - y;
		y = p[i];
		z++;
	}

	for(int i=x-1; i>=0 && z+1 < n; i--){
		ri += y - p[i];
		y = p[i];
		z++;
	}

	long long le = 0;

	y = s;

	z = 0;

	for(int i=x-1; i>=0 && z+1 < n; i--){
		le += y - p[i];
		y = p[i];
		z++;
	}

	for(int i=x+1; i<=n && z+1 < n; i++){
		le += p[i] - y;
		y = p[i];
		z++;
	}

	printf("%lld\n", min(le, ri));

}
