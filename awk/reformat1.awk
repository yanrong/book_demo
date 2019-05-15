BEGIN{
	print "ID Number Arrival Time" > "today_rpt"
	print "=========================" > "today_rpt"
}

{ printf(" %s %s \n", $1, $2) > "today_rpt"}