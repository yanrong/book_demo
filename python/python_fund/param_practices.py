# practice parameter's various style in python
def foo(x,y,z,m=0,n=0):
	print x,y,z,m,n

def call_foo(*args,**kwds):
	print "Calling foo!"
	foo(*args,**kwds)

def story(**kwds):
	return 'Once upon a time,there was a' \
	'%(job)s called %(name)s.'%kwds

def power(x,y,*others):
	if others:
		print 'Receive redundant parameters:',others
	return pow(x,y)

def interval(start,stop=None,step=1):
	'Initates range() for step > 0'
	if stop is None: 	# if the stop is no supplied...
		start,stop = 0,start	# shuffle the parameters
	result = []
	i = start
	while i < stop:
		result.append(i)
		i+=step
	return result

print '='*30

print story(job='king',name='Gumby')
print story(name='Sir Robin',job='brave knight')

params={'job':'Language','name':'Python'}

print '='*30
print story(**params)
del params['job']
print story(job='stroke of genius',**params)

print '='*30
print power(2,3)
print power(3,2)
print power(y=3,x=2)
print power(3,3,'hello world')

print '='*30
print interval(10)
print power(*interval(3,7))

print '='*30
print interval(1,5)
print interval(3,12,4)

print '='*30
args=3,6,9
kwds={'n':32,'m':9}
call_foo(*args,**kwds)

