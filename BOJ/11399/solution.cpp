#include <stdio.h>
#include <algorithm>

using namespace std;

int w[1003], s[1003];

int main(){
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}

	sort(w, w + n);

	s[0] = w[0];

	for (int i = 1; i < n; i++){
		s[i] = s[i - 1] + w[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)ans += s[i];

	printf("%d\n", ans);

}