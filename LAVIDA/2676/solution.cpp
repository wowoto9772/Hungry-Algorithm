#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class ele{
public:
	string name;
	int x, y, r;
}I[103];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			cin >> I[i].name;
			scanf("%d %d %d", &I[i].x, &I[i].y, &I[i].r);
		}

		bool tie = false;
		int max = -1;
		int s = -1;
		for (int i = 0; i < n; i++){ // same name but different person
			int c = 0;
			for (int j = 0; j < n; j++){
				int a = (I[i].x - I[j].x)*(I[i].x - I[j].x) + (I[i].y - I[j].y)*(I[i].y - I[j].y);
				if (a < (I[i].r + I[j].r)*(I[i].r + I[j].r)){
					c++;
				}
			}
			if (max < c){
				max = c;
				s = i;
				tie = false;
			}
			else if (max == c){
				tie = true;
			}
		}

		if (tie)printf("TIE\n");
		else{
			printf("%s\n", I[s].name.c_str());
		}
	}
}