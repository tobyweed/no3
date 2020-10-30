import sys
import numpy

# convert list of solution strings to 2d list of ints
def get_2dlists(soln_strings):
	soln_matrices = []
	for s in soln_strings:
		rows = s.split("\n")
		soln_matrix = []
		for r in rows:
			entries = r.split(" ")[:-1]
			soln_row = []
			for i in entries:
				soln_row.append(int(i))
			soln_matrix.append(soln_row)
		soln_matrices.append(soln_matrix)
	return soln_matrices

def rotate(soln):
	n = len(soln)
	out = [[0]*n for _ in range(n)]
	out_col = n-1
	for row in soln:
		out_row = 0
		for entry in row:
			out[out_row][out_col] = entry
			out_row+=1
		out_col-=1
	return out

def reflect(soln):
	n = len(soln)
	out = [[0]*n for _ in range(n)]
	i = 0
	for row in soln:
		j = 0
		for entry in row:
			out[j][i] = entry
			j+=1
		i+=1
	return out

# return the 8 isomorphic solutions
def get_isomorphs(soln):
	isomorphs = [soln]
	isomorphs.append(reflect(isomorphs[0]))
	for i in range(3):
		isomorphs.append(rotate(isomorphs[i*2]))
		isomorphs.append(reflect(isomorphs[i*2+2]))
	return isomorphs

def is_transform(soln,isomorphs):
	for i in isomorphs:
		if soln == i:
			return True
	return False



# n = int(sys.argv[1])
input = sys.stdin.read()

# split input by newlines and drop first & last entry
soln_strs = input.split("\n\n")[1:][:-1]
solns = get_2dlists(soln_strs)
i=0
print(solns)
print(len(solns))
while True:
	if i >= len(solns):
		break
	s = solns[i]
	isos = get_isomorphs(s)
	unique = [s]
	for s2 in solns:
		if not is_transform(s2, isos):
			unique.append(s2)
	solns = unique
	i+=1
print(solns)
print(len(solns))


# iterate through each solution; convert to a list of 2d lists of integers
# iterate thru each solution 2d list
#    construct each of its transformations
#    compare each transformation to each other solution; if its a match, remove the solution
# 



# n_solns = 0
# placements = list()
# for s in solns:
# 	clauses = s.split()
# 	if clauses:
# 		n_solns += 1
# 		# filter all but clauses corresponding to exact placements
# 		p = list(filter(lambda c: c[0] != "~" and c.upper().isupper() == False, clauses )) 
# 		placements.append(p)


# print("Number of Solutions: " + str(n_solns) + "\n")
# # print a readable chessboard
# for p in placements:
# 	for row in range(1,n+1):
# 		for col in range(1,n+1):
# 			if (str(row)+"."+str(col) in p):
# 				print("1", end =" ")
# 			else:
# 				print("0", end =" ")
# 		print() # newline
# 	print()