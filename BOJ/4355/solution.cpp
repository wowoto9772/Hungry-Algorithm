#include <stdio.h>
#include <vector>

using namespace std;

int main(){

	int n;
	while (scanf("%d", &n) == 1 && n){

		int tot = n;

		vector <int> p;
		for (int i = 2; i*i <= n; i++){
			if (n%i)continue;
			p.push_back(i);
			while (!(n%i)){
				n /= i;
			}
		}

		if (n != 1)p.push_back(n);

		n = tot;

		int lim = 1 << (p.size());

		for (int i = 1; i < lim; i++){
			int g = 1;
			int flg = 0;
			for (int j = 0; j < p.size(); j++){
				if (i&(1 << j)){
					g *= p[j];
					flg++;
				}
			}

			tot -= n / g * ((flg%2) ? 1 : -1);
		}

		printf("%d\n", tot);

	}

}