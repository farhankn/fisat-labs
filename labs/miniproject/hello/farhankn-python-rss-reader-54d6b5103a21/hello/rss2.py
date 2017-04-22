# http://expressindia.indianexpress.com/syndications/

from urllib import urlopen
import re

source  = urlopen('http://expressindia.indianexpress.com/syndications/ei.xml').read()

title = re.compile('<title>(.*)</title>')
link = re.compile('<link>(.*)</link>')

find_title = re.findall(title, source)
find_link = re.findall(link, source)



for i in range(1, 8):
    print find_title[i]
    print find_link[i]
    print "\n"

