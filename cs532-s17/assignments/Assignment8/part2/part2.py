#! /usr/bin/python 

import clusters
blognames,words,data=clusters.readfile('blogdata2.txt') 
clust=clusters.hcluster(data) 
clusters.drawdendrogram(clust,blognames,jpeg='blogclust.jpg') 
