#include <stdio.h>

#include <string.h>

#include <string>
#include <vector>

using namespace std;

// pattern's pi function

#define LMAX 1000003

char org[LMAX], ptn[LMAX];
int pi[LMAX];

int pl, ol;

void getPi(){

	int p = 0;
	pi[1] = 0;

	for(int i=2; i<=pl; i++){

		while(p && (ptn[p+1] != ptn[i]))p = pi[p];
		if(ptn[p+1] == ptn[i])p++;
		pi[i] = p;

	}


}

void getAns(){

	int p = 0;

	vector <int> ans;

	for(int i=1; i<=ol; i++){

		while(p && (ptn[p+1] != org[i]))p = pi[p];
		if(ptn[p+1] == org[i])p++;
		if(p == pl){
			ans.push_back(i-(pl-1));
			p = pi[p];
		}

	}

	printf("%d\n", ans.size());

	for(int i=0; i<ans.size(); i++){
		printf("%d ", ans[i]);
	}

}

int main(){

	fgets(org+1, sizeof(org) - sizeof(char), stdin);

	ol = strlen(org+1);

	if(org[ol] == '\n')ol--;

	fgets(ptn+1, sizeof(ptn) - sizeof(char), stdin);

	pl = strlen(ptn+1);

	if(ptn[pl] == '\n')pl--;

	getPi();

	getAns();

}
