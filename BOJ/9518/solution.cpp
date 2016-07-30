#include <stdio.h>
#include <algorithm>

using namespace std;

char str[55][55];

int dr[] = { 0, 0, 1, 1, -1, -1, 1, -1 };
int dc[] = { -1, 1, 1, -1, 1, -1, 0, 0 };

int main(){
	int r, c;
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++){
		scanf("%s", str[i] + 1);
	}

	int ans = 0, max2 = 0;
	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			int cnt = 0;
			for (int k = 0; k < 8; k++){
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (str[nr][nc] == 'o'){
					cnt++;
				}
			}
			if (str[i][j] == 'o'){
				ans += cnt;
			}
			else{
				max2 = max(max2, cnt);
			}
		}
	}

	printf("%d\n", ans / 2 + max2);
}