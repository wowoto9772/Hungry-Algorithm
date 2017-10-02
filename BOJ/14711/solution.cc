#include <cstdio>
#include <cstring>

using namespace std;

char str[1003][1003];
int c[1003][1003];
int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)for (int j = 0; j < n; j++)str[i][j] = '.';
	scanf("%s", str[0]);

	for (int i = 0; i < n; i++){
		if (str[0][i] == '#'){
			for (int k = 0; k < 4; k++){
				int nr = 0 + dr[k], nc = i + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n)continue;
				c[nr][nc] ^= 1;
			}
		}
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			if (c[i - 1][j]){
				str[i][j] = '#';
				for (int k = 0; k < 4; k++){
					int nr = i + dr[k], nc = j + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= n)continue;
					c[nr][nc] ^= 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)printf("%s\n", str[i]);

}