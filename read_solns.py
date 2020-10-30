import sys

n = int(sys.argv[1])
input = sys.stdin.read()

solns = input.split("\n")
n_solns = 0
placements = list()
for s in solns:
	clauses = s.split()
	if clauses:
		n_solns += 1
		# filter all but clauses corresponding to exact placements
		p = list(filter(lambda c: c[0] != "~" and c.upper().isupper() == False, clauses )) 
		placements.append(p)


print("Number of Solutions: " + str(n_solns) + "\n")
# print a readable chessboard
for p in placements:
	for row in range(1,n+1):
		for col in range(1,n+1):
			if (str(row)+"."+str(col) in p):
				print("1", end =" ")
			else:
				print("0", end =" ")
		print() # newline
	print()

