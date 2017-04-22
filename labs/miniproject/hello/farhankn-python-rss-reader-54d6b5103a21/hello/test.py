from urllib import urlopen


source  = urlopen('http://expressindia.indianexpress.com/syndications/ei.xml').read()

print source
