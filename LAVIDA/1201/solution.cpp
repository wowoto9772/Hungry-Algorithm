#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

char inp[205];
string str[3002];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++){
			scanf("%s", inp);
			str[i] = string(inp);
		}

		sort(str, str + n); // O( nm log (n*m) )

		for (int k = 1; k <= m; k++){
			int cmp = -1, c = 0;
			int max = 0, maxx = -1;
			for (int i = 0; i < n; i++){
				if (str[i].size() >= k){
					if (cmp == -1){
						cmp = i;
						c = 1;
					}
					else if (str[cmp].substr(0, k) == str[i].substr(0, k)){
						c++;
					}
					else{
						if (max < c){
							max = c;
							maxx = cmp;
						}
						cmp = i;
						c = 1;
					}
				}
			}
			if (max < c){
				max = c;
				maxx = cmp;
			}

			printf("%s\n", str[maxx].substr(0, k).c_str());
		}
	}
}