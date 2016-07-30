#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int k;
	scanf("%d", &k);

	k--;

	int size = 1;
	for (int i = 1; (1 << i) <= k; i++){
		size++;
		k -= (1 << i);
	}

	vector <int> q;
	for (int i = 1; i <= size; i++){
		if (k & 1)q.push_back(7);
		else
			q.push_back(4);
		k >>= 1;
	}

	for (int i = q.size() - 1; i >= 0; i--)printf("%d", q[i]);

	printf("\n");

}

// 0 1
// 00 01 10 11
// 000 444
// 001 447
// 010 474
// 011 477
// 100 744
// 101 747
// 110 774