#include <cstdio>
#include <algorithm>

using namespace std;

string dp[2][103];

int main(){

    vector <string> d[8];

    d[2].push_back("1");
    d[3].push_back("7");
    d[4].push_back("4");
    d[5].push_back("2"); d[5].push_back("3"); d[5].push_back("5");
    d[6].push_back("0"); d[6].push_back("6"); d[6].push_back("9");
    d[7].push_back("8");

    for(int i=1; i<=100; i++)dp[0][i] = dp[1][i] = "-1";

    for(int i=2; i<=100; i++){

        for(int j=2; j<=min(i, 7); j++){

            if(dp[0][i-j] != "-1"){
                for(auto &a : d[j]){
                    string tmp = dp[0][i-j] + a;
                    if(tmp[0] == '0')continue;
                    if(dp[0][i] == "-1" || dp[0][i].size() > tmp.size())dp[0][i] = tmp;
                    else{
                        if(dp[0][i].size() == tmp.size() && dp[0][i] > tmp){
                            dp[0][i] = tmp;
                        }
                    }
                }
            }

            if(dp[1][i-j] != "-1"){
                for(auto &a : d[j]){
                    string tmp = a + dp[1][i-j];
                    if(tmp[0] == '0')continue;
                    if(dp[1][i] == "-1" || dp[1][i].size() < tmp.size())dp[1][i] = tmp;
                    else{
                        if(dp[1][i].size() == tmp.size() && dp[1][i] < tmp)dp[1][i] = tmp;
                    }
                }
            }

        }

    }

    int t;
    scanf("%d", &t);

    while(t--){
        int a;
        scanf("%d", &a);

        printf("%s %s\n", dp[0][a].c_str(), dp[1][a].c_str());
    }

}
