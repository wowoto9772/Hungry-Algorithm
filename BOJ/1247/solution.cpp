#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
	int n;
	int t = 3;

	while (t--){

		scanf("%d", &n);
		
		vector <ll> l;
		l.resize(n);

		bool m = false, p = false;
		for (int i = 0; i < n; i++){
			scanf("%lld", &l[i]);
			if (l[i] > 0)p = true;
			if (l[i] < 0)m = true;
		}

		sort(l.begin(), l.end());

		if (m && p){
			int le, ri;
			for (int i = 0; i < n; i++){
				if (l[i] > 0){
					ri = i;
					break;
				}
				if (l[i] < 0){
					le = i;
				}
			}
			while (le >= 0 && ri < n){
				if (l[le] + l[ri] < 0){
					l[le] += l[ri];
					ri++;
				}
				else if (l[le] + l[ri] > 0){
					l[ri] += l[le];
					le--;
				}
				else{
					le--, ri++;
					if (le == -1 && ri == n){
						m = false, p = false;
						break;
					}
				}

				if (le < 0){
					m = false;
					break;
				}
				else if (ri >= n){
					p = false;
					break;
				}

				if (l[ri] < 0){
					if (ri < n - 1){
						l[ri + 1] += l[ri];
						ri++;
					}
					else{
						p = false;
						ri++;
					}
				}
				if (l[le] > 0){
					if (le > 0){
						l[le - 1] += l[le];
						le--;
					}
					else{
						m = false;
						le--;
					}
				}

			}

			if (!m && !p)printf("0\n");
			else if (m)printf("-\n");
			else
				printf("+\n");
		}
		else if (m){
			printf("-\n");
		}
		else if (p){
			printf("+\n");
		}
		else{
			printf("0\n");
		}
	}
}