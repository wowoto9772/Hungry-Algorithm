#include <stdio.h>

int main(){
	int x, y, s;
	while (scanf("%d %d %d", &x, &y, &s) == 3 && x && y && s){
		int ans = 0;

		for (int i = 1; i < s; i++){
			for (int j = 1; j < s; j++){
				int i_ = i * (100 + x);
				i_ /= 100;
				int j_ = j * (100 + x);
				j_ /= 100;
				if (i_ + j_ == s){
					i_ = i * (100 + y);
					i_ /= 100;
					int j_ = j * (100 + y);
					j_ /= 100;

					i_ += j_;

					ans = ans < i_ ? i_ : ans;
				}
			}
		}

		printf("%d\n", ans);
	}
}