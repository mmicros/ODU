	#! /usr/bin/python
import urllib

def memSum(links):
	sum = []
	for link in links:
		i = 0
		prefix = 'http://memgator.cs.odu.edu/timemap/link/'
		res = urllib.urlopen(prefix+link)
		print (res.getcode())
		if res.getcode() == 200:
			for line in res.readlines():
				if 'memento' in line: 
					i = i+1
			sum.append(i)
		else: sum.append(0)
	return sum	

def getMementoSum(filename):
	f = open(filename,'r')
	links = []
	while True:
		line = f.readline()
		if not line: break
		links.append(line)
	mementos = memSum(links)
	print (mementos)
	return mementos

def saveSum(mem,filename):
	f=open(filename, 'w')
	for i in mem:
		f.write(str(i)+"\n")

