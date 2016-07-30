#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char a[1003], b[1003];

long long gcd(long long a, long long b){
	long long mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s %s", a, b);
		int s = strlen(a);

		map <char, char> par;

		bool flag = false;
		bool used['Z' + 3] = { 0 };

		for (int i = 0; i < s && !flag; i++){
			if (par[a[i]] == b[i])continue;
			else{
				used[a[i]] = used[b[i]] = true;
				if (par[a[i]])flag = true;
				else{
					par[a[i]] = b[i];
				}
			}
		}

		if (flag)printf("mjau\n");
		else{
			int c['Z' + 3] = { 0 };
			for (int i = 'A'; i <= 'Z' && !flag; i++){
				if (used[i]){
					char tmp = i;
					int m = 0;
					while (true){
						tmp = par[tmp];
						if (par[tmp] == 0){
							flag = true;
							break;
						}
						m++;
						if (tmp == i){
							c[i] = m;
							break;
						}
					}
				}
			}

			if (flag)printf("mjau\n");
			else{
				map <int, bool> chk;
				vector <long long> x;
				for (int i = 'A'; i <= 'Z'; i++){
					if (used[i]){
						if (chk[c[i]])continue;
						else{
							chk[c[i]] = true;
							x.push_back(c[i]);
						}
					}
				}

				sort(x.begin(), x.end());

				long long cur = 0;
				for (int i = 0; i < x.size(); i++){
					if (x[i]){
						if (!cur)cur = x[i];
						else{
							long long g = gcd(cur, x[i]);
							cur /= g;
							x[i] /= g;
							cur = cur * x[i] * g;
						}
					}
				}

				printf("%lld\n", cur - 1);
			}
		}
	}
}