import sys

input = sys.stdin.read()

words = input.split("resultdimacs: ")

# transform comment lines into dictionary
translator = dict()
commentlines = list(filter(lambda x: len(x) != 0 and x[0] == "c", words[0].split("\n"))) 
for c in commentlines:
	if "->" in c:
		items = c[2:].split('->') # chop off first two chars & split by the arrow
		sat = items[0].strip()
		dimacs = int(items[1])
		translator[dimacs] = sat


# loop through each result & translate using dictionary
results = words[1].split(" 0\n")
numsat = len(results)-1 # remove empty trail
for n in range(numsat):
	clauses = results[n].split()
	# print("SOL_CODE:")
	for clause in clauses:
		c = int(clause.strip())
		neg = False
		if c < 0:
			c = -c
			neg = True
		if c in translator:
			sat_code = translator[c]
			to_add = "~"+sat_code if neg else sat_code
			print(" " + to_add + " ",end="")
	print("\n")
# print("NUMSAT: " +  str(numsat) )

# sys.stdout.write(sat_out)
