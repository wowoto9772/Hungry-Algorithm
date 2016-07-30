#include <stdio.h>
#include <math.h>

int x[205], y[205], r[205];
int p[205];

int main(){
	int n;
	scanf("%d", &n);

	int left = 1, right = 2;

	int k = 2, a, b;
	int pa, pb;

	bool end = false;

	for (int i = 3; i <= n + 2; i++){
		scanf("%d %d %d", &x[i], &y[i], &r[i]);

		if (end)continue;

		if (x[i] - r[i] < 0){
			a = left;
			while (p[a])a = p[a];
			p[a] = i;
		}
		if (x[i] + r[i] > 200){
			a = right;
			while (p[a])a = p[a];

			b = i;
			while (p[b])b = p[b];
			if (a != b){
				p[a] = b;
			}
		}
		for (int j = 3; j < i; j++){
			int d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			double d_ = sqrt((double)d);

			if (d_ - r[i] - r[j] < 0.0){
				a = j;
				while (p[a])a = p[a];

				if (a != i){
					p[a] = i;
				}
			}
		}

		a = left, b = right;
		while (p[a])a = p[a];
		while (p[b])b = p[b];

		if (a == b){
			end = true;
		}
		else{
			k = i;
		}
	}

	printf("%d\n", k - 2);
}