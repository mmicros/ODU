#! /usr/bin/python

import recommendations as re
data = re.loadMovieLens()


matches = re.topMatches(data,'73')
top = matches[0:5]

f = open("Recommended Users",'w')
f.write("-----------------------------\n")
f.write("TOP 5 (Positive Correlation)\n")
f.write("-----------------------------\n")


f.write("\nUSER\tCorr\tCommon Rated Movies")


for i in top:
	sum = 0
	for j in data[i[1]].keys():	
		if j in data['73'].keys():
			sum = sum + 1
	f.write("\n" + str(i[1]) + "		" + str(round(i[0],2)) + "	" + str(sum) )

matches.reverse()
bottom = matches[0:5]

f.write("\n\n-------------------------------\n")
f.write("BOTTOM 5 (Negative Correlation)\n")
f.write("-------------------------------\n")

f.write("\nUSER\tCorr\tCommon Rated Movies")

for i in bottom:
	sum = 0
	for j in data[i[1]].keys():	
		if j in data['73'].keys():
			sum = sum + 1

	f.write("\n" + str(i[1]) + "		" + str(round(i[0],2)) + "	" + str(sum) )
