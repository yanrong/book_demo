#parameter's scope 
#Test all variables that has defined in this function scope
scope=vars()

external='berry'

def combine(parameter):print parameter+external

combine('Black')

parameter='berry'

def combine_2(parameter):print parameter+globals()['parameter']

combine_2('Black')
x = 1
def change_global():
	global x
	x=x+1
	return x

print 'global variable x has not changed is:',x
print 'global variable x has changed is:',change_global()

