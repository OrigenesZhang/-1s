#include <iostream>
using namespace std;
long long s[20], a[5], b[5];
int t;
long long fast_pow(int k){
	long long product=1, base=10;
	while(k){
		if(k&1) product*=base;
		base*=base;
		k>>=1;
	}
	return product;
}
void init(int pos){
    long long st, en, modi=0;
    st=pos*fast_pow(pos-1);
    en=pos*(fast_pow(pos)-1);
    for(int i=pos-1; i>0; i--)
        modi-=fast_pow(i)-1;
    st+=modi;
    en+=modi;
    s[pos]=(st+en)*(9*fast_pow(pos-1))/2+s[pos-1];
}
int main(){
    s[0]=0, s[1]=45;
    a[0]=1, a[1]=11, a[2]=192, a[3]=2893, a[4]=38894;
    b[1]=9, b[2]=180, b[3]=2700, b[4]=36000;
    for(int i=2; i<=4; i++) init(i);
    cin>>t;
    while(t--){
        long long i, j;
        cin>>i;
        for(j=4; j>0; j--)
            if(i>s[j]) break;
        i-=s[j];
        long long cur=a[j];
        long long tmp=i-cur;
        while(tmp>0){
            i=tmp;
            cur+=(j+1);
            tmp-=cur;
        }
        for(j=1; j<=4; j++){
            if(i>b[j]) i-=b[j];
            else break;
        }
        long long integer=i/j;
        cur=i%j;
        if(!cur&&j!=1)
            cur+=j, integer--;
        if(j==1) cout<<i<<endl;
        else cout<<(fast_pow(j-1)+integer)%fast_pow(j-cur+1)/fast_pow(j-cur)<<endl;
    }
    return 0;
}
