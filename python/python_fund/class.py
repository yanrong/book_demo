# defintion a class

_metaclass_ = type # make sure we get new style classes

class person:
	def setName(self,name):
		self.name=name
	def getName(self):
		return self.name
	def greet(self):
		print "hello world! i'm %s."%self.name

foo=person()
foo.setName('Luck Skywalter')
foo.greet()
