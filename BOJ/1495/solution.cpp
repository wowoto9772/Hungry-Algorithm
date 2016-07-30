#include <stdio.h>
#include <memory.h>

int v[103];
bool a[1003];
bool b[1003];

int main(){
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);

	for (int i = 1; i <= n; i++)scanf("%d", &v[i]);

	a[s] = true;

	for (int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		for (int j = 0; j <= m; j++){
			if (a[j]){
				if (j + v[i] <= m)b[j + v[i]] = true;
				if (j - v[i] >= 0)b[j - v[i]] = true;
			}
		}
		if (i != n){
			for (int j = 0; j <= m; j++){
				a[j] = b[j];
			}
		}
		else{
			bool flag = false;
			for (int j = m; !flag && j >= 0; j--){
				if (b[j]){
					printf("%d\n", j);
					flag = true;
				}
			}
			if (!flag)printf("-1\n");
		}
	}
}