# A simple database using get

# Insert database (people) from Listing 4-1 here.

labels = {
	'phone':'phone number',
	'addr':'address'
}

people = {}
name = raw_input('Name: ')
# Are we looking for a phone number or an address?
request = raw_input('Phone number(p) or address (a)?')

# Using the correct key

key=request # In case the request is neither 'p' nor 'a'

if request == 'p':key='phone'
if request == 'a':key='addr'

person = people.get(name,{})
label = labels.get(key,key)
result=person.get(key,'not available')

print "%s's %s is %s."%(name,label,result)

