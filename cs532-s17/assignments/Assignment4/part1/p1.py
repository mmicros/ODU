#! /usr/bin/python
# coding: utf-8

import pygraphml as p
import re
import numpy

def readFriends(filename):
	f = open("graph",'w')

	parser = p.GraphMLParser()
	g = parser.parse(filename)

	nodes = g.nodes()
	print (len(nodes))
	j=0
	for node in nodes:
		f.write("Node "+ str(j)+"\n")
		j = j+1
		f.write(str(node)+"\n")


def getFriendCount(filename):
	fin = open(filename,'r')
	fout = open("Count",'w')
	friends = []
	for line in fin:
		
		if "mutual" in line: pass
		elif "friend_count" in line:
			line = re.sub(':','',line)
			line = line.split()
			fout.write(line[1] + "\n")
			friends.append(int(line[1]))
	comp = getStat(friends)

	fout.write("\n Mean and std dev:\n")
	fout.write(str(comp))

def getStat(data):
	stats = []

	stats.append(numpy.mean(data))
	stats.append(numpy.std(data))

	return stats