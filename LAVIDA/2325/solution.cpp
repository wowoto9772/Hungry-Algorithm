#include <stdio.h>
#include <math.h>

double d[1003][1003];
double x[1003], y[1003], r[1003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, w;
		scanf("%d %d", &w, &n);

		for (int i = 1; i <= n; i++){
			scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
			for (int j = 1; j < i; j++){
				d[j][i] = d[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - r[i] - r[j];
			}
		}

		if (n == 0)printf("%.5lf\n", w / 2.0);
		else{
			double lo = 0, hi = 2 * w, m; // m : radius * 2

			int p[1003] = { 0 };
			while (hi - lo > 1e-9){
				m = (lo + hi) / 2.0;

				int left = n + 1, right = n + 2;

				for (int i = 1; i <= n + 2; i++)p[i] = 0; // init

				int a, b;
				bool flag = false;
				for (int i = 1; !flag && i <= n; i++){
					a = b = 0;
					if (x[i] - r[i] - m <= 0){
						a = left, b = i;
					}
					while (p[a])a = p[a];
					while (p[b])b = p[b];
					if (a == left && b == right || a == right && b == left){
						flag = true;
						break;
					}
					if (a != b){
						int pa = a, pb = b;
						a = left, b = i;
						while (p[a]){
							p[a] = pa;
							a = p[a];
						}
						while (p[b]){
							p[b] = pb;
							b = p[b];
						}
						p[b] = a;
					}
					if (x[i] + r[i] + m >= w){
						a = right, b = i;
					}
					while (p[a])a = p[a];
					while (p[b])b = p[b];
					if (a == left && b == right || a == right && b == left){
						flag = true;
						break;
					}
					if (a != b){
						int pa = a, pb = b;
						a = right, b = i;
						while (p[a]){
							p[a] = pa;
							a = p[a];
						}
						while (p[b]){
							p[b] = pb;
							b = p[b];
						}
						p[b] = a;
					}
				}

				for (int i = 1; !flag && i <= n; i++){
					for (int j = 1; !flag && j < i; j++){
						if (d[i][j] <= m){
							a = i, b = j;
							while (p[a])a = p[a];
							while (p[b])b = p[b];
							if (a == left && b == right || a == right && b == left)flag = true;
							if (a != b){
								int pa = a, pb = b;
								a = i, b = j;
								while (p[a]){
									p[a] = pa;
									a = p[a];
								}
								while (p[b]){
									p[b] = pb;
									b = p[b];
								}
								p[a] = b;
							}
						}
					}
				}

				if (flag){
					hi = m;
					continue;
				}
				while (p[left])left = p[left];
				while (p[right])right = p[right];

				if (left == right)hi = m;
				else
					lo = m;
			}
			// the radius of the largest circular object
			printf("%.5lf\n", m / 2.0);
		}
	}
}