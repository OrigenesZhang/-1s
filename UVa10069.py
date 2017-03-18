T=int(input())
while T>0:
	T-=1
	X=input()
	Z=input()
	dp=[]
	len1=len(X)
	len2=len(Z)
	dp.append([])
	dp[0].append(1)
	for i in range(0, len1):
		dp[0].append(0)
	for i in range(1, len1+1):
		dp.append([1])
		for j in range(1, len2+1):
			dp[i].append(dp[i-1][j])
			if X[i-1]==Z[j-1]:
				dp[i][j]+=dp[i-1][j-1]
	print(dp[len1][len2])
#python大法好
