#! /usr/bin/python

import tweepy
import time
from tweepy import OAuthHandler

import numpy
import json
import re

#Variables that contains the user credentials to access Twitter API 
access_token = "827268804359053313-8j4xGXrMnsunJGNt5jAiFaLjzEK0zwN"
access_token_secret = "fyhey4tyQu5dWj2XsHpkvvyijBkZnmI1OIIynOda6bhs6"
consumer_key = "ZdLJZz2T4fLTFaEgc0piD1rvF"
consumer_secret = "qGEqPv4dn537sAEgPmdir2a30tkG4s66PghiYKclA1CpA0lFZM"

def APIsetup():
	auth = OAuthHandler(consumer_key, consumer_secret)
	auth.set_access_token(access_token, access_token_secret)

	api = tweepy.API(auth)
	return api

def getFollowers(api, user):
	f = open("mlnFollowers",'w')
	users = []
	i=0
	for page in tweepy.Cursor(api.followers, screen_name=user,count=200).pages():
		print(str(i))
		i=i+1
		users.extend(page)
	for j in users:
		f.write(str(j.followers_count) + "\n")
		print(j.followers_count)
	
	#comp = getStat(users)
	#f.write("\n Mean and std dev:\n")
	#f.write(str(comp))

def getStat(data):
	stats = []

	stats.append(numpy.mean(data))
	stats.append(numpy.std(data))

	return stats
