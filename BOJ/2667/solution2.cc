#include <stdio.h>
#include <algorithm>

using namespace std;

struct ele{
	int r, c;
	ele(){}
	ele(int _r, int _c){ 
        r = _r;
        c=_c; 
    }
};

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

char str[28][28];
bool chk[28][28];
int a[320];

ele q[10003];

int main(){
    
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%s", str[i]);

	int c = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (str[i][j] == '1' && !chk[i][j]){
                int front = 0, tale = 0;
				q[tale++] = ele(i, j);
				chk[i][j] = true;
				int d = 0;                
                
				while (front < tale){
					ele pp = q[front++]; // pop
					d++;
					for (int k = 0; k < 4; k++){
						ele psh = ele(pp.r + dr[k], pp.c + dc[k]);
						if (psh.r < 0 || psh.c < 0 || psh.r >= n || psh.c >= n)continue;
						if (chk[psh.r][psh.c])continue;
						if (str[psh.r][psh.c] == '0')continue;
						chk[psh.r][psh.c] = true;
						q[tale++] = psh; // push
					}
				}

				a[c++] = d;
			}
		}
	}

	printf("%d\n", c);
	sort(a, a + c);

	for (int i = 0; i < c; i++)printf("%d\n", a[i]);
}