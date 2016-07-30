#include <stdio.h>
#include <math.h>

#include <vector>
#include <algorithm>

using namespace std;

#define MAX 5000000

bool p[5000003];
int P[1000003];

int top;

bool isPal(int n){

	vector <int> v;

	while (n){
		v.push_back(n % 10);
		n /= 10;
	}

	for (int i = 0; i < v.size() / 2; i++){

		if (v[i] != v[v.size() - 1 - i])return false;

	}

	return true;

}

int main(){

	int m = sqrt(MAX);

	for (int i = 2; i <= MAX; i++){
		if (!p[i]){
			P[top++] = i;
			if (i > m)continue;
			for (int j = i*i; j <= MAX; j+=i)p[j] = true;
		}
	}

	int n;
	scanf("%d", &n);

	int x = lower_bound(P, P + top, n) - P;

	for (int i = x; i < top; i++){

		if (isPal(P[i])){

			printf("%d\n", P[i]);
			break;

		}

	}

}