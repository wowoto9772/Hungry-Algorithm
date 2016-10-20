#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    map <string, int> mp;
    mp["monday"] = 0;
    mp["tuesday"] = 1;
    mp["wednesday"] = 2;
    mp["thursday"] = 3;
    mp["friday"] = 4;
    mp["saturday"] = 5;
    mp["sunday"] = 6;

    string s1, s2;
    cin >> s1 >> s2;

    int tot = mp[s1] - mp[s2];

    if(tot == 0 || tot == 4 || tot == 5 || tot == -2 || tot == -3)printf("YES\n");
    else
        printf("NO\n");

}
