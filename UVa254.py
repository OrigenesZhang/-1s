def hanoi(m, n, a, b, c):
    if not m:
        return n, 0, 0
    if m==(1<<n)-1:
        return 0, 0, n
    for k in range(1, n):
        if m==(1<<n-k)-1:
            if k&1:
                return k, n-k, 0
            else:
                return k, 0, n-k
        if m>(1<<n-k)-1 and m<(1<<n-k+1)-1:
            if k&1:
                b, a, c=hanoi(m-(1<<n-k), n-k, n-k, 0, 0)
                a+=k-1
                c+=1
                return a, b, c
            else:
                c, a, b=hanoi(m-(1<<n-k), n-k, n-k, 0, 0)
                a+=k-1
                b+=1
                return a, b, c
while True:
    s=input()
    if s=="0 0":
        break
    n, m=s.split()
    m=int(m)
    n=int(n)
    a=n
    b=c=0
    if not a:
        print("0 0 0")
        continue
    a, b, c=hanoi(m, n, a, b, c)
    if n&1:
        print(a, c, b)
    else:
        print(a, b, c)
