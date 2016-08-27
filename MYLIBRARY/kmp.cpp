#include <stdio.h>

#include <string.h>

#include <string>
#include <vector>

using namespace std;

#define LEN 1000003

char org[LEN], ptn[LEN];
int pi[LEN];
int pl, ol;

void getPi(){

	pi[j][1] = 0;

	for(int i=2; i<=pl[j]; i++){

		while(p && (ptn[p+1] != ptn[i]))p = pi[j][p];
		if(ptn[p+1] == ptn[i])p++;
		pi[i] = p;

	}

}

void getAns(){


	int p = 0;

	for(int i=1; i<=ol; i++){

		while(p && (ptn[j][p+1] != org[i]))p = pi[j][p];
		if(ptn[j][p+1] == org[i])p++;
		if(p == pl[j]){
			// find !
			printf("YES\n");
			return ;
		}


		// cannot find
		printf("NO\n");

	}

}

int main(){

	scanf("%s", ptn+1);
	pl = strlen(ptn+1);

	getPi();

	scanf("%s", org);
	ol = strlen(org);

	getAns();

}
