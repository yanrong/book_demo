def print_params(*params):
	print params

print '='*30
print_params(1,2,3)
print '='*30

def print_params_2(title,*params):
	print title
	print params

print '='*30
print_params_2('Params',1,2,3)
print_params_2('Nothings:')
print '='*30

para_tuple=(1,2,3,4,5)
print_params_2('pass s tuple directly',para_tuple)
print '='*30

def print_params_3(**params):
	print params

print '='*30
print_params_3(x=1,y=2,z=3)

print '='*30
def print_params_4(x,y,z=3,*pospar,**keypar):
	print x,y,z
	print pospar
	print keypar

print '='*30
print_params_4(1,2,3,4,5,6,7,foo=1,bar=2)
print
print_params_4(1,2)
print '='*30


