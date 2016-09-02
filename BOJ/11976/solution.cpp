#include <stdio.h>

#include <vector>

using namespace std;

pair <int,int> e[5]; // brz, slv, gld, plt

int main(){

	for(int i=1; i<=4; i++)scanf("%d %d", &e[i].first, &e[i].second);

	int gld_plt = e[4].second - e[4].first;

	int slv_gld = e[3].second - e[3].first + (e[4].second - e[4].first);

	int brz_slv = e[2].second - e[2].first + (e[4].second - e[4].first) + (e[3].second - e[3].first);

	printf("%d\n%d\n%d\n", brz_slv, slv_gld, gld_plt);

}
