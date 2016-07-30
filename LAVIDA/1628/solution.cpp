#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) == 2){
		if (!n && !m)break;

		vector <double> e[12];
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				double entry;
				scanf("%lf", &entry);
				e[j].push_back(entry);
			}
		}

		for (int i = 1; i <= m; i++)sort(e[i].begin(), e[i].end());

		double ans = 0;
		for (int i = 0; i < n; i++){
			double p = 1.0;
			for (int j = 1; j <= m; j++){
				p *= e[j][i];
			}
			ans += p;
		}

		printf("%.4lf\n", ans);
	}
}