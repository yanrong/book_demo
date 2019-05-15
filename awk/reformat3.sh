#!/bin/bash
#

awk '
	BEGIN{
		FS="[ \t:]+"
		"date" | getline
		print " Today is ", $2 ,$3 > "today_rpt3"
		print " ===================" > "today_rpt3"
		print " ID Number Arrival Time" > "today_rpt3"
		close("today_rpt3")
	}

	{
		arrival = HM_to_M($2, $3)
		printf(" %s %s:%s:%s %s\n", $1, $2, $3, $4, arrival > 460 ?"*":" " )| \
		"sort -k 1 >> today_rpt3"
		total += arrival
	}

	END{
		close("today_rpt3")
		close("sort -k 1 >> today_rpt3")
		printf( "Average arrival time : %d:%d\n", total/NR/60, \
		(total/NR)% 60) >> "today_rpt3"
	}

	function HM_to_M(hour, min){
		return hour*60 + min
	}
' $*