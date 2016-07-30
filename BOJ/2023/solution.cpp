#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int v){
	if (v == 2)return true;
	else if (v < 2)return false;
	else{
		if (!(v % 2))return false;
		for (int i = 3; i*i <= v; i += 2){
			if (!(v%i))return false;
		}
		return true;
	}
}
vector <int> p[10];

int main(){

	p[1].resize(4);
	p[1][0] = 2, p[1][1] = 3, p[1][2] = 5, p[1][3] = 7;

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++){
		for (int j = 0; j < p[i].size(); j++){
			for (int k = 1; k < 10; k++){
				int np = p[i][j] * 10 + k;
				if (isPrime(np)){
					p[i + 1].push_back(np);
				}
			}
		}
	}

	sort(p[n].begin(), p[n].end());

	for (int i = 0; i < p[n].size(); i++)printf("%d\n", p[n][i]);

	// p[n] : 9

}