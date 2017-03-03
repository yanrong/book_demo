'''
word = 'dummy'

while word:
	word = raw_input('Please enter a word:')
	#do somethin with the word:
	print 'The word was '+ word
'''
'''
word = raw_input('Please enter a word: ')

while word:
	print 'The word was '+word
	word = raw_input('Please enter a word:')
'''

while True:
	word = raw_input('Please enter a word: ')
	if not word:break
	# do something
	print 'The word was '+word
