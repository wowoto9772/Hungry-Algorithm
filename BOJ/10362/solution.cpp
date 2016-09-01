#include <stdio.h>

#include <string.h>

char str[133];

int chk[66][66];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int x, y;
		scanf("%d %d", &x, &y);

		scanf("%s", str);

		int s = strlen(str);

		for(int i=0; i<64; i++)for(int j=0; j<64; j++)chk[i][j] = 0;

		chk[x][y] = 1;

		int d = 0;

		for(int i=0; i<s; i++){
			if(str[i] == 'F'){
				x += dx[d], y += dy[d];
				chk[x][y]++;
			}else if(str[i] == 'R'){
				d++;
				if(d == 4)d = 0;
			}else if(str[i] == 'L'){
				d--;
				if(d == -1)d = 3;
			}
		}

		int z = 0;
		for(int i=0; i<64; i++)for(int j=0; j<64; j++)if(chk[i][j] > 1)z++;

		printf("Case #%d: %d %d %d\n", ++tc, x, y, z);

	}

}
