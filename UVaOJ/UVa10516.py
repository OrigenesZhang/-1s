def fast_pow(p ,q):
    product=1
    base=p
    while q:
        if q&1:
            product*=base
        base*=base
        q>>=1
    return product
dp=[[]]
for i in range(1, 33):
    dp.append([1])
    for j in range(1, 17):
        dp[i].append(fast_pow(dp[i][j-1], i)+1)
        if len(str(dp[i][j]))>=200:
            break
while True:
    s=input()
    if s=="0 0":
        break
    n, d=s.split()
    n=int(n)
    d=int(d)
    s+=' '
    print(s, end="")
    if not d:
        print(1)
        continue
    else:
        print(dp[n][d]-dp[n][d-1])
