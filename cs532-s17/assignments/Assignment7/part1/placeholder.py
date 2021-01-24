#! /usr/bin/python

import recommendations as re

data = re.loadMovieLens()
f = open("Alter Egos",'w')

alterEgos = []
for line in open('./data/u.user'):
	u = ( id, age, gender, occupation, zip)=line.split('|')[0:5]
	
	if (u[2]=='M' and u[1]=='24' and u[3]=='student') :
		alterEgos.append(u)

for i in alterEgos[0:3]:
	f.write("\n\n-------------------------------\n")
	f.write("User : " )
	f.write (str(i[0:4])+"\n")

	top =[]
	bottom=[]
	rated = []
	
	for j,k in (data[i[0]].items()):
		rated.append((j,k))

	ascending = sorted(rated, key=lambda student: student[1])
	bottom = ascending[0:5]
	descending = list(reversed(ascending))
	top = descending[0:5]

	f.write ("\nTop : ")
	for i in top:
		f.write (str(i)+"\n")


	f.write ("\nBottom :")
	for i in bottom:
		f.write (str(i)+"\n")