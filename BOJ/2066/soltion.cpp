#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#define FOR(a,b,c) for(int a=b; a<=c; a++)

using namespace std;

string card[10][5];
double dp[5][5][5][5][5][5][5][5][5];

double dy(int a, int b, int c, int d, int e, int f, int g, int h, int i){
	if (dp[a][b][c][d][e][f][g][h][i] >= 0.0)return dp[a][b][c][d][e][f][g][h][i];
	
	int s[10] = { 0 };
	s[1] = a, s[2] = b, s[3] = c;
	s[4] = d, s[5] = e, s[6] = f;
	s[7] = g, s[8] = h, s[9] = i;

	int z = 0;
	dp[a][b][c][d][e][f][g][h][i] = 0.0;

	for (int x = 1; x <= 8; x++){
		if (!s[x])continue;
		for (int y = x + 1; y <= 9; y++){
			if (!s[y])continue;
			if (card[x][s[x]][0] == card[y][s[y]][0]){
				z++;
				int ns[10] = { 0 };
				for (int w = 1; w <= 9; w++)ns[w] = s[w];
				ns[x]--, ns[y]--;

				dp[a][b][c][d][e][f][g][h][i] += dy(ns[1], ns[2], ns[3], ns[4], ns[5], ns[6], ns[7], ns[8], ns[9]);
			}
		}
	}

	if (z == 0)dp[a][b][c][d][e][f][g][h][i] = 0.0;
	else{
		dp[a][b][c][d][e][f][g][h][i] /= (double)z;
	}

	return dp[a][b][c][d][e][f][g][h][i];
}

int main(){
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 4; j++){
			cin >> card[i][j];
		}
	}

	FOR(a, 0, 4)FOR(b, 0, 4)FOR(c, 0, 4)FOR(d, 0, 4)FOR(e, 0, 4)FOR(f, 0, 4)FOR(g, 0, 4)FOR(h, 0, 4)FOR(i, 0, 4)dp[a][b][c][d][e][f][g][h][i] = -0.5;
	dp[0][0][0][0][0][0][0][0][0] = 1.0;

	printf("%.6lf\n", dy(4, 4, 4, 4, 4, 4, 4, 4, 4));

	/*
	각 그룹의 제일 위에 있는 카드만을 들어낼 수 있다. 
	또한 아무렇게나 들어낼 수 있는 것이 아니라, 
	숫자가 같은 경우만 들어낼 수 있다.
	카드는 밑에서 위로 주어진다.
	*/
}