#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class ele{
public:
    string org, stb;
    ele(){}
    ele(string _org, string _stb){
        org = _org, stb = _stb;
    }
    bool operator<(const ele &A)const{
        return stb < A.stb;
    }
}e[1003];

char str[23];

int main(){
    
	int n;
	while (scanf("%d", &n) == 1 && n){
        
        for(int i=0; i<n; i++){
            scanf("%s", str);
            e[i].org = string(str);
            e[i].stb = e[i].org;
            for(int j=0; j<e[i].stb.size(); j++){
                if(e[i].stb[j] >= 'a')e[i].stb[j] -= 'a' - 'A';
            }
        }

		sort(e, e+n);
		printf("%s\n", e[0].org.c_str());
	}
}