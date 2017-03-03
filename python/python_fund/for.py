d = {'x':1,'y':2,'z':3}

for keys in d:
	print keys, 'corresponds to',d[keys]
print '='*20
names=['anne','beth','george','damon']
ages=[12,45,32,102]

for i in range(len(names)):
	print names[i], 'is', ages[i], 'years old'

print '='*20
for name,age in zip(names,ages):
	print name, 'is', age, 'years old'
print '='*20
# for index,string in enumerate(strings)
#	if 'xxx' in string
#		strings[indext]='[censored]'
#
