#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	set <int> candy;
	map <int, int> cnt;

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == 1){
			// pick up

			set <int> ::iterator it = candy.begin();

		}
		else{
			// insert
			int c;
			scanf("%d", &c);

			if (cnt[b] == 0)candy.insert(b);

			cnt[b] += c;

			if (cnt[b] == 0)candy.erase(b);
		}
	}

}