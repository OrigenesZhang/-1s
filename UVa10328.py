import sys
dp=[[1 for i in range(101)]]
for i in range(1, 101):
    dp.append([])
    for j in range(0, 101):
        if i<=j:
            dp[i].append(dp[i-1][j]<<1)
        elif i==j+1:
            dp[i].append((dp[i-1][j]<<1)-1)
        else:
            dp[i].append((dp[i-1][j]<<1)-dp[i-j-2][j])
while True:
    s=sys.stdin.readline()
    if not s:
        break
    n, k=s.split()
    n=int(n)
    k=int(k)
    print(dp[n][n]-dp[n][k-1])
