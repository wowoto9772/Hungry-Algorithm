#include <cstdio>

using namespace std;

long long height[100003];
long long idx[100003];

int main()
{ 
	int n;
    scanf("%d", &n);

	int top = 1;
	scanf("%lld", &height[1]);
	idx[1] = 1;

	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		long long a;
		scanf("%lld", &a);
		if (height[top] < a) {
            top++;
			height[top] = a;
			idx[top] = i;
		}
		else if (height[top] > a) {
			long long r;
			while (height[top] > a) {
				r = idx[top];
				long long tmp = (i - idx[top]) * height[top];
				ans = ans < tmp ? tmp : ans;
				top--;
			}
			height[++top] = a;
			idx[top] = r;
		}
	}

	while (top != 0) {
		long long tmp = (n - idx[top] + 1) * height[top];
		ans = ans < tmp ? tmp : ans;
		top--;
	}

	printf("%lld\n", ans);
}