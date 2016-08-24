#include <stdio.h>
#include <limits.h>

#include <string.h>
#include <string>

#include <map>

#include <algorithm>

using namespace std;

char str[23], tmp[23];

int igo[203];

int d[203][203][2];

int main(){

	int n, pay[2] = {0,};
	scanf("%d %d", &n, &pay[1]);
	pay[1] <<= 1;

	map <string, int> city;

	for(int i=1; i<=n; i++){
		scanf("%s", str);
		city[(string)str] = i;
		for(int j=1; j<=n; j++){
			d[i][j][0] = d[i][j][1] = INT_MAX;
		}
		d[i][i][0] = d[i][i][1] = 0;
	}

	int q;
	scanf("%d", &q);

	for(int i=1; i<=q; i++){
		scanf("%s", str);
		igo[i] = city[string(str)];
	}

	int m;
	scanf("%d", &m);

	while(m--){
		scanf("%s", str);

		int a, b;

		scanf("%s", tmp);
		a = city[string(tmp)];

		scanf("%s", tmp);
		b = city[string(tmp)];

		int c;
		scanf("%d", &c);

		c<<=1;

		if(!strcmp(str, "Mugunghwa") || !strcmp(str, "ITX-Cheongchun") || !strcmp(str, "ITX-Saemaeul")){
			d[a][b][1] = d[b][a][1] = 0;
			d[a][b][0] = d[b][a][0] = min(d[a][b][0], c);			
		}else if(!strcmp(str, "S-Train") || !strcmp(str, "V-Train")){
			d[a][b][1] = d[b][a][1] = min(d[a][b][1], c>>1);
			d[a][b][0] = d[b][a][0] = min(d[a][b][0], c);
		}else{
			for(int i=0; i<2; i++){
				d[a][b][i] = d[b][a][i] = min(d[a][b][i], c);
			}
		}
	}

	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int t=0; t<2; t++){
					if((d[i][k][t] | d[k][j][t]) == INT_MAX)continue;
					d[i][j][t] = min(d[i][j][t], d[i][k][t] + d[k][j][t]);
				}
			}
		}
	}

	int tot[2] = {0};

	for(int i=0; i<2; i++){
		tot[i] = pay[i];
		for(int j=1; j<q; j++){
			tot[i] += d[igo[j]][igo[j+1]][i];
		}
	}

	if(tot[0] > tot[1])printf("Yes");
	else
		printf("No");

}
