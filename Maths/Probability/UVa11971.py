def gcd(a, b):
	if not b:
		return a
	return gcd(b, a%b)
T=int(input())
for t in range(1, T+1):
	s=input()
	N, K=s.split()
	K=int(K)
	if K==1:
		print("Case #"+str(t)+": 0/1")
		continue
	b=1<<K
	a=b-K-1
	g=gcd(a, b)
	print("Case #"+str(t)+": "+str(a//g)+"/"+str(b//g))
