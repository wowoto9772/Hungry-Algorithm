#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char I[100003];

int main()
{
	int t;
	scanf("%d", &t);
    fgets(I, 300, stdin);
    
	for(int T=1; T<=t; T++){
        
        fgets(I, sizeof(I), stdin);
		
        int s = strlen(I);
		double CP = -1, CI = -1, CU = -1;
		double tmp;
		for(int i=0; i<s; i++){
			if(I[i] == '='){
				if(I[i-1] == 'P'){
					tmp = 0;
					char d[20] = {0};
					int top = 0;
					for(int j=i+1; j<s; j++){
						if(I[j+1] == 'm' || I[j+1] == 'k' || I[j+1] == 'M'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							if(I[j+1] == 'm'){
								tmp /= 1000;
							}
							else if(I[j+1] == 'k'){
								tmp *= 1000;
							}
							else if(I[j+1] == 'M'){
								tmp *= 1000000;
							}
							i = j;
							CP = tmp;
							break;
						}else if(I[j+1] == 'A' || I[j+1] == 'V' || I[j+1] == 'W'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							i = j;
							CP = tmp;
							break;
						}
						else
							d[top++] = I[j];
					}
				}else if(I[i-1] == 'I'){
					tmp = 0;
					char d[20] = {0};
					int top = 0;
					for(int j=i+1; j<s; j++){
						if(I[j+1] == 'm' || I[j+1] == 'k' || I[j+1] == 'M'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							if(I[j+1] == 'm'){
								tmp /= 1000;
							}
							else if(I[j+1] == 'k'){
								tmp *= 1000;
							}
							else if(I[j+1] == 'M'){
								tmp *= 1000000;
							}
							i = j;
							CI = tmp;
							break;
						}else if(I[j+1] == 'A' || I[j+1] == 'V' || I[j+1] == 'W'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							i = j;
							CI = tmp;
							break;
						}
						else
							d[top++] = I[j];
					}
				}else if(I[i-1] == 'U'){
					tmp = 0;
					char d[20] = {0};
					int top = 0;
					for(int j=i+1; j<s; j++){
						if(I[j+1] == 'm' || I[j+1] == 'k' || I[j+1] == 'M'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							if(I[j+1] == 'm'){
								tmp /= 1000;
							}
							else if(I[j+1] == 'k'){
								tmp *= 1000;
							}
							else if(I[j+1] == 'M'){
								tmp *= 1000000;
							}
							i = j;
							CU = tmp;
							break;
						}else if(I[j+1] == 'A' || I[j+1] == 'V' || I[j+1] == 'W'){
							d[top++] = I[j];
							sscanf(d, "%lf", &tmp);
							i = j;
							CU = tmp;
							break;
						}
						else
							d[top++] = I[j];
					}
				}
			}
		}
        
		printf("Problem #%d\n", T);
		if(CI == -1){
			printf("I=%.2lfA\n", CP / CU);
		}else if(CU == -1){
			printf("U=%.2lfV\n", CP / CI);
		}else if(CP == -1){
			printf("P=%.2lfW\n", CU * CI);
		}printf("\n");
	}
}