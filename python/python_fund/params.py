# parameters testing

def init(data):
	data['first']={}
	data['middle']={}
	data['last']={}

def lookup(data,label,name):
	return data[label].get(name)

storage={}

init(storage)

my_sister = 'Anne Lie Hetland'
storage['first'].setdefault('Anne', []).append(my_sister)
storage['middle'].setdefault('Lie', []).append(my_sister)
storage['last'].setdefault('Hetland', []).append(my_sister)

#istorage

print lookup(storage,'first','Anne')
