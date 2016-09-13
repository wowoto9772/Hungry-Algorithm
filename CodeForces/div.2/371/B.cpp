#include <stdio.h>

#include <set>

#include <algorithm>

using namespace std;

int e[100003];

int main(){

	int n;
	scanf("%d", &n);

	set <int> v;

	for(int i=0; i<n; i++){
		int e;
		scanf("%d", &e);
		v.insert(e);
	}

	if(v.size() > 3)printf("NO");
	else{
		int p = -1;
		int d = -1;
		for(auto &e : v){
			if(p == -1)p = e;
			else{
				if(d == -1){
					d = e - p;
					p = e;
				}else{
					if(e - p != d){
						printf("NO");
						return 0;
					}
				}
			}
		}

		printf("YES");
	}

}
