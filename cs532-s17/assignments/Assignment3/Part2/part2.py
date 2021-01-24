#! /usr/bin/python3
import math

def getDF(term):
	f1 = open('Processed','r')
	f2 = open('links1000','r')
	df = 0
	uris = []
	numTerm = []
	numTotal = []
	tf = []
	for i in f1:
		uri = f2.readline()
		if term in i: 
			df = df+1
			uris.append(uri)
			termNum = i.lower().count(term.lower())
			totalNum = len(i.split())

			numTotal.append(totalNum)
			numTerm.append(termNum)
			tf.append(termNum/totalNum)

	write(uris, numTerm, numTotal)
	print("There are " + str(df) + " URIs that contain the term "+ term)
	return [uris, numTerm, numTotal]

def write(uris, numTerm, numTotal ):
	i=1
	f = open('result','w')
	f1 = open('TDIFD', 'w')
	f.write('{:<10s} {:<10s} {:<10s} {:<10s} {:<10s} {:<10s}'.format('Term','Total','TF','IDF','TFIDF','URIs'))
	f.write("\n")
	while i < len(uris):
		tf = numTerm[i]/numTotal[i]
		idf = math.log((20*10**9/(1.7*10**6) ),2)
		tfidf = tf*idf

		f.write('{:<10d} {:<10d} {:<10.4f} {:<10.4f} {:<10.4f} {:<100s}'.format(numTerm[i], 
			numTotal[i] ,tf, idf, tfidf, uris[i])) 
		f.write("\n")
		i = i+1
