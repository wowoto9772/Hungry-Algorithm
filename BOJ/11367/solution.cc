#include <cstdio>
#include <cstring>

using namespace std;

char str[23];

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
	
		int v;
		scanf("%s %d", str, &v);
		
		printf("%s ", str);
		
		if(v == 100)printf("A+");
		else if(v < 60)printf("F");
		else{
			printf("%c", 'D'-(v-60)/10);
			if(v%10 >= 7)printf("+");
		}
		
		printf("\n");
		
	}
	
}