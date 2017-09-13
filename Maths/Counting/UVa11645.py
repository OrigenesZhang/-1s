cs=1
while True:
    N=int(input())
    if N<0:
        break
    n=N
    res=0
    d=1
    while n>1:
        res+=(n>>2)*d
        if n&3==3:
            res+=(N&(d-1))+1
        d<<=1
        n>>=1
    s="Case "+str(cs)+": "+str(res)
    print(s)
    cs+=1
