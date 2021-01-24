facebook <- unlist(read.table("p1.txt"))
twitter <- unlist(read.table("p2.txt"))

facebook = sort(facebook)
twitter = sort(twitter)+1

m = round(mean(facebook),2)
s = round(sd(facebook),2)
colors = c("skyblue2", "red","yellow")
cols = ifelse(
          (facebook == 164), colors[2],
          (ifelse(
            abs(facebook - m) < 2 , colors[3] , colors[1])))

barplot(facebook, 
        col= cols,
        border = NA , 
        ylim=c(0.8,5000), 
        xlim=c(0,180), 
        ylab="Number of friends" , 
        xaxt='n' , 
        main="Frienship paradox for Dr. Nelson's Facebook", 
        sub = paste("Michael Nelson =", 124," friends (Red)", "\nMean =", m, " friends (Yellow)", "\nStd Dev =", s) , 
        log='y')

m = round(mean(twitter),2)
s = round(sd(twitter),2)
cols = ifelse(
  (twitter == 625), colors[2],
  (ifelse(
    abs(twitter - m) < 10 , colors[3] , colors[1])))

barplot(twitter, 
        col= cols, 
        border = NA  ,
        xlim=c(0,length(twitter)+100),
        ylim=c(0.8,500000), 
        ylab="Number of Followers" , 
        xaxt='n',  
        main="Frienship paradox for Dr. Nelson's Twitter", 
        sub = paste("Michael Nelson =", 624," followers (Red)", "\nMean =", m, " followers (Yellow)", "\nStd Dev =", s) , 
        log='y')
