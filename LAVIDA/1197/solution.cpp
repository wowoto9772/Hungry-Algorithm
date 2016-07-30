#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

char str[1003];
char ans2[1003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		double ans = 0;

		for (int i = 1; i <= n; i++){
			scanf("%s", str);
			int s = strlen(str);

			int c = 0, m = 0;
			for (int j = 0; j < s; j++){
				if (str[j] >= 'a')c++;
				else {
					m++;
				}
			}

			double g = (log(26.0) / log(10.0)) * c + m;
			// logx = log_e(x)
			if (ans < g){
				ans = g;
				strcpy(ans2, str);
			}
			else if (fabs(ans-g) < 1e-9){
				if (strcmp(ans2, str) > 0){
					strcpy(ans2, str);
				}
			}
		}

		printf("%s\n", ans2);
	}
}