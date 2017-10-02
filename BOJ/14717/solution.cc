#include <cstdio>

using namespace std;

int main(){

	double ans = 0;

	int a, b;
	scanf("%d %d", &a, &b);

	int tot = 9 * 17;

	if (a == b){
		printf("%.3lf\n", 1.0 - (double)(10 - a) / tot);
	}
	else{
		int c = (a + b) % 10;
		int d = 0;
		for (int j = 1; j <= 10; j++){
			for (int k = 1; k <= 10; k++){
				if (j == k)continue;
				int x = (j + k) % 10;
				if (c > x){
					if (j == a || k == a || j == b || k == b)d++;
					else
						d += 2;
				}
			}
		}
		printf("%.3lf\n", (double)d / tot);
	}

}