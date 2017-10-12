#穷举循环节...
INF=0x3f3f3f3f3f3f3f3f
def gcd(a, b):
	if not b:
		return a
	return gcd(b, a%b)
while True:
	s=input()
	if s=="0":
		break
	s=s.split('.')
	s=s[1]
	n1=0
	m1=1
	rn=rm=INF
	for i in s:
		n1=n1*10+int(i)
		m1*=10
	for i in range(len(s)):
		n2=0
		m2=1
		for j in s[:i]:
			n2=n2*10+int(j)
			m2*=10
		nom=n1-n2
		denom=m1-m2
		g=gcd(nom, denom)
		nom//=g
		denom//=g
		if denom<rm:
			rm=denom
			rn=nom
	print(str(rn)+"/"+str(rm))
