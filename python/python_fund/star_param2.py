def add(x,y):return x+y

params = (1,2)
print add(*params)

def hello(**params):
	print params
print '='*30
params = {'name':'Sir Robin','greeting':'Well met'}

hello(**params)

def with_stars(**kwds):
	print kwds['name'],'is',kwds['age'],'year old'
def without_stars(kwds):
	print kwds['name'],'is',kwds['age'],'years old'

args = {'name':'Mr Gumby','age':42}
print '='*30

with_stars(**args)
without_stars(args)
