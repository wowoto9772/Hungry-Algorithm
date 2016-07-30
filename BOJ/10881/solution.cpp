#include <stdio.h>
#include <limits.h>

void swp(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int M(int a, int b){ return a < b ? b : a; }
int m(int a, int b){ return a < b ? a : b; }

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int w[3], h[3];
		int cw[3], ch[3];
		for (int i = 0; i < 3; i++){
			scanf("%d %d", &w[i], &h[i]);
			cw[i] = w[i];
			ch[i] = h[i];
		}

		int ans = INT_MAX;
		for (int i = 0; i <= 1; i++){
			swp(&cw[0], &ch[0]);
			for (int j = 0; j <= 1; j++){
				swp(&cw[1], &ch[1]);
				for (int k = 0; k <= 1; k++){
					swp(&cw[2], &ch[2]);
					// |||
					int Mh = M(ch[0], M(ch[1], ch[2]));
					int Mw = cw[0] + cw[1] + cw[2];
					ans = m(ans, Mh*Mw);
					// |=
					// 0
					Mw = cw[0] + M(cw[1], cw[2]);
					Mh = M(ch[0], ch[1] + ch[2]);
					ans = m(ans, Mh*Mw);
					// 1
					Mw = cw[1] + M(cw[0], cw[2]);
					Mh = M(ch[1], ch[0] + ch[2]);
					ans = m(ans, Mh*Mw);
					// 2
					Mw = cw[2] + M(cw[0], cw[1]);
					Mh = M(ch[2], ch[0] + ch[1]);
					ans = m(ans, Mh*Mw);
				}
			}
		}

		printf("%d\n", ans);
	}
}