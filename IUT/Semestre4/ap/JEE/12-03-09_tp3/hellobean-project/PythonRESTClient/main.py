import urllib
import json

clientName = 'Vincent';

url = 'http://localhost:8080/HelloBeanREST/rest/hello/'+clientName;
u = urllib.urlopen(url)
# u is a file-like object
data = u.read()
deserialized = json.loads(data);
hellobean = deserialized['hellobean'];
hellomessage = hellobean['helloMsg']+hellobean['clientName'];
print hellomessage;

