#include <cstdio>

using namespace std;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int e[103][103];
int t[103][103];

int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i=0; i<n; i++)for(int j=0; j<n; j++)t[i][j] = -1; // head first
	
	for(int i=1; i<=k; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		r--, c--;
		e[r][c] = 1;
	}
	
	int l;
	scanf("%d", &l);
	
	int ans = 0;
	
	int cr = 0, cc = 0, cd = 0, cl = 1;
	
	bool flag = false;

	for(int i=1; i<=l; i++){
		int m;
		char d;
		scanf("%d %c", &m, &d);
		
		while(ans < m && !flag){
			ans++;
			int nr = cr + dr[cd], nc = cc + dc[cd];
			if(nr < 0 || nr >= n || nc < 0 || nc >= n || ans-t[nr][nc] <= cl){
				flag = true;
			}
			t[nr][nc] = ans;
           	cl += e[nr][nc];
           	e[nr][nc] = 0;	
			cr = nr, cc = nc;
		}
		
		if(d == 'L')cd--;
		else
			cd++;
		cd = (cd+4) % 4;
	}
	
	while(!flag && ans++){
		int nr = cr + dr[cd], nc = cc + dc[cd];
		if(nr < 0 || nr >= n || nc < 0 || nc >= n || ans-t[nr][nc] <= cl){
			flag = true;
		}
		t[nr][nc] = ans;
       	cl += e[nr][nc];
      	e[nr][nc] = 0;	
		cr = nr, cc = nc;
	}
	
	printf("%d\n", ans);

}