#include <stdio.h>

#include <string.h>

#include <vector>

using namespace std;

char str[53];

int main(){

    vector <int> val;
    vector <char> op;

    scanf("%s", str);

    int s = strlen(str);

    int v = 0;

    for(int i=0; i<s; i++){

        if(str[i] == '+' || str[i] == '-'){
            val.push_back(v);
            op.push_back(str[i]);
            v = 0;
        }else{
            v = v * 10 + str[i] - '0';
            if(i == s-1)val.push_back(v);
        }

    }

    int ret = val[0];

    bool sub = false;

    for(int i=0; i<op.size(); i++){
        if(op[i] == '-'){
            sub = true;
            ret -= val[i+1];
        }else{
            if(sub)ret -= val[i+1];
            else
                ret += val[i+1];
        }
    }

    printf("%d\n", ret);

}
