#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, b, c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[100003];

int p[1003];

int P(int a){
	while (p[a])a = p[a];
	return a;
}

int main()
{

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++)scanf("%d %d %d", &I[i].a, &I[i].b, &I[i].c);

	sort(I + 1, I + 1 + m);

	int ans = 0, c = 0;

	for (int i = 1; c != n-1 && i <= m; i++){
		int a = P(I[i].a), b = P(I[i].b);
		if (a == b)continue;
		else{
			p[a] = b;
			ans += I[i].c;
			c++;
		}
	}

	printf("%d\n", ans);
}