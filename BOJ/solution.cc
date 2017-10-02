#include <cstdio>

using namespace std;

bool chk[6][6];

int main(){

	int n;
	scanf("%d", &n);

	if (n == 3){
		for (int j = 0; j < 3; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			chk[a][b] = chk[b][a] = true;
		}
		if (chk[1][4] && chk[3][4] && chk[1][3]){
			printf("Wa-pa-pa-pa-pa-pa-pow!");
			return 0;
		}
	}

	printf("Woof-meow-tweet-squeek");

}