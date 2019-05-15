awk '
BEGIN {
	while(getline < ARGV[1]){
		English[++n] = $1
		Chinese[n] = $2
	}

	ARGV[1] = "-"
	srand() 
	question()
}

{
	if($1 != English[ind]){
		print "Try again! Or help"
		getline
		if($1 == "help"){
			printf("%s english is %s",Chinese[ind], English[ind])
			$1 = English[ind]
		}
	}
	else{
		print "\nYou are right !! Press Enter to Continue --- "
		getline
		question()
	}
}

function question(){
	ind = int(rand()* n) + 1
	system("clear")
	print " Press \"ctrl-d\" to exit"
	printf("\n%s ", Chinese[ind] " 的英文生字是: ")
}
' $*