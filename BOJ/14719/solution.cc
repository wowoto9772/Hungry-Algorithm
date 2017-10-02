#include <cstdio>
#include <algorithm>

using namespace std;

int e[503];

int main(){

	int h, w;
	scanf("%d %d", &h, &w);

	for (int i = 1; i <= w; i++)scanf("%d", &e[i]);

	int ans = 0;
	for (int i = 1; i <= w; i++){
		int p = i;
		for (int j = i + 1; j <= w; j++){
			if (e[i] <= e[j]){
				p = j;
				break;
			}
		}
		if (p != i){
			for (int k = p - 1; k > i; k--){
				ans += e[i] - e[k];
			}
			i = p - 1;
		}
		else{
			int h = 0, q = i;
			for (int j = i + 1; j <= w; j++){
				if (h < e[j])h = e[j], q = j;
			}
			for (int k = q - 1; k > i; k--){
				ans += e[q] - e[k];
			}
			if (q != i)i = q - 1;
		}
	}

	printf("%d\n", ans);

}