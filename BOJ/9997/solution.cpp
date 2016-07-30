//#include <stdio.h>
//#include <string.h>
//
//#define lim (1 << 26) - 1
//
//bool chk[lim + 2];
//
//char str[103];
//
//int n;
//int wrd[27];
//int ans;
//
//void find(int cur, int sum, int vst){
//
//	if (sum == lim){
//		if (!chk[vst]){
//			ans++;
//			chk[vst] = true;
//		}
//	}
//
//	if(cur < n){
//		find(cur + 1, sum | wrd[cur], vst | (1<<cur));
//		find(cur + 1, sum, vst);
//	}
//
//}
//
//int main(){
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++){
//
//		scanf("%s", str);
//
//		int s = strlen(str);
//
//		for (int j = 0; j < s; j++){
//
//			wrd[i] |= 1 << (str[j] - 'a');
//
//		}
//
//	}
//
//	find(0, 0, 0);
//
//	printf("%d\n", ans);
//
//}

#include <stdio.h>
#include <string.h>

#define lim (1 << 26) - 1

char str[103];

int n;
int wrd[27];
int ans;

void find(int cur, int sum){

	if (sum == lim){
		ans++;
	}

	for (int i = cur + 1; i < n; i++){
		find(i, sum | wrd[i]);
	}

}

int main(){

	scanf("%d", &n);

	for (int i = 0; i < n; i++){

		scanf("%s", str);

		int s = strlen(str);

		for (int j = 0; j < s; j++){

			wrd[i] |= 1 << (str[j] - 'a');

		}

	}

	find(-1, 0);

	printf("%d\n", ans);

}