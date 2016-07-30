#include <stdio.h>

bool rem[1003];
int jmp[1003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &jmp[i]);
	}

	int s = 1;
	bool end = false;

	int t = n;
	while (t--){
		int k = jmp[s];
		printf("%d ", s);
		rem[s] = true;

		int end = 0;
		while (k && end < n*n){
			if (k < 0){
				s--;
				if (s == 0)s = n;
				if (!rem[s])k++;
				else{
					end++;
					continue;
				}
			}
			else{
				s++;
				if (s == n + 1)s = 1;
				if (!rem[s])k--;
				else{
					end++;
					continue;
				}
			}
		}
	}
}