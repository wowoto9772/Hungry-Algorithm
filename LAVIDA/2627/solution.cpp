#include <stdio.h>

class ele{
public:
	int p, c;
}I[1003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, w;
		scanf("%d %d", &w, &n);

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &I[i].p, &I[i].c);  // give in order
		}

		int l = 1;
		int p = 0;

		int ans = 0, c = 0;
		int tt = 0;
		while (l <= n){
			ans += I[l].p - p;
			p = I[l].p;
			if (c + I[l].c <= w){
				c += I[l].c;
				if (c == w){
					ans += p;
					p = c = 0;
				}
				l++;
			}
			else{
				ans += p;
				p = c = 0;
				continue;
			}
		}

		if (p)ans += p;

		printf("%d\n", ans);
	}
}