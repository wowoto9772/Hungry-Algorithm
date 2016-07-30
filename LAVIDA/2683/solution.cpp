#include <stdio.h>
#include <string.h>

#include <string>
#include <map>

#define max(a,b) (a<b?b:a)

using namespace std;

char str[103][20 * 15 + 30];

int say[103];
bool hear[103][203];
bool conv[103][103];

bool v[103];
int n;
int cnt(int c){
	v[c] = true;
	int r = 1;
	for (int i = 1; i <= n; i++){
		if (v[i])continue;
		if (conv[c][i] && conv[i][c])r += cnt(i);
	}return r;
}

int main(){
	int t;
	scanf("%d", &t);

	n = t;

	map <string, int> lang;

	int top = 0;

	while (t){
		while (!strcmp(str[t], ""))gets(str[t]);

		int s = strlen(str[t]);

		string x;
		int conc = 0; // concept
		for (int i = 0; i < s; i++){
			if (str[t][i] == ' '){
				conc++;
				if (conc > 1){
					int id = 0;
					// hear
					if (!lang[x]){
						lang[x] = ++top;
					}
					id = lang[x];
					if (conc == 2){ // also speak
						say[t] = id;
					}
					hear[t][id] = true;
				}
				x = "";
			}
			else{
				x += str[t][i];
				if (i == s - 1){
					conc++;
					if (conc > 1){
						int id = 0;
						// hear
						if (!lang[x]){
							lang[x] = ++top;
						}
						id = lang[x];
						if (conc == 2){ // also speak
							say[t] = id;
						}
						hear[t][id] = true;
					}
					x = "";
				}
			}
		}
		t--;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j)continue;
			for (int k = 1; k <= top; k++){
				if (hear[j][say[i]]){
					conv[i][j] = true;
				}
			}
		}
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				conv[i][j] |= conv[i][k] & conv[k][j];
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++){
		if (!v[i]){
			int g = cnt(i);
			ans = max(ans, g);
		}
	}

	printf("%d\n", n - ans);
}