#include <cstdio>
#include <set>

using namespace std;

int s[103][3];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	set <int> p[3];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			scanf("%d", &s[i][j]);
			p[j].insert(s[i][j]);
		}
	}

	int ans = 987654321;
	for (auto &e : p[0]){
		for (auto &f : p[1]){
			for (auto &g : p[2]){
				int c = 0;
				for (int i = 0; i < n; i++){
					if (s[i][0] <= e && s[i][1] <= f && s[i][2] <= g){
						c++;
						if (c == k)break;
					}
				}
				if (c == k && ans > e+f+g)ans = e+f+g;
			}
		}
	}

	printf("%d\n", ans);

}