#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

int e[300003];
int v[300003];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for(int i=0; i<n; i++)scanf("%d", &e[i]);

	int tot = e[n-1] - e[0];

	for(int i=0; i<n; i++){
		v[i] = e[i+1] - e[i];
	}

	sort(v, v+n-1);

	for(int i=n-2; i>(n-2-(k-1)); i--)tot -= v[i];

	printf("%d\n", tot);

}
