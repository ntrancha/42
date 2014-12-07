#/bin/sh

#COLOR LINUX
CBgrey="\033[1;30m"
CBred="\033[1;31m"
CBgreen="\033[1;32m"
CByellow="\033[1;33m"
CBbleu="\033[1;34m"
CBrose="\033[1;35m"
CBbleuc="\033[1;36m"
CBwhite="\033[1;37m"
#COLOR LINUX + GRAS
Cgrey="\033[0;30m"
Cred="\033[0;31m"
Cgreen="\033[0;32m"
Cyellow="\033[0;33m"
Cbleu="\033[0;34m"
Crose="\033[0;35m"
Cbleuc="\033[0;36m"
Cwhite="\033[0;37m"


if [ -z $3 ]
then
	if [ "$1" = "?" ]
	then
		echo "ft [dossier des .h] [dossier des .c]"
		exit
	fi
	if [ "$1" = "-?" ]
	then
		echo "ft [dossier des .h] [dossier des .c]"
		exit
	fi
	if [ "$1" = "-h" ]
	then
		echo "ft [dossier des .h] [dossier des .c]"
		exit
	fi
else
	echo "ft [dossier des .h] [dossier des .c]"
	exit
fi

dos=`pwd`
if [ -z $1 ]
	dosh=`pwd`
then
	dosh="`pwd`/$1"
	if [ -z $2 ]
	then
		dosc=`pwd`
	else
		dosc="`pwd`/$2"
	fi
fi

rm -rf .nk
cd $dosh
nh=`ls -l *.h | wc -l` 
cd $doc
nc=`ls -l *.c | wc -l` 
cd $dosh
na=`ls -l *.h | wc -l` 
def="def"
null=`grep -R "#ifn$def" * 1> ifndef.nk 2> /dev/null`
cat ifndef.nk | cut -d ":" -f 1 > h.nk
#echo "Fichier(s) Header(s)"
#echo "--------------------"
#cat h.nk
#echo -en "--------------------\n"
echo -en "" > f.nk
index=1
while [ $index -le $na ]
do
	file=`cat h.nk | awk 'NR == '$index'{print}'`
	fichier=`cat $file`
	nlines=`cat $file | wc -l`
	count=0
	while [ $count -le $nlines ]
	do
		line=`cat $file | awk 'NR == '$count'{print}'`
		tester=`echo $line | grep "\t" | wc -l`
		if [ $tester -eq 1 ]
		then
			tester2=`echo $line | grep ");" | wc -l`
			if [ $tester2 -eq 1 ]
			then
				l0=`echo "$line" | awk '{print $1}'`
				n0=`echo "$line" | awk '{print $1}' | wc -c`
				l1=`echo "$line" | awk '{print $2}'`
				n1=`echo "$line" | awk '{print $2}' | wc -c`
				l2=`echo "$line" | awk '{print $3}'`
				n2=`echo "$line" | awk '{print $3}' | wc -c`
				l3=`echo "$line" | awk '{print $4}'`
				n3=`echo "$line" | awk '{print $4}' | wc -c`
				l4=`echo "$line" | awk '{print $5}'`
				n4=`echo "$line" | awk '{print $5}' | wc -c`
				l5=`echo "$line" | awk '{print $6}'`
				n5=`echo "$line" | awk '{print $6}' | wc -c`
				echo "$l0" >> r.nk
				if [ $n1 -gt 0 ]
				then
					echo -en "$l1" >> f.nk
				fi
				if [ $n2 -gt 0 ]
				then
					echo -en " $l2" >> f.nk
				fi
				if [ $n3 -gt 0 ]
				then
					echo -en " $l3" >> f.nk
				fi
				if [ $n4 -gt 0 ]
				then
					echo -en " $l4" >> f.nk
				fi
				if [ $n5 -gt 0 ]
				then
					echo -en " $l5" >> f.nk
				fi
				echo -en "\n" >> f.nk
			fi
		fi
		count=`expr $count + 1`
	done
	index=`expr $index + 1`
