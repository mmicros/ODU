#! /usr/bin/python

import igraph
f1 = [1,2,3,4,5,6,7,8,9,11,12,13,14,17,18,20,22]
f2 = [10,15,16,19,21,23,24,25,26,27,28,29,30,31,32,33,34]

g = igraph.Graph.Read_GML("karate.gml")
layout=g.layout()
igraph.plot(g, 'Karate club.pdf',layout = layout,vertex_label=g.vs["id"])

colorDict = {"f2": "blue", "f1": "red"}
for v in g.vs:
	if v["id"] in f2:
		v["color"]= "blue"
	else:
		v["color"]= "red"

igraph.plot(g,'Karate club factions.pdf', layout = layout,vertex_label=g.vs["id"])



pred = g.community_edge_betweenness(clusters=2,directed=False)

predictedSplit=pred.as_clustering()
igraph.plot(predictedSplit,"prediction.pdf",layout=layout)