#include <stdio.h>

#include <limits.h>

#include <queue>

using namespace std;

int chk[10003];

int s[10003];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){

		scanf("%d", &s[i]);

		chk[i] = INT_MAX;

	}

	int a, b;
	scanf("%d %d", &a, &b);

	queue <int> q;

	chk[a] = 0;
	q.push(a);

	while(!q.empty() && chk[b] == INT_MAX){

		int f = q.front();q.pop();

		for(int i=f+s[f]; i<=n; i+=s[f]){
			if(chk[i] > chk[f] + 1){
				chk[i] = chk[f] + 1;
				q.push(i);
			}
		}

		for(int i=f-s[f]; i>=1; i-=s[f]){
			if(chk[i] > chk[f] + 1){
				chk[i] = chk[f] + 1;
				q.push(i);
			}
		}

	}

	if(chk[b] == INT_MAX)chk[b] = -1;

	printf("%d\n", chk[b]);


}
