#Import the necessary methods from tweepy library
#! /usr/bin/python

from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream

import urllib
import json
import re

#Variables that contains the user credentials to access Twitter API 
access_token = "827268804359053313-8j4xGXrMnsunJGNt5jAiFaLjzEK0zwN"
access_token_secret = "fyhey4tyQu5dWj2XsHpkvvyijBkZnmI1OIIynOda6bhs6"
consumer_key = "ZdLJZz2T4fLTFaEgc0piD1rvF"
consumer_secret = "qGEqPv4dn537sAEgPmdir2a30tkG4s66PghiYKclA1CpA0lFZM"


#This is a basic listener that just prints received tweets to stdout.
class StdOutListener(StreamListener):

	rawData = []
	jDatas = []
	numTweets = 0

	def __init__(self, noTweets):
		self.numTweets = noTweets

	def on_data(self, data):
		print str(len(self.rawData)) + " " + str(len(self.jDatas))
		self.rawData.append(data)
		self.parseData(data)        
		return len(self.jDatas) < self.numTweets

	def on_error(self, status):
		print status
    
	def parseData(self, data):
		jdata = json.loads(data)
		if 'possibly_sensitive' in jdata.keys():
			self.jDatas.append(jdata)

def saveUris(uris, filename):
	print("Saving uris to "+ filename)
	f = open(filename, 'w')
	for uri in uris:
		f.write(uri+'\n')
	f.close()

def getAllTheFinalURI(links):
	uris = []
	cnt = 0
	print("Getting 1000 unique uris ... \n")
	for link in links:
		try:
			uri = getFinalURI(link)
			print uri		
			if 'twitter' not in uri:
				print ("Good Link")
				if not(uri in uris):
					uris.append(uri)
					cnt = cnt +1
				if cnt == 1000:
					break
			else:
				print ("Twitter Link")
		except:
			i = 0            
	return uris

def getFinalURI(link):
	try:
		url = urllib.urlopen(link)
		return url.geturl()
	except:
		return ""        

def extractLinksFromTweets(tweets):
	links = []
	print("Extracting links...\n")
	for tweet in tweets:
		link = extractLinkFromTweet(tweet)
		links.append(link)
	print("Done extracting!\n")
	return links

def extractLinkFromTweet(tweet):
	link = ""
	if 'retweeted_status' in tweet:
		link = extractLink(tweet['retweeted_status']['text'])
	else:
		link = extractLink(tweet['text'])

	return link
		

def extractLink(text):
		regex = r'https?://t.co/[^\s]*'
		match = re.search(regex, text)
		if match:
			return match.group()
		return ''

def saveTweets(tweets, filename):
	print("Saving tweets to "+ filename)
	f = open(filename, 'w')
	for tweet in tweets:
		json.dump(tweet, f)
		f.write('\n')
	print("\nDone saving!\n")
	f.close()

def loadTweets(filename):
	print("Loading tweets from "+ filename)
	f = open(filename, 'r')
	jData = []
	for i in f:    
		jData.append(json.loads(i))
	f.close()
	print("\nDone loading!\n")
	return jData

def collectTheTweets(noTweets):
    #This handles Twitter authetification and the connection to Twitter Streaming API
	l = StdOutListener(noTweets)
	auth = OAuthHandler(consumer_key, consumer_secret)
	auth.set_access_token(access_token, access_token_secret)
	stream = Stream(auth, l)

    #This line filter Twitter Streams to capture data by the keywords: 'python', 'javascript', 'ruby'
	stream.filter(track=['kexp', 'Rick and Morty', 'Game of Thrones', 'Ashton Kutcher', 'Richard Wolff', 'cnn', 'time', 'articles','Matt Taibbi'])
	return l.jDatas