#include <stdio.h>

#include <vector>

#include <algorithm>

using namespace std;

int s[50003];

int main(){

	int n;
	scanf("%d", &n);

	vector <int> sexy[7];

	sexy[0].push_back(0);

	for(int i=1; i<=n; i++){

		scanf("%d", &s[i]);
		s[i] %= 7;

		s[i] += s[i-1];

		s[i] %= 7;

		sexy[s[i]].push_back(i);

	}

	int ans = 0;

	for(int i=0; i<7; i++){
		if(sexy[i].size() >= 2){
			ans = max(sexy[i].back() - sexy[i].front(), ans);	
		}
	}

	printf("%d\n", ans);

}
