#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool pos(int n, int p){
	if (n == 1)return false;

	int a[33] = { 0 };
	int top = 0;

	while (p){
		a[top++] = p% n;
		p /= n;
	}

	for (int j = 0; j < top / 2; j++){
		if (a[j] != a[top - 1 - j])return false;
	}

	return true;
}


int main(){

	int x;
	while (scanf("%d", &x) == 1){

		for (int i = 2; i < x; i++){
			if (pos(i, x))printf("%d\n", i);
		}

		continue;

		vector <int> p;
		for (int i = 1; i*i < x; i++){
			if (x%i){
				if (pos(i, x))p.push_back(i);
			}
			else{
				if (pos(x / i - 1, x) || pos(i, x))p.push_back(x / i - 1);
			}
		}

		sort(p.begin(), p.end());
		p.resize(distance(p.begin(), unique(p.begin(), p.end())));

		for (int i = 0; i < p.size(); i++)printf("%d\n", p[i]);
	}
}