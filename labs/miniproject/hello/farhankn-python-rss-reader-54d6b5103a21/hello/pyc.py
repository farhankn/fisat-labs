import pycurl


db = 'feeds.db'
f = open(db, 'w')
c = pycurl.Curl()
c.setopt(c.URL, 'http://expressindia.indianexpress.com/syndications/')
c.setopt(c.WRITEFUNCTION, db)
c.perform()
c.close()
f.close()
import re

source = buffer.getvalue()

print source
