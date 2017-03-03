#recursive programming testing

def factorial(n):
	if n == 1:
		return 1
	else:
		return n*factorial(n-1)

print factorial(10)

def bin_search(seq,key,lower,upper):
	if lower == upper:
		assert key == seq[upper]
		return seq[upper]
	else:
		middle = (lower+upper)//2
		if key > seq[middle]:
			return bin_search(seq,key,middle+1,upper)
		else:
			return bin_search(seq,key,lower,middle)

seq=[34,67,5,8,100,95,58]
seq.sort()
result=bin_search(seq,34,0,len(seq))

if result:print 'found elements',result
