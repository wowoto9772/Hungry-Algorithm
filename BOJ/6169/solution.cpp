#include <stdio.h>

int main(){

	int t, m, u, f, d;
	scanf("%d %d %d %d %d", &t, &m, &u, &f, &d);

	int cur = 0;
	int ans = 0;

	bool imp = false;

	for(int i=1; i<=m; i++){

		char x;
		scanf(" %c", &x);

		if(imp)continue;

		if(x == 'u' || x == 'd'){
			cur += (u+d);
			if(cur > t){
				imp = true;
				continue;
			}
		}else{
			cur += f<<1;
			if(cur > t){
				imp = true;
				continue;
			}
		}

		ans = i;
	}

	printf("%d\n", ans);

}
