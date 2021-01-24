#! /usr/bin/python

import urllib
import json
import datetime as dt
import subprocess

def creationDate(res):
	ecd = res['Estimated Creation Date']
	return ecd

def extractCreationDate(carbonDateContent):
	dates=[]
	for c in carbonDateContent:
		jdata = json.loads(c)
		print(jdata['Estimated Creation Date'])
		date = creationDate(jdata)
		dates.append(date)
	return dates

def saveCreationDates(dates, filename):
	f = open(filename,'w')
	for d in dates:
		f.write(d + "\n")

 
def dayDiff(dates):
 	f = open('DaysSinceCreation','w')
 	for d in dates:
 		day = dt.date( int(d[:4]), int(d[5:7]), int(d[8:10]) )
 		today = dt.date.today()
 		diff = today-day
 		f.write(str(diff.days)+"\n")

def carbonDate(filename):
	cd = []
	f = open(filename, 'r')
	for link in f:
		print("Carbon dating link : " + link)
		#bashCommand = "http://localhost:8888/cd?url=" + link
		#process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
		#output, error = process.communicate()
		
		res = urllib.urlopen("http://localhost:8888/cd?url=" + link)
		
		out = json.dumps(res.read())
		out = json.loads(out)
		
		cd.append(out)
	return cd