done
index=1
na=`cat f.nk | wc -l`
oldh=""
total=0
while [ $index -le $na ]
do
	line=`cat f.nk | awk 'NR == '$index'{print}'`
	retour=`cat r.nk | awk 'NR == '$index'{print}'`
	f=`echo $line | cut -d "(" -f 1`
	fs=`echo $f | cut -d "*" -f 2`
	fc=`echo $f | wc -c`
	fsc=`echo $fs | wc -c`
	oldt=`grep "$fs(" *.h | cut -d : -f 1`
	total=`expr $total + 1`
	#FICHIER .H
	if [ "$oldt" != "$oldh" ]
	then
		echo -en "\n${Cbleuc}\t"
		fichierh=`grep "$fs(" *.h | cut -d : -f 1`
		ft=`grep ");" $fichierh | wc -l`
		echo -en "$fichierh ${Cwhite}(${CBred}${ft}${Cwhite})\n"
		oldh=`grep "$fs(" *.h | cut -d : -f 1`
	fi
	#RETOUR
	echo -en "${CBgreen}$retour\t\t"
	#FONCTION
	if [ $fc -eq $fsc ]
	then
		echo -en " "
	else
		echo -en "${CBwhite}*"
	fi
	echo -en "${CByellow}$fs${Cwhite}"
	#PARAMETRE
	echo -en "${CBwhite}( "
	p0=`echo $line | cut -d "(" -f 2`
	p=`echo $p0 | cut -d ")" -f 1`
	p1=`echo $p | cut -d "," -f 1`
	p2=`echo $p | cut -d "," -f 2`
	p3=`echo $p | cut -d "," -f 3`
	p4=`echo $p | cut -d "," -f 4`
	p5=`echo $p | cut -d "," -f 5`
	pn1=`echo $p1 | wc -c`
	pn2=`echo $p2 | wc -c`
	pn3=`echo $p3 | wc -c`
	pn4=`echo $p4 | wc -c`
	pn5=`echo $p5 | wc -c`
	p11=`echo $p1 | cut -d " " -f 1`
	p12=`echo $p1 | cut -d " " -f 2`
	echo -en "${Cgreen}$p11 ${Cwhite}$p12${CBwhite}"
	if [ "$p1" != "$p2" ]
	then
		p21=`echo $p2 | cut -d " " -f 1`
		p22=`echo $p2 | cut -d " " -f 2`
		echo -en ", ${Cgreen}$p21 ${Cwhite}$p22${CBwhite}"
		if [ "$p3" != "$p2" ]
		then
			if [ "$p3" != "$p4" ]
			then
				echo -en ", "
			fi
			p31=`echo $p3 | cut -d " " -f 1`
			p32=`echo $p3 | cut -d " " -f 2`
			echo -en "${Cgreen}$p31 ${Cwhite}$p32${CBwhite}"
			if [ "$p3" != "$p4" ]
			then
				if [ "$p5" != "$p4" ]
				then
					echo -en ", "
				fi
				p41=`echo $p4 | cut -d " " -f 1`
				p42=`echo $p4 | cut -d " " -f 2`
				echo -en "${Cgreen}$p41 ${Cwhite}$p42${CBwhite}"
				if [ "$p5" != "$p4" ]
				then
					p51=`echo $p5 | cut -d " " -f 1`
					p52=`echo $p5 | cut -d " " -f 2`
					echo -en ", ${Cgreen}$p51 ${Cwhite}$p52${CBwhite}"
				fi
			fi
		fi
	else
		echo -en " "
	fi
	echo -en "${CBwhite})  [ "
	#POINT C
	cd $dosc
	grep "$fs" *.c | cut -d ":" -f 1 > c.nk
	lc=`cat c.nk | wc -l`
	count=0
	old=""
	while [ $count -le $lc ]
	do
		pointc=`cat c.nk | awk 'NR == '$count'{print}'`
		if [ "$pointc" = "$old" ]
		then
			old=`echo $pointc`
	else
			echo -en "${Cbleu}$pointc "
		fi
		count=`expr $count + 1`
		old=`echo $pointc`
	done
	if [ $count -eq 0 ]
	then
		echo -en "${CBred}X "
	fi
	echo -en "${CBwhite}]"
	echo -en "\n"
	index=`expr $index + 1`
done
rm -rf *.nk
cd $dosh
rm -rf *.nk
cd $dos
rm -rf *.nk
echo -en "${Cwhite}total: $total fonction(s).\n"
