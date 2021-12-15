#!/bin/bash
x=0
while [ $x -le 50 ]
do
	./tools/cc.sh > file
	var=$(cat file | grep "NB_actions" | cut -d ' ' -f3)
	tmp=$(cat file | awk 'NR==3{print}')
	ins=$(cat file | awk 'NR==5{print}')
	echo $(tput setaf 3) $tmp "$(tput setaf 7)nb_instructions" $var $(tput setaf 5)$ins
	var=$(( $var + 0))
	if [ $var -ge 914 ];
	then
		echo "$(tput setaf 1)KO"
		break
	else
		echo "$(tput setaf 2)OK"
		echo -n ""
	fi
	x=$(( x+1 ))
done
rm -f file
