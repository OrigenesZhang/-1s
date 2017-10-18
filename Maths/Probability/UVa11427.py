import math
N=int(input())
for cs in range(1, N+1):
	s=input()
	p, n=s.split()
	exec("p="+p)
	n=int(n)
	dp=[[0 for i in range(105)] for j in range(105)]
	dp[0][0]=dp[0][1]=1
	for i in range(1, n+1):
		for j in range(int(math.ceil(p*i+1e-9))):
			dp[i][j]=dp[i-1][j]*(1-p)
			if j:
				dp[i][j]+=dp[i-1][j-1]*p
	res=0
	for i in range(int(math.ceil(p*n+1e-9))):
		res+=dp[n][i]
	print("Case #"+str(cs)+": "+str(int(1/res)))
