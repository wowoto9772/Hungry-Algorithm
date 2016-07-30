//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int arrToNum(int a[], int s){
//	int ret = 0;
//	for (int i = 0; i < s; i++){
//		ret = ret * 10 + a[i];
//	}return ret;
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//
//	int cn = n;
//
//	int val[10] = { 0 };
//	int s = 0;
//	while (cn){
//		val[s] = cn % 10;
//		cn /= 10;
//		s++;
//	}
//	
//	sort(val, val + s);
//
//	int ans = 0;
//	while (next_permutation(val, val + s)){
//		int c = arrToNum(val, s);
//		if (n < c){
//			if (!ans)ans = c;
//			else if (ans > c)ans = c;
//		}
//	}
//
//	printf("%d\n", ans);
//}

#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	char str[10] = { 0 };
	scanf("%s", str);

	printf("%s\n", next_permutation(str, str + strlen(str)) ? str : "0");
}