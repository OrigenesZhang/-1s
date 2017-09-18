import sys
def C(n, r):
    p=1
    for i in range(r):
        p*=n-i
        p//=i+1
    return p
while True:
    s=sys.stdin.readline()
    if not s:
        break
    K, N=s.split()
    K=int(K)
    N=int(N)
    s=input()
    l=s.split()
    while len(l)<(K<<1):
        tmp=input()
        tmp=tmp.split()
        l+=tmp
    for i in range(K<<1):
        l[i]=int(l[i])
    for i in range(K):
        N-=l[i<<1]
        l[(i<<1)+1]-=l[i<<1]
    if N<0:
        print(0)
        continue
    L=[l[(i<<1)+1] for i in range(K)]
    if sum(L)<N:
        print(0)
        continue
    res=0
    for i in range(1<<K):
        S=0
        cnt=0
        for j in range(K):
            if i&(1<<j):
                S+=L[j]+1
                cnt+=1
        if N<S:
            continue
        if cnt&1:
            res-=C(N-S+K-1, K-1)#这边还是对K选不是对K-cnt-1选因为处理的是超过上限的所有情况而不是仅超过1
        else:
            res+=C(N-S+K-1, K-1)
    res=max(0, res)
    print(res)
