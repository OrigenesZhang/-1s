#include <iostream>
using namespace std;


double Q_rsqrt( double number )
{
    long long i;
    double x2, y;
    const double threehalfs = 1.5;

    x2 = number * 0.5;
    y  = number;
    i  = * ( long long * ) &y;                       // evil floating point bit level hacking（对浮点数的邪恶位元hack）
   // i  = 0x5f3759df - ( i >> 1 );
    i  = 0x5fe6eb50c7aa19f9 - ( i >> 1 );    // what the fuck?（这他妈的是怎么回事？）
    y  = * ( double * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次迭代）
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除）
   
    return y;
}


//0x5fe6eb50c7aa19f9
int main() {
    int a=-1;

    double x=0.5*a;
    cout<<1/Q_rsqrt(16);
}