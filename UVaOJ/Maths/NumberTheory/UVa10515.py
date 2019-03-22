table=[[], [], [6, 2, 4, 8], [1, 3, 9, 7], [6, 4], [5], [6], [1, 7, 9, 3], [6, 8, 4, 2], [1, 9]]
while True:
	s=input()
	if s=="0 0":
		break
	m, n=s.split()
	m=int(m[-1])
	n=int(n)
	if n==1 or m==1:
		print(1)
		continue
	if not m:
		print(0)
		continue
	print(table[m][n%len(table[m])])
