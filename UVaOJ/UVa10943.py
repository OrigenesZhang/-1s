def combination(n, r):
    r=min(r, n-r)
    res=1
    for i in range(r):
        res*=n-i
        res//=i+1
    res%=1000000
    return res
while True:
    s=input()
    if s=="0 0":
        break
    n, k=s.split()
    n=int(n)
    k=int(k)
    print(combination(n+k-1, k-1))
