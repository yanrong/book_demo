print map(str, range(10))#equivalent to [str(i) for i in range(10)]
[str(i) for i in range(10)]
print map(int, range(10))
print
def func(x):
	return x.isalnum()

seq=["foo","x41","?!","***"]
print filter(func,seq)

[x for x in seq if x.isalnum()]
#lambda expression which let you define simple functions in line
#primary used with map filter and reduce
print filter(lambda x: x.isalnum(),seq)
print
numbers = [72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33]
print reduce(lambda x,y:x+y,numbers)
