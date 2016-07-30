#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int a[1003], b[1003];

class ele{
public:
	int a, b;
	double c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[1000003];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++)scanf("%d %d", &a[i], &b[i]);

		int top = 0;
		int p[1003] = { 0 };

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i != j){
					int x = a[i] - a[j];
					x *= x;
					int y = b[i] - b[j];
					y *= y;

					I[top].a = i, I[top].b = j;
					I[top++].c = sqrt((double)x + y);
				}
			}
		}

		sort(I, I + top);

		double ans = 0;
		int c = 0;

		for (int i = 0; c != n - 1 && i < top; i++){
			int x = I[i].a, y = I[i].b;
			while (p[x])x = p[x];
			while (p[y])y = p[y];
			if (x != y){
				p[x] = y;
				ans += I[i].c;
				c++;
			}
		}

		printf("%.2lf\n", ans);
	}
}