import sys
dp=[[1 for i in range(151)]]
for i in range(1, 151):
    dp.append([0])
    for j in range(1, 151):
        dp[i].append(0)
        for k in range(i):
            dp[i][j]+=dp[k][j-1]*dp[i-k-1][j]
while True:
    s=sys.stdin.readline()
    if not s:
        break
    n, d=s.split()
    n=int(n)
    d=int(d)
    if n&1 or n>>1<d:
        print(0)
        continue
    n>>=1
    print(dp[n][d]-dp[n][d-1])
