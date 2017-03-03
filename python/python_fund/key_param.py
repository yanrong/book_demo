def hello_1(greeting,name):
	print '%s, %s'%(greeting,name)

def hello_2(name,greeting):
	print '%s, %s'%(name,greeting)

hello_1('Hello','yanrong')
hello_2('Hello','yanrong')
print 
hello_1(greeting='Hello',name='world')
hello_1(name='world',greeting='Hello')
hello_2(name='Hello',greeting='world')
print 
#hello_2()
def hello_3(greeting='Hello',name='world'):
	print '%s, %s!'%(greeting,name)

hello_3()
hello_3(greeting='nice')
hello_3(name='Name',greeting='Nice')
print 

def hello_4(name,greeting='Hello',punctuation='!'):
	print '%s, %s%s'%(greeting,name,punctuation)

hello_4('Mars')
hello_4('Mars','Howdy')
hello_4('Mars','Howdy','...')
print 

hello_4('Mars',punctuation='.')
hello_4('Mars',greeting='Top of the morning to ya')

# got multiple values for keyword argument 'greeting'
# hello_4('Mars','must misunderstand',greeting='Top of the morning to ya')
# take a least parameters 
# hello_4()

