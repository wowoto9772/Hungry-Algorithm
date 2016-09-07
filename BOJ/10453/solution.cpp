#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

char A[100003], B[100003];

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		scanf("%s %s", A, B);

		int s = strlen(A);

		int l = 0, r = 0;

		long long ans = 0;

		for(int i=0; i<s; i++){
			if(A[i] == B[i])continue;
			else{
				if(i == s-1)break;
				for(r=i+1;r<s;r++){
					if(A[r] == B[i]){
						break;
					}
				}
				ans += r - i;
				swap(A[i], A[r]);
			}
		}

		printf("%lld\n", ans);
		
	}

}

