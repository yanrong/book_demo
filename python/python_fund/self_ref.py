# self method reference

class Class:
	def method(self):
		print 'i hava a self'

def function():
	print 'i don\'t have'

instance=Class()
instance.method()
print '='*20
instance.method=function
instance.method()
##########################################
print '='*20
class Bird:
	song='Squaawk'
	def sing(self):
		print self.song

bird=Bird()
bird.sing()
print '='*20
birdsong=bird.sing
birdsong()
###print birdsing=bird.sing
############################################
class Secretive:
	def _inaccessible(self):
		print 'Bet you can\'t see me...'
	def accessible(self):
		print "The secret messaget is:"
		self._inaccessible()
print '='*20
s = Secretive()
#s._inaccessible()
s.accessible()
