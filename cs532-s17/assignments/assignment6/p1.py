#! /usr/bin/python

#Import the necessary methods from tweepy library
import tweepy
from tweepy import OAuthHandler	
import re
import codecs
import time
import json

#Variables that contains the user credentials to access Twitter API 
access_token = "827268804359053313-8j4xGXrMnsunJGNt5jAiFaLjzEK0zwN"
access_token_secret = "fyhey4tyQu5dWj2XsHpkvvyijBkZnmI1OIIynOda6bhs6"
consumer_key = "ZdLJZz2T4fLTFaEgc0piD1rvF"
consumer_secret = "qGEqPv4dn537sAEgPmdir2a30tkG4s66PghiYKclA1CpA0lFZM"

def APIsetup():
	auth = OAuthHandler(consumer_key, consumer_secret)
	auth.set_access_token(access_token, access_token_secret)

	api = tweepy.API(auth,wait_on_rate_limit = True ,wait_on_rate_limit_notify = True)
	return api

def getFollowers(api, user):
	f1 = open("nodes",'w')
	f2 = open("links",'w')
	f1.write("name,followers\n")
	f2.write("source,target\n")
	users = []
	i=0

	# get all followers and inserts them in users[]
	for page in tweepy.Cursor(api.followers, screen_name=user,count=200).pages():
		print(str(i))
		i=i+1
		users.extend(page)


	# go through users[] and find followers_count
	for j in users:
		print (j.name)
		print(j.followers_count)
		f1.write((j.name).encode("UTF-8")+","+str(j.followers_count) +"\n")	
		f2.write("OKMotovlog,"+(j.name).encode("UTF-8")+"\n")

		i=0
		for k in users:

			if (k.screen_name <> j.screen_name):
				print(str(i))
				i=i+1
				print ("\nUSERS:\n" +j.screen_name)
				print (k.screen_name+"\n")

				a = api.show_friendship(source_screen_name=j.screen_name,
					target_screen_name=k.screen_name)
				if(a[0].followed_by == True or a[0].following == True ):
					f2.write((j.name).encode("UTF-8")+","+(j.name).encode("UTF-8"))