#include <stdio.h>

#include <set>

using namespace std;

set <int> sexy[10];

int main(){

	int n, l;
	scanf("%d %d", &n, &l);

	for(int i=1; i<10; i++){
		if(i == l)continue;
		sexy[1].insert(i);
	}

	int c = 0;

	for(int i=1; i<9; i++){
		if(n <= sexy[i].size() + c){
			for(auto &v : sexy[i]){
				c++;
				if(c == n){
					printf("%d", v);
					return 0;
				}
			}
		}else{

			c += sexy[i].size();

			for(auto &v : sexy[i]){
				for(int j=0; j<10; j++){
					if(j == l)continue;
					sexy[i+1].insert(v * 10 + j);
				}
			}
		}
	}

}
