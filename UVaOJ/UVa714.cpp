#include<cstdio>
using namespace std;
const int N=510, D=(int)1e7+10;
int a[N], v[N];
int n, k;
bool check(long long x){
    long long t=1, h=0;
    for(int i=1; i<=n; i++){
        h+=a[i];
        if(h>x) h=a[i], t++;
    }
    return t<=k;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long h=0, mx=0;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            h+=a[i];
            mx=mx>a[i]?mx:a[i];
        }
        long long l=mx, r=h, mid, ans=1<<30;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        int e=1;
        h=0;
        for(int i=n; i>=1; i--){
            h+=a[i];
            v[i]=0;
            if(h>ans){
                h=a[i];
                e++;
                v[i]=1;
            }
        }
        h=0;
        for(int i=1; i<=n; i++){
            printf("%d",a[i]);
            if(v[i]) printf(" /");
            else if(h<k-e) printf(" /"), h++;
            if(i<n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
