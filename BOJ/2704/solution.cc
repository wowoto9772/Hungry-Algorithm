#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string binary(int v){
    if(v == 0)return "000000";
    string in, ans;
    while(v){
        in += (v&1)+'0';
        v >>= 1;
    }
    for(int i=5; i>in.size()-1; i--)ans+='0';
    for(int i=in.size()-1; i>=0; i--)ans+=in[i];
    return ans; 
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        string hh,mm,ss;
        hh=binary(h);
        mm=binary(m);
        ss=binary(s);
        for(int i=0;i<6;i++)cout << hh[i] << mm[i] << ss[i];
        cout << " " << hh+mm+ss << '\n';
    }
}
