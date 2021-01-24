#! /usr/bin/python

import recommendations as re
data,mov = re.loadMovieLens()

f = open("MY Correlated movies",'w')

sim = re.topMatches(data,'156')
top = sim[0:5]
bottom = sim[len(sim)-5:len(sim)]

f.write("My favorite movie : Reservoir Dogs (1992)\n")
f.write("-----------------------------\n")
f.write("Top 5 Correlations\n")
f.write("-----------------------------\n")

f.write("Corr\tMovie")
for i in top:
	f.write("\n" + str(round(i[0],2)) + "\t" +mov[i[1]] )

f.write("\n\n-----------------------------\n")
f.write("Bottom 5 Correlations\n")
f.write("-----------------------------\n")

f.write("Corr\tMovie")
for i in bottom:
	f.write("\n" + str(round(i[0],2)) + "\t" +mov[i[1]] )


sim = re.topMatches(data,'1162')
top = sim[0:5]
bottom = sim[len(sim)-5:len(sim)]

f.write("\n\n\n****************************************\n")

f.write("\n\n\nMy least favorite movie : Phat Beach (1996)\n")
f.write("-----------------------------\n")
f.write("Top 5 Correlations\n")
f.write("-----------------------------\n")

f.write("Corr\tMovie")
for i in top:
	f.write("\n" + str(round(i[0],2)) + "\t" +mov[i[1]] )

f.write("\n\n-----------------------------\n")
f.write("Bottom 5 Correlations\n")
f.write("-----------------------------\n")

f.write("Corr\tMovie")
for i in bottom:
	f.write("\n" + str(round(i[0],2)) + "\t" +mov[i[1]] )