#! /usr/bin/python

import tweepy_testing as tt

dd = tt.collectTheTweets(5000)
tt.saveTweets(dd,'tweets')
tweets = tt.loadTweets('tweets')
links = tt.extractLinksFromTweets(tweets)
finalURIs = tt.getAllTheFinalURI(links)
tt.saveUris(finalURIs, 'test')
