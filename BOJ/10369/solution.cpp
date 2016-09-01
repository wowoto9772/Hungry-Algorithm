#include <stdio.h>

#include <algorithm>

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		unsigned int n1, n2;

		scanf("%x %x", &n1, &n2);

		printf("Case #%d: ", ++tc);

		if(n1 == n2)printf("0 Any\n");
		else{

			int left = 32, right = 0;

			for(int i=0; i<32; i++){

				unsigned int _n2 = (n1 << i) | (n1 >> (32-i));

				if(_n2 == n2){

					left = min(i, left);
					right = max(right, i);

				}

			}

			if(left == 32 && right == 0)printf("Not possible\n");
			else{

				if(left > 32 - right)printf("%d Right\n", 32 - right);
				else if(left < 32 - right){
					printf("%d Left\n", left);
				}else{
					printf("%d Any\n", left);
				}

			}

		}


	}

}
