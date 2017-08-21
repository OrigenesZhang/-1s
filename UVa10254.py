#dp[n]=min(dp[k]+2**(n-k)-1)
#上面这个python会T
#下面这个规律是打表找到的
import sys
f=[]
g=[0]
for i in range(1, 142):
    f.append(i*(i+1)>>1)
    g.append(g[i-1]+i*(1<<i-1))
while True:
    N=sys.stdin.readline()
    if not N:
        break
    N=int(N)
    if not N:
        print(0)
        continue
    for i in range(140):
        if N==f[i]:
            print(g[i+1])
            break
        elif N<f[i+1]:
            print(g[i+1]+(N-f[i])*(1<<i+1))
            break
