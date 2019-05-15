#!/bin.bash
#
awk '
BEGIN {
	sys_sort = "sort -k 1 >> today_rpt4"
	result = "today_rpt4"

	FS = "[ \t:]+"
	"date" | getline
	print " Today is ", $2, $3 	> result
	print "===================" > result
	print "ID number Arrival Time" > result
	close(result)
	#creat XXXlate.dat to store late record
	late_file = $2"late.dat"
	#value get dat from "late_file" ,  1 is success
	while( getline < late_file > 0)
		cnt[$1] = $2
	close(late_file)
}

{
	arrival = HM_to_M($2, $3)
	if( arrival > 460 || cnt[$1] > 0 ){
		mark = "*"
		cnt[$1]++
	}
	else mark = " "

	message = cnt[$1] ? cnt[$1] "times" : ""
	printf("%s %2d:%2d %5s %s\n", $1, $2, $3, mark,message) | sys_sort
	total += arrival
}

END{
	close(result)
	close(sys_sort)
	printf("Average arrival time : %d:%d\n", total/NR/60, (total/NR)%60) >> result
	for(any in cnt)
		print any, cnt[any] > late_file
}
function HM_to_M(hour, min){
	return hour*60 + min
}
' $*