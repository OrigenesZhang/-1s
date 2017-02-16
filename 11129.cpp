#include <iostream>
using namespace std;
int n, num[10000+100], sub1[5000+50], sub2[5000+50];
void divide_and_conquer(int l, int r){
    if(l==r) return;
    int tot1=0, tot2=0, cur1=0, cur2=0, i;
    for(i=l; i<=r; i+=2) sub1[tot1++]=num[i];
    for(i=l+1; i<=r; i+=2) sub2[tot2++]=num[i];
    for(i=l; i<l+tot1; i++) num[i]=sub1[cur1++];
    for(; i<=r; i++) num[i]=sub2[cur2++];
    divide_and_conquer(l, l+tot1-1);
    divide_and_conquer(l+tot1, r);
}
int main(){
    while(cin>>n){
        if(!n) break;
        for(int i=0; i<n; i++) num[i]=i;
        divide_and_conquer(0, n-1);
        cout<<n<<':';
        for(int i=0; i<n; i++)
            cout<<' '<<num[i];
        cout<<endl;
    }
    return 0;
}
