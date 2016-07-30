#include <stdio.h>
#include <set>

using namespace std;

int I[103][103];
int J[103][103];

int gcd(int a, int b){

	int m = 1;
	while (m){

		m = a % b;
		a = b;
		b = m;

	}

	return a;
}

int dr[] = { -1, -1, -1 , 0, 0, 0, 1, 1, 1 };

int dc[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main(){

	int w, h, b;
	scanf("%d %d %d", &h, &w, &b);

	for (int i = 1; i <= w; i++){
		for (int j = 1; j <= h; j++){
			scanf("%d", &I[i][j]);
		}
	}

	int n = b;

	while (b--){

		for (int i = 0; i <= w + 1; i++)I[i][0] = I[i][h], I[i][h + 1] = I[i][1];
		for (int i = 0; i <= h + 1; i++)I[0][i] = I[w][i], I[w + 1][i] = I[1][i];

		I[0][0] = I[w][h];
		I[0][h + 1] = I[w][1];
		I[w + 1][h + 1] = I[1][1];
		I[w + 1][0] = I[1][h];

		for (int i = 1; i <= w; i++){
			for (int j = 1; j <= h; j++){
				
				J[i][j] = 0;
				
				for (int k = 0; k < 9; k++){
					J[i][j] += I[i + dr[k]][j + dc[k]];
				}

			}
		}

		for (int i = 1; i <= w; i++){
			for (int j = 1; j <= h; j++){
				I[i][j] = J[i][j];
			}
		}

	}

	set <int> q;
	for (int i = 1; i <= w; i++){
		for (int j = 1; j <= h; j++){
			q.insert(I[i][j]);
		}
	}

	printf("%d\n", q.size());

}