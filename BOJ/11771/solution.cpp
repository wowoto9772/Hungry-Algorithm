#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

char ans[13][13];

char str[13], ptn[103];

int main()
{
	int n;
	vector < pair <int,int> > hole[4];

	scanf("%d",&n);

	for(int i=0; i<n; i++){

		scanf("%s", str);
		for(int j=0; j<n; j++) {
			if(str[j] == '.') {
				hole[0].emplace_back(i, j);
			}
		}
	}


	scanf("%s", ptn);

	int idx = 0;

	bool sw = true;

	for(auto & e : hole[0]) {

		int i = e.first;
		int j = e.second;

		hole[1].emplace_back(j, n-1-i);
		hole[2].emplace_back(n-1-i, n-1-j);
		hole[3].emplace_back(n-1-j, i);

	}

	for(int i=1; i<4; i++){
		sort(hole[i].begin(), hole[i].end());
	}

	for(int i=0; i<4; i++){

		for(auto &e : hole[i]) {

			ans[e.first][e.second] = ptn[idx];
			idx++;

		}

	}

	bool flag = false;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(ans[i][j] == 0) {
				flag = true;
			}
		}
	}

	if(flag)printf("invalid grille");
	else{
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%c",ans[i][j]);
			}
		}
	}


	return 0;
}

