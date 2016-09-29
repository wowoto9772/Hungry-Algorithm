#include <cstdio>

#include <cmath>

#include <vector>

#include <algorithm>

using namespace std;

const double pi = acos(-1.0);

int x[5], y[5];

double S(int x, int y){
    return sqrt((double)(x*x+y*y));
}

int main(){

    vector < pair<int,int> > v(3);

    for(int i=0; i<3; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<3; i++)x[i] = v[i].first, y[i] = v[i].second;

    int vx[6], vy[6];

    vx[0] = x[1] - x[0], vy[0] = y[1] - y[0];
    vx[1] = x[2] - x[0], vy[1] = y[2] - y[0];

    vx[2] = x[0] - x[1], vy[2] = y[0] - y[1];
    vx[3] = x[2] - x[1], vy[3] = y[2] - y[1];

    vx[4] = x[0] - x[2], vy[4] = y[0] - y[2];
    vx[5] = x[1] - x[2], vy[5] = y[1] - y[2];

    int over = 0, dig = 0, zero = 0;

    vector <int> l;

    for(int d=0; d<3; d++){

        int i = d * 2;
        int j = i + 1;

        int dot = vx[i] * vx[j] + vy[i] * vy[j];

        double ans = acos((double)dot / S(vx[i], vy[i]) / S(vx[j], vy[j]));

        l.push_back((vx[i]-vx[j])*(vx[i]-vx[j])+(vy[i]-vy[j])*(vy[i]-vy[j]));

        if(fabs(ans) <= 1e-12)zero++;
        else if(fabs(ans-pi/2.0) <= 1e-12)dig++;
        else if(pi/2.0 < ans)over++;


    }

    if(zero)printf("X\n");
    else{

        sort(l.begin(), l.end());

        if(l[0] == l[2])printf("JungTriangle\n");
        else if(l[0] == l[1] || l[1] == l[2]){
            if(over)printf("Dunkak2Triangle\n");
            else if(dig)printf("Jikkak2Triangle\n");
            else
                printf("Yeahkak2Triangle\n");
        }else{
            if(over)printf("DunkakTriangle\n");
            else if(dig)printf("JikkakTriangle\n");
            else
                printf("YeahkakTriangle\n");
        }

    }

}
