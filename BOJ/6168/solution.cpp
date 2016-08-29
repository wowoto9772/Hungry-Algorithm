#include <stdio.h>
#include <algorithm>

using namespace std;

int o[30003], t[30003];

int x[30003];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){

		scanf("%d", &x[i]);

		o[i] = o[i-1] + (x[i] == 2);

	}

	for(int i=n; i>=1; i--){
		t[i] = t[i+1] + (x[i] == 1);
	}

	int ans = n;

	for(int i=0; i<=n; i++){

		ans = min(ans, o[i] + t[i+1]);

	}

	printf("%d\n", ans);

}
