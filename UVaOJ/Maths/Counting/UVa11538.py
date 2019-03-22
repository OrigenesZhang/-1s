while True:
    s=input()
    if s=="0 0":
        break
    n, m=s.split()
    n=int(n)
    m=int(m)
    if n>m:
        t=n
        n=m
        m=t
    print(n*(n-1)*m+m*(m-1)*n+2*n*(n-1)*(3*m-n-1)//3)
