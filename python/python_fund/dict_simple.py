# A simple database

# A dictionary with person names as keys,Each person is represeted as
# another dictionary with the key 'phone'and 'addr' referring to their phone
#number and address,respectively

people = {
	'Alice':{'phone':'2341','addr':'Foo drive 23'},
	'Beth':{'phone':'9012','addr':'Bar street 42'},
	'Cecil':{'phone':'3158','addr':'Baz avenue 90'}	
}

#Descriptive labels for th phone number adn address,These will be used
#when printing the output

labels = {
	'phone':'Phone number',
	'addr':'address'
}

name = raw_input('Name: ')
#Are you looking for a phone number or an address

request = raw_input('Phone number(p) or address(a)?')

#using the correct key

if request == 'p':key = 'phone'
if request == 'a':key = 'addr'

# Only try to print infotmation if the name is valid key in
# our dictionary

if name in people: print"%s's %s is %s."% \
	(name,labels[key],people[name][key])
