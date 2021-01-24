#!/usr/bin/env python

from bs4 import BeautifulSoup
import urllib.request
import sys

url=sys.argv[1]
#url = "http://www.cs.odu.edu/~mln/teaching/cs532-s16/test/pdfs.html"
req=urllib.request.Request(url)

with urllib.request.urlopen(req) as res:
	Html = res.read()
	soup = BeautifulSoup(Html,"html.parser")
	for link in soup.find_all('a'):
		linkReq = urllib.request.Request(link.get('href'))
		with urllib.request.urlopen(linkReq) as linkRes:
			if('pdf' in linkRes.info()['Content-Type'] and (linkRes.code== 200) ):
				print("First URI : " + link.get('href'))
				print("Last URI  : {}".format(linkRes.geturl()))
				print("Bytes: " + linkRes.info()['Content-length'] +"\n")
