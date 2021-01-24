#! /usr/bin/python3
import subprocess as sp
import urllib.request 
from bs4 import BeautifulSoup as bs
import json 
import re


def getProcessedHTML(filename):
	print ("inside getProcessedHTML")
	f = open(filename,'r')
	o1 = open("Raw",'w')
	o2 = open("Processed",'w')
	i=0
	
	for line in f:
		print ("Link " + str(i))
		i = i+1
		rawHTML = getHTML(line)
		processedHTML = getText(rawHTML)	

		o1.write(str(rawHTML)+"\n")		
		o2.write(str(processedHTML)+"\n"	)				

def getHTML(uri):
	print ("inside getHTML")

	req = urllib.request.Request(uri, headers={'User-Agent': 'Mozilla/4.0'})
	try: res = urllib.request.urlopen(req) 
	except urllib.error.URLError as e:
		print(e.reason)	
		return ""
		#html = res.read()	
		#print (html)
	return res.read()

def visible(element):
	#print ("inside visible\n")
	if element.parent.name in ['style', 'script', '[document]', 'head', 'title']:
		return False
	elif re.match('<!--.*-->', str(element)):return False
	return True

def getText(html):
	print ("inside getText")
	soup = bs(html,'html.parser')
	texts = soup.findAll(text=True)
	visibleText = list(filter(visible,texts))

	return visibleText
