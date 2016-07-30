////#include <stdio.h>
////#include <string.h>
////#include <algorithm>
////
////using namespace std;
////
////char str[1003];
////
////int dp[1003][1003];
////
////int dy(int le, int ri){
////
////	if (le > ri)return 0;
////	else if (le == ri)return 1;
////
////	if (dp[le][ri] != -1)return dp[le][ri];
////
////	if (str[le] == str[ri]){
////		dp[le][ri] = min(2 + dy(le + 1, ri), 2 + dy(le + 1, ri - 1));
////	}
////	else{
////		dp[le][ri] = 2 + dy(le + 1, ri);
////	}
////
////	return dp[le][ri];
////
////} // 점화식이 틀림 asdasd
////
////int main(){
////
////	scanf("%s", str);
////
////	int s = strlen(str);
////
////	for (int i = 0; i < s; i++)for (int j = i; j < s; j++)dp[i][j] = -1;
////
////	printf("%d\n", dy(0, s - 1));
////
////}
//
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//char str[1003];
//
//int dp[1003][1003];
//
//int dy(int le, int ri){
//
//	if (le > ri)return 0;
//	else if (le == ri)return 1;
//
//	if (dp[le][ri] != -1)return dp[le][ri];
//
//	if (str[le] == str[ri]){
//		dp[le][ri] = min(2 + dy(le + 1, ri), 2 + dy(le + 1, ri - 1));
//	}
//	else{
//		dp[le][ri] = 2 + dy(le + 1, ri);
//	}
//
//	return dp[le][ri];
//
//} // 점화식이 틀림 asdasd
//
//int main(){
//
//	scanf("%s", str);
//
//	int s = strlen(str);
//
//	for (int i = 0; i < s; i++)for (int j = i; j < s; j++)dp[i][j] = -1;
//
//	printf("%d\n", dy(0, s - 1));
//
//}

//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//char str[1003];
//
//int dp[1003][1003];
//
//int dy(int le, int ri){
//
//	if (le > ri)return 0;
//	else if (le == ri)return 1;
//
//	if (dp[le][ri] != -1)return dp[le][ri];
//
//	if (str[le] == str[ri]){
//		dp[le][ri] = min(2 + dy(le + 1, ri), 2 + dy(le + 1, ri - 1));
//	}
//	else{
//		dp[le][ri] = 2 + dy(le + 1, ri);
//	}
//
//	return dp[le][ri];
//
//} // 점화식이 틀림 asdasd
//
//int main(){
//
//	scanf("%s", str);
//
//	int s = strlen(str);
//
//	for (int i = 0; i < s; i++)for (int j = i; j < s; j++)dp[i][j] = -1;
//
//	printf("%d\n", dy(0, s - 1));
//
//}

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[1003];

int d[] = { 0, 1 };

bool isPal(int s){
	for (int i = 0; i < s / 2; i++){
		if (str[i] != str[s - 1 - i])return false;
	}
	return true;
}

int main(){

	scanf("%s", str);

	int s = strlen(str);

	int ans = s * 2;

	if (isPal(s))ans = s;
	else{

		for (int i = s / 2; i < s; i++){

			for (int k = 0; k < 2; k++){

				bool flag = true;

				int c = 0;

				int le = i, ri = i + d[k];

				while (true){

					if (ri < s && str[le] == str[ri]){

						le--, ri++;

						if (ri == s){

							flag = false;

							if (le == -1){
								ans = s;
								break;
							}

						}
						else{

							if (le == -1)break;

						}

					}
					else{

						if (flag)break;
						else{

							c++;
							le--;
							if (le == -1)break;

						}

					}

				}

				if (!flag){

					ans = min(ans, s + c);

				}

			}


		}

	}

	printf("%d\n", ans);

}