#include <iostream>
using namespace std;
int p[20050], n, c, x, y;
int Find(int k){
    return p[k]==k?k:p[k]=Find(p[k]);
}
int Union(int k1, int k2){
    int u=Find(k1), v=Find(k2);
    p[u]=v;
}
int main(){
    cin>>n;
    for(int i=0; i<2*n; i++) p[i]=i;
    while(cin>>c>>x>>y){
        if(!c) break;
        switch(c){
            case 1:{
                int u=Find(x), v=Find(y+n);
                if(u==v){
                    cout<<-1<<endl;
                    break;
                }
                Union(x, y);
                Union(x+n, y+n);
                break;
            }
            case 2:{
                int u=Find(x), v=Find(y);
                if(u==v){
                    cout<<-1<<endl;
                    break;
                }
                Union(x, y+n);
                Union(x+n, y);
                break;
            }
            case 3:{
                int u=Find(x), v=Find(y);
                cout<<(u==v)<<endl;
                break;
            }
            default:{
                int u=Find(x), v=Find(y+n);
                cout<<(u==v)<<endl;
                break;
            }
        }
    }
    return 0;
}
