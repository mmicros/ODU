days <- unlist(read.table("age.txt"))
num <- unlist(read.table("mem.txt"))

plot(days,num, log="xy", pch=20, col="red", xlab="Days since creation ", ylab="Num of Mementos",  main="Age vs # of Mementos")


