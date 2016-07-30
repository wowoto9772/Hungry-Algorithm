#include <stdio.h>

char str[103][103];
char seq[10003];
int n;

bool isPal(int x, int y, int dx, int dy){
	int top = 0;
	while (top < n*n){
		seq[top++] = str[x][y];
		x += dx;
		y += dy;
		if (x == -1 || x == n){
			y++;
			if (x == -1)x = n-1;
			else if (x == n)x = 0;
		}
		else if (y == -1 || y == n){
			x++;
			if (y == -1)y = n-1;
			else if (y == n)y = 0;
		}
	}

	for (int i = 0; i < top / 2; i++){
		if (seq[i] != seq[top - 1 - i])return false;
	}return true;
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++)scanf("%s", str[i]);

		if (isPal(0, 0, 0, 1) || isPal(0, 0, 1, 0))printf("YES\n");
		else
			printf("NO\n");
	}
}