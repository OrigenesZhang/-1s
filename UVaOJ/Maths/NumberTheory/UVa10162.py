while True:
	N=int(input())
	if not N:
		break
	S=(N//20)*4%10
	upp=N%20
	tot=0
	for i in range(1, upp+1):
		tot+=i**i
	tot%=10
	S=(S+tot)%10
	print(S)
