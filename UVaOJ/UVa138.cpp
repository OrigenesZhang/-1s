//Pell's equation
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int x=1, y=1, cur;
    for(int i=0; i<10; i++){
        cur=3*x+2*y+1;
        y+=cur+x;
        x=cur;
        cout<<setw(10)<<x<<setw(10)<<y<<endl;
    }
    return 0;
}
/*
 * 先凑配成(2y+1)^2-2(2x)^2=1的形式,这是一个Pell方程;
 * 这样有(2y[k]+1)+2x[k]*sqrt(2)=((2y[1]+1)+2x[1]*sqrt(2))^k;
 * 但是这里的x[1]和y[1]可以是(1,1)比题目给的样例更简单(但是只是数学上满足并不满足题意)
 * 之后带入得到x[k]=3*x[k-1]+2*y[k-1]+1,y[k]=4*x[k-1]+3*y[k-1]+1=x[k]+x[k-1]+y[k-1];
 */
