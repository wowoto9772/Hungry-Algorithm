#include <stdio.h>

#include <string.h>

#include <string>
#include <vector>

using namespace std;

char org[10003], ptn[1003][103];
int pn;
int pi[1003][103];
int pl[1003], ol;

void getPi(){

	for(int j=1; j<=pn; j++){

		int p = 0;

		pi[j][1] = 0;

		for(int i=2; i<=pl[j]; i++){

			while(p && (ptn[j][p+1] != ptn[j][i]))p = pi[j][p];
			if(ptn[j][p+1] == ptn[j][i])p++;
			pi[j][i] = p;

		}
	}

}

void getAns(){

	for(int j=1; j<=pn; j++){

		int p = 0;

		for(int i=1; i<=ol; i++){

			while(p && (ptn[j][p+1] != org[i]))p = pi[j][p];
			if(ptn[j][p+1] == org[i])p++;
			if(p == pl[j]){
				printf("YES\n");
				return ;
			}

		}

	}

	printf("NO\n");

}

int main(){

	scanf("%d", &pn);

	for(int i=1; i<=pn; i++){
		scanf("%s", ptn[i]+1);
		pl[i] = strlen(ptn[i]+1);
	}

	getPi();

	int q;
	scanf("%d", &q);

	while(q--){
		scanf("%s", org+1);
		ol = strlen(org+1);
		getAns();
	}

}
