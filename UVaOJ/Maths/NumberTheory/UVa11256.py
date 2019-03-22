def gcd(a, b):
	if not b:
		return a
	return gcd(b, a%b)
Pow=[10**i for i in range(10)]
N=int(input())
while N:
	N-=1
	n=int(input())
	res=1<<63
	length=len(str(n))
	for i in range(1, length+1):
		cur=1
		for j in range(i<<1, (length<<1)+1, i):
			cur=cur*Pow[i]+1
			d=n//gcd(cur, n)
			if len(str(d))<=i:
				tmp=Pow[i-1]//d*d
				if tmp<Pow[i-1]:
					tmp+=d
				res=min(res, cur*tmp)
	print(res)
