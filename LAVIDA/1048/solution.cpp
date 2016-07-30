#include <stdio.h>

int I[23];

double ab(double a){ return a < -a ? -a : a; }

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int s = 0;
		double I_[23] = { 0 };

		for (int i = 1; i <= n; i++){
			scanf("%d", &I[i]);
			I_[i] = I[i];
			s += I[i];
		}

		double s_ = s;
		s_ /= n;

		double min = 10001.0;
		int ans;

		for (int i = 1; i <= n; i++){
			if (ab(I_[i] - s_) < min){
				min = ab(I_[i] - s_);
				ans = i;
			}
		}

		printf("%d\n", I[ans]);
	}
}