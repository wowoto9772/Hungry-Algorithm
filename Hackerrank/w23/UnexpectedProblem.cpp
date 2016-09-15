#include <stdio.h>

#include <string.h>

#include <string>
#include <vector>

using namespace std;

using ll = long long;

#define LEN 500003

const ll cmod = 1000000007LL;

char org[LEN], ptn[LEN];
int pi[LEN];
int pl, ol;

// 1 base only

void getPi(){

	int p = 0;

	pi[1] = 0;

	for(int i=2; i<=pl; i++){

		while(p && (ptn[p+1] != ptn[i]))p = pi[p];
		if(ptn[p+1] == ptn[i])p++;
		pi[i] = p;

	}

}

int main(){

	scanf("%s", ptn+1);
	pl = strlen(ptn+1);

	getPi();

    int T = (pl - pi[pl]);

    int m;
    scanf("%d", &m);

    ll ans = m / T;

    ans %= cmod;

    printf("%lld\n", ans);

}
