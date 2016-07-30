#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

double x[103], y[103];

class ele{
public:
	int a, b;
	double c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[10003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++){
			scanf("%lf %lf", &x[i], &y[i]);
		}

		int top = 0;
		
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				I[top].a = i, I[top].b = j, I[top].c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				top++;
			}
		}

		sort(I, I + top);

		double ans = 0;
		int c = 0, f = 0;
		int p[103] = { 0 };
		while (c < n - 1 && f < top){
			int A = I[f].a, B = I[f].b;
			double C = I[f].c;
			f++;
			while (p[A])A = p[A];
			while (p[B])B = p[B];
			if (A == B)continue;
			else{
				c++;
				p[A] = B;
				ans = ans < C ? C : ans;
			}
		}

		printf("%.2lf\n", sqrt(ans));
	}
}