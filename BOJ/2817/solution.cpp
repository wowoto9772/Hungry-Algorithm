#include <stdio.h>
#include <vector>

using namespace std;

char w[13];

vector <double> rnk[13];

int main(){
	int top = 0;

	int t, n;
	scanf("%d %d", &t, &n);

	int c['Z' + 3];
	for (int i = 'A'; i <= 'Z'; i++)c[i] = -1;

	for (int i = 0; i < n; i++){
		int a;
		scanf(" %c %d", &w[i], &a);

		if (t * 0.05 <= a){
			c[w[i]] = 0;
			for (int j = 14; j >= 1; j--){
				rnk[i].push_back((double)a / j);
			}
		}
	}

	for (int i = 0; i < 14; i++){
		double Max = 0.0;
		int ind = -1;

		for (int j = 0; j < n; j++){
			if (!rnk[j].empty()){
				if (Max < rnk[j].back()){
					Max = rnk[j].back();
					ind = j;
				}
			}
		}

		if (ind != -1){
			c[w[ind]]++;
			rnk[ind].pop_back();
		}
	}

	for (int i = 'A'; i <= 'Z'; i++)if(c[i] >= 0)printf("%c %d\n", i, c[i]);
}