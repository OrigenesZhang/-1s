def gcd(a, b):
    if not b:
        return a
    return gcd(b, a%b)
dp=[[0 for i in range(0, 150)] for j in range(0, 25)]
dp[0][0]=1
for i in range(1, 25):
    for j in range(0, 145):
        if dp[i-1][j]:
            for k in range(1, 7):
                if j+k>144:
                    break
                dp[i][j+k]+=dp[i-1][j]
while True:
    s=input()
    (n, x)=s.split()
    n=int(n)
    x=int(x)
    if not n and not x:
        break
    if n*6<x:
        print(0)
        continue
    if x<=n:
        print(1)
        continue
    tot=6**n
    res=0
    for i in range(x, 6*n+1):
        res+=dp[n][i]
    div=gcd(res, tot)
    print(res//div, end="")
    print('/', end="")
    print(tot//div)
