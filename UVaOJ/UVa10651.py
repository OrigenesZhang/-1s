dp=[]
def solve(num):
	for i in range(11):
		if (num>>i)&1 and (num>>(i+1))&1:
			if i>0 and not (num>>(i-1))&1:
				dp.append(num-(1<<i)-(1<<(i+1))+(1<<(i-1)))
			if i!=10 and not (num>>(i+2))&1:
				dp.append(num-(1<<i)-(1<<(i+1))+(1<<(i+2)))
n=int(input())
while n:
	n-=1
	s=input()
	cnt=tmp=0
	for i in range(12):
		tmp<<=1
		if s[i]=='o':
			cnt+=1
			tmp+=1
	dp=[tmp]
	front=0
	if cnt<=1:
		print(cnt)
		continue
	while front<len(dp):
		solve(dp[front])
		front+=1
	tmp=dp[len(dp)-1]
	cnt=0
	while tmp:
		cnt+=tmp&1
		tmp>>=1
	print(cnt)
