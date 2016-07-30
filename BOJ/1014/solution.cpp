#include <stdio.h>
#include <memory.h>

char I[15][15];

int dp[1 << 10][1 << 10][10];
int n, m;

int M(int a, int b){ return a < b ? b : a; }

int dy(int c, int t, int p){
	if (p < 0)return 0;
	if (dp[c][t][p] != -1)return dp[c][t][p];

	dp[c][t][p] = 0;

	dp[c][t][p] = dy(t, 0, p - 1);

	bool flag = false;

	for (int i = 0; i < m; i++){
		if (I[p][i] == 'x')continue;
		if (c & (1 << i))continue;

		int c_ = c, t_ = t;
		c_ |= 1 << i;
		if (i > 0){
			if (I[p][i - 1] != 'x')c_ |= 1 << (i - 1);
			if (p > 0 && I[p - 1][i - 1] != 'x')t_ |= 1 << (i - 1);
		}
		if (i < m - 1){
			if (I[p][i + 1] != 'x')c_ |= 1 << (i + 1);
			if (p > 0 && I[p - 1][i + 1] != 'x')t_ |= 1 << (i + 1);
		}
		dp[c][t][p] = M(dp[c][t][p], 1 + dy(c_, t_, p));
	}

	return dp[c][t][p];
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)scanf("%s", &I[i]);

		memset(dp, 0xff, sizeof(dp));

		printf("%d\n", dy(0, 0, n - 1));
	}
}

/*
#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
int C, N, M;
string bd[100];
int nbx[100][100], nby[100][100], v[100][100];
int T=0;
bool dfs(int a, int b) {
if (a<0) return true;
if(v[a][b]==T) return false;
v[a][b]=T;
for (int i=a-1;i<=a+1;i++) {
for (int j=b-1;j<=b+1;j+=2) {
if (i>=0 && i<M && j>=0 && j<N && bd[i][j]=='.') {
if (dfs(nbx[i][j], nby[i][j])) {
nbx[i][j]=a; nby[i][j]=b;
nbx[a][b]=i; nby[a][b]=j;
return true;
}
}
}
}
return false;
}
int play() {
memset(nbx,-1,sizeof(nbx));
memset(nby,-1,sizeof(nby));
memset(v, -1, sizeof(v)); T=-1;
int rst=0;
for(int i=0;i<M;i++) for(int j=0;j<N;j++) {
if (bd[i][j]=='.') {
rst++;
if (j%2) {
T++;
if (dfs(i,j)) rst--;
}
}
}
return rst;
}
int main() {
cin>>C;
for (int i=1; i<=C; i++) {
cin>>M>>N;
for (int r=0;r<M;r++) cin>>bd[r];
cout<<play()<<endl;
}
return 0;
}
*/