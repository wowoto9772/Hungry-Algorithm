#include <stdio.h>

int main(){
	int n, p;
	scanf("%d %d", &n, &p);

	int s[102] = { 0 };
	s[0] = 0, s[p + 1] = n;
	for (int i = 1; i <= p; i++)scanf("%d", &s[i]);

	bool c[103] = { 0 };

	for (int i = 0; i <= p; i++){
		for (int j = i + 1; j <= p + 1; j++){
			c[s[j] - s[i]] = true;
		}
	}

	int e = 0;
	for (int i = n; !e && i >= 1; i--){
		if (c[i])e = i;
	}
	for (int i = 1; i <= e; i++){
		if (c[i]){
			printf("%d", i);
			if (i < e)printf(" ");
		}
	}printf("\n");
}