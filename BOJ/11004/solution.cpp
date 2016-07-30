#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int A[5000000];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)scanf("%d", &A[i]);
	nth_element(A, A + k - 1, A + n);

	printf("%d\n", A[k - 1]);
}