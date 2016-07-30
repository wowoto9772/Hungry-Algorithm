#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[505];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%s", str);

		int s = strlen(str);
		int mx = 0, Mx = 0, my = 0, My = 0;
		int d = 0;
		int cx = 0, cy = 0;

		for (int i = 0; i < s; i++){
			if (str[i] == 'L'){
				d--;
				if (d < 0)d += 4;
			}
			else if (str[i] == 'R'){
				d++;
				if (d > 3)d -= 4;
			}
			else{
				int nx, ny;
				if (str[i] == 'F'){
					nx = cx + dx[d];
					ny = cy + dy[d];
				}
				else{
					nx = cx - dx[d];
					ny = cy - dy[d];
				}
				cx = nx;
				cy = ny;
			}
			mx = min(cx, mx);
			my = min(cy, my);
			Mx = max(cx, Mx);
			My = max(cy, My);
		}
		printf("%d\n", (Mx - mx) * (My - my));
	}
}