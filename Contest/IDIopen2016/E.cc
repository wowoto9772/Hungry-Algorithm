#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;
int L;
int x[2], y[2];
const double Pii = acos(-1);
bool sex = true;
bool p(ll radius)
{
    double A, B, C,Ap,Bp,Cp;
    double xx[2];
    double yy[2];

    bool touch = false;
    if(x[0] == x[1]) {
        ll d = abs(x[0]);
        if(d<radius) {
            touch = true;
            xx[0] = xx[1] = x[0];
            yy[0] = sqrt(radius*radius - xx[0]*xx[0]);
            yy[1] = -yy[0];
        }
    } else if(y[0] == y[1]) {
        ll d = abs(y[1]);
        if(d<radius) {
            touch = true;
            yy[0] = yy[1] = y[0];
            xx[0] = sqrt(radius*radius - yy[0]*yy[0]);
            xx[1] = -xx[0];
        }
    } else {
        A = y[1] - y[0];
        B = x[0] - x[1];
        C = (y[0] * (x[1] - x[0]) - (y[1] - y[0]) * x[0]);
        if( (C*C) < radius*radius*(A*A+B*B)) {
            touch = true;
            Ap = pow(A, 2)+pow(B, 2);
            Bp = A*C;
            Cp = pow(C, 2)-pow(B,2)*pow(radius,2);
            xx[0] = (-Bp + sqrt(pow(Bp,2)-(Ap*Cp)))/(Ap);
            xx[1] = (-Bp - sqrt(pow(Bp,2)-(Ap*Cp)))/(Ap);
            yy[0] = (-A*xx[0]-C)/B;
            yy[1] = (-A*xx[1]-C)/B;


        }
    }
    if(!touch) {
        if( (radius*radius*Pii) >= (double)L) return true;
        else return false;
    } else {
        double theta = acos((xx[0]*xx[1] + yy[0]*yy[1])/(hypot(xx[0], yy[0])*hypot(xx[1], yy[1])));
        double buchae = radius * radius * theta / 2;
        double samgack = abs(xx[0]*yy[1]-xx[1]*yy[0])/2;
        double nullbi = radius*radius*Pii - buchae + samgack;
        if( (y[0] * (x[1] - x[0]) - (y[1] - y[0]) * x[0]) == 0){
            nullbi = radius*radius*Pii / 2;
            samgack = 0;
            buchae = 0;
        }
        if(!sex) {
            sex = !sex;
            printf("theta = %lf\nbuchae=%lf\nsamgack=%lf\n",theta,buchae,samgack);
            printf("nullbi = %lf\n", nullbi);
            printf("RADIUS = %lld\n", radius);
            printf("A=%lf // B=%lf // C=%lf\n",A,B,C);
            printf("Ap=%lf // Bp=%lf // Cp=%lf\n",Ap,Bp,Cp);
            printf("xx[0] = %lf // xx[1] = %lf // yy[0] = %lf // yy[1] = %lf\n", xx[0], xx[1], yy[0], yy[1]);
        }
        if(nullbi >= (double)L)  return true;
        else return false;
    }
}


int main(){
    scanf("%d",&L);
    for(int i=0;i<2;++i) {
        scanf("%d%d", &x[i], &y[i]);
    }

    int hi = 10000;
    int lo = 1;
    int mid = lo + (hi-lo) / 2;
    while(lo<hi) {
        mid = lo + (hi-lo) / 2;
        if(p(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if(p(lo)) {
        printf("%d\n" , lo);
    } else {
        printf("%d\n" , lo);
    }
}
