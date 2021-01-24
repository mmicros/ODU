#!/usr/bin/env python

#Import the necessary methods from tweepy library
from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream
import re
import urllib2


#Variables that contains the user credentials to access Twitter API 
access_token = "827268804359053313-8j4xGXrMnsunJGNt5jAiFaLjzEK0zwN"
access_token_secret = "fyhey4tyQu5dWj2XsHpkvvyijBkZnmI1OIIynOda6bhs6"
consumer_key = "ZdLJZz2T4fLTFaEgc0piD1rvF"
consumer_secret = "qGEqPv4dn537sAEgPmdir2a30tkG4s66PghiYKclA1CpA0lFZM"
links = []
cnt=0

def extract_link(text):
    regex = r'https?://[^\s<>"]+|www\.[^\s<>"]+'
    match = re.search(regex, text)
    if match:
        return match.group()
    return ''

#This is a basic listener that just prints received tweets to stdout.
class StdOutListener(StreamListener):

	def on_data(self, data):
		global cnt
		lnk = extract_link(data)
	
		if lnk != "":
			linkReq = urllib.request.Request(lnk.get('href'))
			with urllib.request.urlopen(linkReq) as linkRes:
				if(linkRes.code == 200 ):
					links.append(lnk)
					cnt =cnt+1
					print("Link  : {} ".format(cnt))
					print("First URI : " + link.get('href'))
					print("Last URI  : {}".format(linkRes.geturl()))
		return True

	#links.append(lnk);
	#cnt =cnt+1
	#print("Link {} : {} ".format(cnt,lnk))


	def on_error(self, status):
		print (status)
		return 

if __name__ == '__main__':

    #This handles Twitter authetification and the connection to Twitter Streaming API
    l = StdOutListener()
    auth = OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_token_secret)
    stream = Stream(auth, l)


    #This line filter Twitter Streams to capture data by the keywords: 'python', 'javascript', 'ruby'
    stream.filter(track=["psychedelic rock", "drums", "Bonham","Greenwald"])

