numbers = [0,7,1,14,2,21,3]
print numbers
for n in numbers:
	print str(n) + "%7 = " + str(n%7)
	if(n%7 == 0):
		print "removing " + str(n) + " \n"
		numbers.remove(n)
print numbers
