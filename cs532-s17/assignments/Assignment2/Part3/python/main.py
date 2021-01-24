#! /usr/bin/python

import part3 as p3

#dates = p3.extractCreationDate("nonZero")
#p3.saveCreationDates(dates,'result')
#p3.dayDiff(dates)

cd = p3.carbonDate("nonZero")
dates = p3.extractCreationDate(cd)
p3.dayDiff(dates)
p3.saveCreationDates(dates,"Dates")
