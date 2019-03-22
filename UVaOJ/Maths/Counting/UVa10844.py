dp=[[0 for j in range(901)] for i in range(901)]
res=[0 for i in range(901)] #数据坑,按照题面是不会有I==900的情况出现的
for i in range(1, 901):
	dp[i][1]=1
	res[i]=dp[i][1]
	for j in range(2, i+1):
		dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j
		res[i]+=dp[i][j]
while True:
	I=int(input())
	if not I:
		break
	print(str(I)+", "+str(res[I]))
