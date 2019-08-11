#include <cstdio>
#include <cstring>

using namespace std;

char str[1000003];

int main(){
	scanf("%s", str);
	int s = strlen(str);
	int f = s % 3;
	int i_ = 0;
	if (f == 1){
        if(str[0] == '1')printf("1");
        else
            printf("0");
		i_ = 1;
	}
	else if (f == 2){
		printf("%d", (str[0] - '0') * 2 + str[1] - '0');
		i_ = 2;
	}
	for (int i = i_; i<s; i += 3){
		printf("%d", (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0'));
	}printf("\n");
}