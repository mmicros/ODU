#! /usr/bin/python 
import feedparser
import feedfilter
import docclass
import random
import re
cl=docclass.fisherclassifier(docclass.getwords)
cl.setdb('hotHand.db')

feed = "blogFeeds.xml"
f=feedparser.parse(feed)
g = open("class.txt","r")

cat = [] 
for line in g:
  tmp = line.split(' ')[1].strip('\n')
  cat.append(tmp)

num = 90

def q1Train(f,cat,num,classifier):
  # Get feed entries and loop over them
  print "--- TRAINING  ---"
  for entry in f['entries']:
    i = f.entries.index(entry)
    if( i < num):
      print
      print '-----'
      print 'Title:     '+entry['title'].encode('utf-8')
      fulltext='%s\n%s' % (entry['title'],entry['summary'][0])
      print i
      classifier.train(fulltext, cat[i])

  for i in classifier.categories():
    classifier.setminimum(i,.16)

def q1Test(f,cat,num,classifier):
  print "--- TESTING  ---"
  h = open("table10.txt", "w")
  #h = open("table50.txt", "w")
  h.write("title,  pred, act\n")

  for entry in f['entries']:
    i = f.entries.index(entry)
    if( i >= num):
      print
      print '-----'
      print 'Title:     '+entry['title'].encode('utf-8')
      fulltext='%s\n%s' % (entry['title'],entry['summary'])
      print i
      a = feedfilter.entryfeatures(entry)
      b = random.randint(0,len(a)-1)
      c = ' '.join(a)
      #print a
      fulltext='%s\n%s' % (entry['title'],entry['summary'][0])
      # cls = classifier.classify(a.items()[b][0])
      # cls = classifier.classify(fulltext)
      cls = classifier.classify(fulltext)

      f.entries[i].pred = cls
      f.entries[i].cls = cat[i]

      print "Guess: "+str(cls)
      print "Actual: "+str(cat[i])

      fout = '%s, %s, %s\n' % (re.sub(r'[^\x00-\x7F]+', '', entry['title'][0:30]), cls, cat[i])
      h.write(fout)

def assess(f, num):
  tp, fp, fn = 0, 0, 0
  for i in range(num, 100):
    if(f.entries[i].pred == f.entries[i].cls):
      tp +=1
    if(f.entries[i].pred != f.entries[i].cls):
      fp +=1
    if(not f.entries[i].pred):
      fn +=1

  precision = float(tp)/(tp + fp)
  recall = float(tp)/(tp +fn)

  fmeasure = 2*(precision*recall)/(precision+recall)
  print "\n-----------------------------------------"
  print precision, recall
  print fmeasure
  print "-----------------------------------------\n"

q1Train(f, cat, num, cl)
q1Test(f, cat, num, cl)
assess(f,num)
