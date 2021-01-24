#! /usr/bin/python

import recommendations as re
data = re.loadMovieLens()

itemsim=re.getRecommendations(data,'73')

f = open("Best & Worst Recommendations",'w')

f.write("-----------------------------\n")
f.write("Top 5 Recommendations\n")
f.write("-----------------------------\n")

f.write("Predicted Rating\tMovie")
for i in itemsim[0:5]:
	f.write("\n" + str(round(i[0],2)) + "\t\t\t\t\t" +i[1] )

itemsim.reverse()

f.write("\n\n-----------------------------\n")
f.write("Bottom 5 Recommendations\n")
f.write("-----------------------------\n")

f.write("Predicted Rating\tMovie")
for i in itemsim[0:5]:
	f.write("\n" + str(round(i[0],2)) + "\t\t\t\t\t" +i[1] )

