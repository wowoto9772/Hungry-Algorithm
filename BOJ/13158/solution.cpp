#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;


vector < int > lnk[26][1003];

char ptn[203];

double dp[1003][203];

int n, p;

double dy(int c, int m){

	
	if(c == n)return 1.0;
	else if(m >= p)return 0.0;

	double &ret = dp[c][m];

	if(ret >= 0.0)return ret;

	ret = 0.0;

	if(lnk[ptn[m]][c].size()){
		for(int i=0; i<lnk[ptn[m]][c].size(); i++){
			ret += dy(lnk[ptn[m]][c][i], (m+1)) / (double)lnk[ptn[m]][c].size();
		}
	}else{
		ret = dy(c, (m+1));
	}

	return ret;


}


int main(){

	int m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		int a, b;
		char x;
		scanf("%d %d %c", &a, &b, &x);
		x -= 'A';
		lnk[x][a].emplace_back(b);
		lnk[x][b].emplace_back(a);
	}

	scanf("%s", ptn);

	p = strlen(ptn);

	for(int i=0; i<p; i++)ptn[i] -= 'A';

	for(int i=1; i<=n; i++){
		for(int j=0; j<p; j++){
			dp[i][j] = -1.0;
		}
	}

	printf("%.8lf\n", dy(1, 0) * 100.0);

}
