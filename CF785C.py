import math
str=input().split()
n=int(str[0])
m=int(str[1])
if m>=n:
	print(n)
else:
	k=-0.5+math.sqrt(0.5*0.5-2*(m-n))
	tmp=int(math.sqrt(1-8*(m-n)))	#precision is 53 bits so cannot use in-built function math.ceil	
	k=int(k)+(tmp*tmp<1-8*(m-n))	#use < instead of the combination of == and not to avoid prcision problems
	if n>m+k:
		print(m+k)
	else:
		print(n)
