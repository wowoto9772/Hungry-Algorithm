#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

int x[4] = { -2, -1, 1, 2 };

class ele{
public:
	int A, C;
	char str[110];
};

void swp(char *a, char *b){
	int t = *a;
	*a = *b;
	*b = t;
}

bool isBWB(char str[]){
	int s = strlen(str);

	for (int i = 0; i < s; i++){
		if (str[i] == 'W'){
			int l = i - 1, r = i + 1;
			bool L = false, R = false;
			while (l >= 0){
				if (str[l] == 'B'){
					L = true;
					break;
				}
				else{
					l--;
				}
			}
			while (r < s){
				if (str[r] == 'B'){
					R = true;
					break;
				}
				else{
					r++;
				}
			}

			if (L && R)return true;
		}
	}return false;
}

int main()
{
	char str[102] = { 0 };
	int T = 1;

	while (scanf("%s", str) == 1 && str[0] != '-'){
		int s = strlen(str);

		queue <ele> F;
		ele psh, pop;

		for (int i = 0; i < s; i++){
			if (str[i] == 'F'){
				psh.A = i, psh.C = 0;
				strcpy(psh.str, str);
				F.push(psh);
			}
		}

		int ans = -1;

		while (!F.empty()){
			if (!isBWB(F.front().str)){
				ans = F.front().C;
				break;
			}
			for (int i = 0; i < 4; i++){
				ele pop = F.front();
				if (pop.C < 9){
					int nf = pop.A + x[i];
					if (0 <= nf && nf < s){
						psh.A = nf;
						psh.C = pop.C + 1;
						swp(&pop.str[nf], &pop.str[pop.A]);
						if (i == 0 || i == 3){
							if (pop.str[pop.A] == 'W')pop.str[pop.A] = 'B';
							else
								pop.str[pop.A] = 'W';
						}
						strcpy(psh.str, pop.str);
						F.push(psh);
					}
				}
			}

			F.pop();
		}

		// transform the given arrangement to an arrangement
		// that has no white tile(s) between any of its black tiles.

		printf("%d. %d\n", T++, ans);
	}
}