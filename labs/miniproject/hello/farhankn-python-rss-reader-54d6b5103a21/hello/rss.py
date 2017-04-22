import urllib2

response = urllib2.urlopen('http://expressindia.indianexpress.com/syndications/ei.xml')
mystring = response.read()



import re
mylist = re.sub("<.*?>", "\n", mystring)

print mylist

