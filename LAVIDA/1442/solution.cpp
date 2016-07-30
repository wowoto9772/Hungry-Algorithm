#include <stdio.h>
#include <vector>

using namespace std;

int GCD(int n, int k){
	vector <int> p, c;
	for (int i = 2; i*i <= k; i++){
		if (k%i)continue;
		else{
			p.push_back(i);
			c.push_back(1);
			int s = c.size();
			k /= i;
			while (!(k%i)){
				k /= i;
				c[s-1]++;
			}
		}
	}

	if (k > 1){
		p.push_back(k);
		c.push_back(1);
	}

	int ans = 1;

	for (int i = 0; i < p.size(); i++){
		int s = 0;
		long long x = p[i];
		while (x <= n){
			s += n / x;
			x *= p[i];
		}
		s = s > c[i] ? c[i] : s;
		for (int j = 0; j < s; j++)ans *= p[i];
	}

	return ans;
}

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) == 2){
		printf("%d\n", GCD(n, k));
	}
}