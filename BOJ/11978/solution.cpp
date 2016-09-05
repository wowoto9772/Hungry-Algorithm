#include <stdio.h>

#include <algorithm>

using namespace std;

int t[2002][2002];

int main(){

	int n;
	scanf("%d", &n);

	int x = 1000, y = 1000;

	int elp = 0;

	t[x][y] = ++elp;

	int ans = 1003;

	for(int i=1; i<=n; i++){
		
		char cmd;
		int stp;

		scanf(" %c %d", &cmd, &stp);

		int dx = 0, dy = 0;

		if(cmd == 'E'){
			dx++;
		}else if(cmd == 'W'){
			dx--;
		}else if(cmd == 'S'){
			dy--;
		}else
			dy++;

		for(int k=1; k<=stp; k++){

			int nx = x + dx, ny = y + dy;

			elp++;

			if(t[nx][ny]){
				ans = min(ans, elp - t[nx][ny]);
			}

			t[nx][ny] = elp;

			x = nx, y = ny;

		}

	}

	if(ans == 1003)ans = -1;

	printf("%d\n", ans);

}
