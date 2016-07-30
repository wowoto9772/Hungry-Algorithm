#include <stdio.h>
#include <algorithm>

using namespace std;

bool mv[10003];
int c[53];
int w[10003];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &c[i]);

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++){
		scanf("%d", &w[i]);
	}

	sort(c, c + n);
	sort(w, w + m);

	int ans = 0;

	while (true){
		int f = n - 1;
		bool proc = false;
		bool ex = true;
		for (int j = m - 1; j >= 0; j--){
			if (mv[j])continue;
			ex = false;
			if (c[f] >= w[j]){
				f--;
				mv[j] = true;
				proc = true;
				if (f == -1){
					break;
				}
			}
		}
		if (ex)break;
		else if (!proc){
			ans = -1;
			break;
		}
		else{
			ans++;
		}
	}

	printf("%d\n", ans);
}