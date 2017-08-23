import sys
def combination(n, r):
    r=min(r, n-r)
    res=1
    for i in range(r):
        res*=n-i
    for i in range(2, r+1):
        res//=i
    return res
N=[[], [i+1 for i in range(22)]]
for i in range(2, 22):
    N.append([1])
    for j in range(1, 22):
        N[i].append(N[i][j-1]+i**j)
dp=[[1] for i in range(22)]
for i in range(1, 22):
    for j in range(1, 21//i+1):
        tmp=1
        for k in range(i):
            tmp*=combination(N[i][j]-1-k*N[i][j-1], N[i][j-1])
        dp[i].append(tmp*(dp[i][j-1]**i))
while True:
    s=sys.stdin.readline()
    if not s:
        break
    k, d=s.split()
    k=int(k)
    d=int(d)
    print(dp[k][d])
