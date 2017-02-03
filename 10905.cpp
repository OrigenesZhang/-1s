#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct str{
    char st[1000];
}s[55];
int N;
bool cmpcmp(const char* s1, const char* s2){
    int len1=strlen(s1), len2=strlen(s2);
    if(len1<len2){
        for(int i=0; i<len1; i++){
            if(s1[i]<s2[i]) return false;
            if(s1[i]>s2[i]) return true;
        }
        return cmpcmp(s1, s2+len1);
    }else if(len1==len2){
        for(int i=0; i<len1; i++){
            if(s1[i]<s2[i]) return false;
            if(s1[i]>s2[i]) return true;
        }
        return true;
    }else{
        for(int i=0; i<len2; i++){
            if(s1[i]<s2[i]) return false;
            if(s1[i]>s2[i]) return true;
        }
        return cmpcmp(s1+len2, s2);
    }
}
bool cmp(str s1, str s2){
    return cmpcmp(s1.st, s2.st);
}
int main(){
    while(scanf("%d", &N)){
        if(!N) break;
        for(int i=0; i<N; i++)
            scanf("%s", s[i].st);
        sort(s, s+N, cmp);
        for(int i=0; i<N; i++)
            printf("%s", s[i].st);
        putchar('\n');
    }
    return 0;
}
