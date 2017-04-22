# Simple RSS Feed Reader
# Using Feedparser: sudo pip install feedparser
import feedparser
print("Enter the RSS URL")
content = raw_input()

#Reading Content
d = feedparser.parse(content)
print("\nParsing Content, Please Wait")
print("\n Feed Name"+d['feed']['title'])
print(d['feed']['link'])

#Open File
db = 'feeds.db'
f = open(db, 'w')

#Write Content
for post in d.entries:
        f.write("Title: "+post.title + "|"  "\nLink: " +post.link + "\n")
f.close


print("\nSuccessfully Written Into File")


#End of Program
