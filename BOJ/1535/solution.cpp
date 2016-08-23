#include <stdio.h>
#include <algorithm>

using namespace std;

int u[23];
int g[23];

int main(){
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++)scanf("%d", &u[i]);
	for(int i=0; i<n; i++)scanf("%d", &g[i]);

	int ans = 0;

	for(int i=1; i<(1<<n); i++){

		int hp = 100;
		int x = 0;

		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				hp -= u[j];
				x += g[j];
			}
		}

		if(hp > 0)ans = max(ans, x);
	}

	printf("%d\n", ans);

}
