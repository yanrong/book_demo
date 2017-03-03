#/usr/bin/env python

from random import randint
###############
#version 1
###############
#odd = lambda x: x%2

allNums = []
for eachNum in range(9):
	allNums.append(randint(1,99))

#print filter(odd,allNums)
#for i in range(9):
print filter(lambda x:x%2,allNums)

###-version 2-#######
print [n for n in allNums if n%2]

######-version 3-########
#from random import randint as ri
#print [n for n in[ri(1,99) for i in range(9)] if n%2]
#