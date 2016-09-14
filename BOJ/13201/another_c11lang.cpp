#include <stdio.h>

#include <string.h>

#include <limits.h>

#include <math.h>

#include <vector>

#include <algorithm>

using namespace std;

char str[103][5];

int c[103][103];

double dp[103][1003];

double logv[103][103];


int n, m;

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &n, &m);

		int src = -1;

		for(int i=0; i<n; i++){
			scanf("%s", str[i]);
			if(strcmp(str[i], "ICN") == 0)src = i;
		}

		for(int i=0; i<n; i++){

			int tot = 0;

			for(int j=0; j<n; j++){
				scanf("%d", &c[i][j]);
				tot += c[i][j];
			}

			for(int j=0; j<n; j++){
				if(c[i][j]){
					logv[i][j] = ( log((double)c[i][j]) - log((double)tot) );
				}else{
					logv[i][j] = ( log(0.0) );
				}
			}

		}

		for(int i=0; i<n; i++)for(int j=0; j<=m; j++)dp[i][j] = log(0.0);

		dp[src][0] = 0.0;

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(dp[k][i+1] < dp[j][i] + logv[j][k]){
						dp[k][i+1] = dp[j][i] + logv[j][k];
					}
				}
			}
		}

		double maxi = log(0.0);

		int fin = -1;

		for(int i=0; i<n; i++){

			if(maxi < dp[i][m]){
				maxi = dp[i][m];
				fin = i;
			}

		}

		printf("%s\n", str[fin]);

	}

}
