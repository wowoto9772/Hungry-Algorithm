#include <cstdio>

#include <cstring>

#include <string>

#include <algorithm>

using namespace std;

class ele{

    public:

        int l, s;
        string str;

        ele(){}
        ele(int _l, int _s, string _str){
            l = _l, s = _s, str = _str;
        }

        bool operator<(const ele &A)const{
            if(l == A.l){
                if(s == A.s)return str < A.str;
                return s < A.s;
            }
            return l < A.l;
        }

}e[1003];

char str[53];

int main(){

    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){

        scanf("%s", str);

        int s = strlen(str);

        e[i] = {s, 0, string(str)};

        for(int j=0; j<s; j++){
            if(str[j] >= '0' && str[j] <= '9'){
                e[i].s += str[j] - '0';
            }
        }
        
    }

    sort(e, e+n);

    for(int i=0; i<n; i++)printf("%s\n", e[i].str.c_str());

}
