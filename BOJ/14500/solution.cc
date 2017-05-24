#include <cstdio>
#include <vector>

using namespace std;

vector < pair<int,int> > my;
int e[503][503];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
bool chk[503][503];

int max(int a, int b){
	if(a > b)return a;
	return b;
}

int ans, n, m;

void dfs(int r){
	if(r == 0){
		int tmp = 0;
		for(auto &x : my)tmp += e[x.first][x.second];
		ans = max(ans, tmp);
		return ;
	}
	for(auto &x : my){
		for(int i=0; i<4; i++){
			pair <int,int> y = {x.first + dr[i], x.second + dc[i]};
			if(y.first < 1 || y.second < 1 || y.first > n || y.second > m)continue;
			if(chk[y.first][y.second])continue;
			chk[y.first][y.second] = true;
			my.emplace_back(y.first, y.second);
			
			dfs(r-1);
			
			chk[y.first][y.second] = false;
			my.pop_back();
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &e[i][j]);
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			chk[i][j] = true;
			my.emplace_back(i, j);
			dfs(3);
			chk[i][j] = false;
			my.pop_back();
		}
	}
	
	printf("%d\n", ans);
	
}