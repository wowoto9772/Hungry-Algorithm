#include <stdio.h>
#include <algorithm>

#include <queue>
#include <vector>

using namespace std;

int d[103][103];

bool cyc[103];

bool chk[103];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)d[i][j] = 103;

	vector < vector <int> > lnk;
	lnk.resize(n+1);

	for(int i=1; i<n; i++){
		
		int x;
		scanf("%d", &x);

		while(x--){

			int y;
			scanf("%d", &y);

			d[i][y] = 1;

			lnk[i].push_back(y);

		}

	}

	for(int k=1; k<=n; k++){

		for(int i=1; i<=n; i++){

			for(int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}

	for(int i=1; i<n; i++){
		if(d[i][i] != 103){
			cyc[i] = true;
		}
	}

	queue <int> q;

	chk[1] = true;
	q.push(1);

	while(!q.empty()){

		int f = q.front();q.pop();

		if(cyc[f]){
			printf("CYCLE");
			return 0;
		}
		
		for(int i=0; i<lnk[f].size(); i++){
			
			int g = lnk[f][i];

			if(chk[g])continue;

			chk[g] = true;
			q.push(g);

		}

	}

	printf("NO CYCLE");

}
