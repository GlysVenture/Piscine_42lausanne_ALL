ifconfig -a link | grep ether | sed 's/ether//g' | tr -d ' ' | tr -d '	'
