#include <stdio.h>

bool p[50];
int P[50];
int top;

int main(){
	int nxt;

	for (int i = 2; i*i < 50; i++){
		nxt = i;
		if (!p[i]){
			P[top++] = i;
			for (int j = i + i; j < 50; j += i){
				p[j] = true;
			}
		}
	}for (int i = nxt + 1; i < 50; i++)if (!p[i])P[top++] = i;

	int t;
	while (scanf("%d", &t) == 1){

		while (t--){
			int n, k;
			scanf("%d %d", &n, &k);
			k = n - k > k ? k : n - k;

			int s[50] = { 0 };

			for (int i = 1; i <= k; i++){
				int x = n--, y = i;
				for (int j = 0; j < top; j++){
					if (P[j] > x && P[j] > y)break;
					while (!(x%P[j])){
						s[j]++;
						x /= P[j];
					}
					while(!(y%P[j])){
						s[j]--;
						y /= P[j];
					}
				}
			}

			long long m = 1;
			for (int i = 0; i < top; i++){
				while (s[i]){
					s[i]--;
					m *= P[i];
				}
			}

			printf("%lld\n", m);
		}
	}

}