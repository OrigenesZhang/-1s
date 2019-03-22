//Southeastern Europe regional 2006;
//Greedily make the current number sqrt(a) if possible;
//The description of this question is wrong in ACM/ICPC live archive;
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double m, p, a, b;
    while(cin>>m>>p>>a>>b){
        double mmax=sqrt(a), mmin=-1/mmax, ab=a*b;
        int x=0, y=0;
        for(int i=0; i<m-1; i++){
            if(ab>=mmax){
                ab-=a;
                x++;
            }else{
                ab+=1;
                y++;
            }
        }
        cout<<(int)(x*pow(mmax, p)+y*pow(mmin, p)+pow(ab/mmax, p)+0.5)<<endl;
    }
    return 0;
}
/*
//Verdict: Accepted in POJ but Wrong Answer in UVa;
//May due to some precision issues;
//This method is faster;
#include <iostream>
#include <cmath>
using namespace std;
int m, p, a, b;
int main(){
    while(cin>>m>>p>>a>>b){
        double mmax=sqrt(a), s=(double)b*sqrt(a), cur=-(double)m/mmax;
        int up=(s-cur)/(mmax+1.0/mmax);
        cout<<(int)(pow(s-(double)up*mmax+(double)(m-up-1)/mmax, p)+up*pow(mmax, p)+(m-up-1)*pow(1.0/mmax, p)+0.5)<<endl;
    }
    return 0;
}
*/
