#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int pp[13][2];
char str[203];

int main(){

    scanf("%s", str);

    int s = strlen(str);
    int top = 0;

    vector <int> p;
    for(int i=0; i<s; i++){
        if(str[i] == '(')p.push_back(i);
        else if(str[i] == ')'){
            pp[top][0] = p.back();
            pp[top][1] = i;
            p.pop_back();
            top++;
        }
    }

    vector <string> output;
    for(int i=1; i<(1<<top); i++){
        for(int j=0; j<top; j++){
            if(i & (1<<j)){
                str[pp[j][0]] = str[pp[j][1]] = 0;
            }else{
                str[pp[j][0]] = '(';
                str[pp[j][1]] = ')';
            }
        }

        string ou;
        for(int j=0; j<s; j++){
            if(str[j] == 0)continue;
            ou += str[j];
        }
        output.push_back(ou);
    }

    sort(output.begin(), output.end());
    output.resize(unique(output.begin(), output.end()) - output.begin());
    for(auto &e : output)printf("%s\n", e.c_str());

}
