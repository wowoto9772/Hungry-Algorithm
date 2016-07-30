#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int A[200003], B[200003];

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <= a; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= b; i++) {
		scanf("%d", &B[i]);
	}

	sort(A + 1, A + 1 + a);
	sort(B + 1, B + 1 + b);

	set <int> S;

	int l = 1, r = 1;

	while (l <= a && r <= b) {
		if (A[l] == B[r])l++, r++;
		else if (A[l] < B[r]) {
			S.insert(A[l]);
			l++;
		}
		else if (A[l] > B[r]) {
			S.insert(B[r]);
			r++;
		}
	}

	for (int i = l; i <= a; i++)S.insert(A[i]);
	for (int i = r; i <= b; i++)S.insert(B[i]);

	printf("%d\n", S.size());

}