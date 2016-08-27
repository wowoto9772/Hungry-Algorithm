#include <stdio.h>
#include <algorithm>

using namespace std;

int c[103];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		scanf("%d", &c[i]);
	}

	sort(c, c+n);

	int ans = 0;

	for(int i=0; i<n && c[i] <= m; i++){
		for(int j=i+1; j<n && c[i] + c[j] <= m; j++){
			for(int k=j+1; k<n && c[i] + c[j] + c[k] <= m; k++){
				ans = max(ans, c[i] + c[j] + c[k]);
			}
		}
	}

	printf("%d\n", ans);

}
