//底下那个python不知道为什么就T了orz
#include <stdio.h>
int Fib[50], Fibs[50];
int main(){
	Fib[0]=0, Fib[1]=1, Fib[2]=1;
	Fibs[0]=0, Fibs[1]=1, Fibs[2]=2;
	int len=2;
	while(Fibs[len]<90000000){
		Fib[len+1]=Fib[len]+Fib[len-1];
		Fibs[len+1]=Fibs[len]+Fib[len+1];
		len++;
	}
	int T, K, i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &K);
		int Flag=0, p0=0;
		for(i=len; i>=0; i--){
			if(Flag){
				Flag=0;
				continue;
			}
			if(K>Fibs[i]+1){
				K-=Fibs[i]+1;
				putchar('1');
				putchar('0');
				p0=1;
				Flag=1;
			}else if(K==Fibs[i]+1){
				putchar('1');
				for(j=0; j<i; j++)
					putchar('0');
				putchar('\n');
				break;
			}else if(p0)
				putchar('0');
		}
	}
	return 0;
}
/*
Fib=[0, 1, 1]
Fibs=[0, 1, 2]
while Fibs[-1]<90000000:
    Fib.append(Fib[-1]+Fib[-2])
    Fibs.append(Fibs[-1]+Fib[-1])
T=int(input())
while T:
    T-=1
    K=int(input())
    cur=len(Fibs)-1
    Flag=False
    p0=False
    for i in range(cur, -1, -1):
        if Flag:
            Flag=False
            continue
        if K>Fibs[i]+1:
            K-=Fibs[i]+1
            print(10, end="")
            p0=True
            Flag=True
            continue
        elif K==Fibs[i]+1:
            print(1, end="")
            for j in range(i):
                print(0, end="")
            print()
            break
        elif p0:
            print(0, end="")
*/
