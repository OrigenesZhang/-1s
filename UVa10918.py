dp=[1, 2]
for i in range(2, 31):
    if i&1:
        dp.append((dp[i-1]<<1)+dp[i-2])
    else:
        dp.append(dp[i-1]+dp[i-2])
while True:
    N=int(input())
    if N==-1:
        break
    if N&1:
        print(0)
    else:
        print(dp[N])
