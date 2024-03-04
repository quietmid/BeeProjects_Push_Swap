#!/bin/bash

# Based on the push_swap tester by GEMARTIN. I wanted to have a tester that's a slightly shorter and personalized for myself to test my pushswap

# ---------------------------------- COLORS ----------------------------------------- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${YELLOW}"Push Swap Tester "${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};

# --------------------------------- Control Error ----------------------------------- #

FILE=$PWD/push_swap

# check if the program exist
if [ -f "$FILE" ]; then
	echo -n
else
	printf "${RED}THE PUSH_SWAP PROGRAM CAN'T BE FOUND D: ${DEF_COLOR}\n";
	exit 0
fi 

#
#if [ $1 == -v ];then
#if [ -z "$2" ];then
#	n=500;
#else
#	n=$2;
#fi
#ARG=$(ruby -e "puts (0..($n)).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./pro_checker $ARG
#exit 0
#fi

#if [ $1 == -v2 ];then
#ARG=$2; ./push_swap $ARG | ./pro_checker $ARG
#exit 0
#fi

# -z checks for if $1 is empty || -b checks for if the argument is valid
if [ -z "$1" ] || [ $1 != -b ]; then
printf ${BLUE}"\n--------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\tMISSING ARGUMENT OR INVALID ARGUMENT\t\n"${DEF_COLOR};
printf ${BLUE}"\n--------------------------------------------------------------\n"${DEF_COLOR};

ARG="a"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
else
	printf "${RED} 1.[KO] ${DEF_COLOR}\n";
fi

ARG="111a11"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}2.[KO] ${DEF_COLOR}\n";
fi

ARG="test test test"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}3.[KO] ${DEF_COLOR}\n";
fi

ARG="-01 0001 00001"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}4.[KO] ${DEF_COLOR}\n";
fi

ARG="11-01 2 -11"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}5.[KO] ${DEF_COLOR}\n";
fi

ARG="-11 2 -11"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}6.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}6.[KO] ${DEF_COLOR}\n";
fi

ARG="-2147483649"
printf "Argument: $ARG INT MIN ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}7.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}7.[KO] ${DEF_COLOR}\n";
fi

ARG="2147483648"
printf "Argument: $ARG INT MAX ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}8.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}8.[KO] ${DEF_COLOR}\n";
fi

ARG="1 -2 3 214a748"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}9.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}9.[KO] ${DEF_COLOR}\n";
fi

ARG="1 2 3 03 214"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}10.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}10.[KO] ${DEF_COLOR}\n";
fi

#ARG=" "
printf "Argument: space ${DEF_COLOR}\n"
output=$(./push_swap " " | ./checker_Mac " " 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}11.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}11.[KO] ${DEF_COLOR}\n";
fi

#ARG=""
printf "Argument:  empty ${DEF_COLOR}\n"
output=$(./push_swap "" | ./checker_Mac "" 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}12.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}12.[KO] ${DEF_COLOR}\n";
fi

ARG="+"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}13.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}13.[KO] ${DEF_COLOR}\n";
fi

ARG="999999999999999999999"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}14.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}14.[KO] ${DEF_COLOR}\n";
fi

ARG="-999999999999999999999"
printf "Argument: $ARG ${DEF_COLOR}\n"
output=$(./push_swap $ARG | ./checker_Mac $ARG 2>&1)
if [[ $output == "Error" ]]; then
	printf "${GREEN}15.[OK] ${DEF_COLOR}\n";
else
	printf "${RED}15.[KO] ${DEF_COLOR}\n";
fi

#--------------------------------------------- Basic Input ------------------------------------ #

printf ${BLUE}"\n--------------------------------------------------------------\n"${DEF_COLOR};
printf ${BLUE}"\n\t\t\tBasic Inputs\t\n"${DEF_COLOR};
printf ${BLUE}"\n--------------------------------------------------------------\n"${DEF_COLOR};

printf ${BLUE}"2 inputs\n"${DEF_COLOR};
ARG="2 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}";
else
	printf "${RED}1.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="4 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}";
else
	printf "${RED}2.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="-3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
	printf "${RED}3.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi
# THREE
printf ${BLUE}"3 inputs\n"${DEF_COLOR};
ARG="2 3 1";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}";
else
	printf "${RED}1.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="200 3 150";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}";
else
	printf "${RED}2.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="2 3 150";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 4 ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
	printf "${RED}3.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

#FIVE
printf ${BLUE}"5 inputs\n"${DEF_COLOR};

ARG="1 3 5 7 9";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}1.[OK] ${DEF_COLOR}";
else
	printf "${RED}1.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="2 1 7 5 9";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}2.[OK] ${DEF_COLOR}";
else
	printf "${RED}2.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="2 1 -7 5 -9";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}3.[OK] ${DEF_COLOR}";
else
	printf "${RED}3.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="3 1 5 42 29";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}4.[OK] ${DEF_COLOR}";
else
	printf "${RED}4.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

ARG="1 3 4 2 5";
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 13 ]; then
	printf "${GREEN}5.[OK] ${DEF_COLOR}";
else
	printf "${RED}5.[KO]${DEF_COLOR}";
	printf "${WHITE} TEST: ";
	echo -n "$ARG "
fi
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}[OK] \n${DEF_COLOR}";
else
	printf "${RED}[KO] \n${DEF_COLOR}";
fi

#ONE HUNDRED
printf ${BLUE}"100 inputs\n"${DEF_COLOR};

res_1=0
res_2=0
res_3=0
res_4=0
res_5=0
res_err=0
control=1
val=25
if [ $1 > 0 ]; then
	val=$1
fi
((val++))
cont=1
while [ $cont -lt $val ]
do
ARG=$(ruby -e "puts (00..99).to_a.shuffle.join(' ')");
S=$(./push_swap $ARG | ./checker_Mac $ARG)
if [ $S == "OK" ]; then
	printf "${GREEN}$cont.[OK]${DEF_COLOR}";
	control=2
else 
	printf "${RED}$cont.[KO]${DEF_COLOR}";
	control=3
fi
N=$(./push_swap $ARG | wc -l)
if [ $N -lt 701 ] && [ $control -eq 2 ]; then
	printf "${GREEN}[OK][5/5]${DEF_COLOR}";
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_1++))
elif [ $N -gt 700 ] && [ $N -lt 901 ] && [ $control -eq 2 ]; then
	printf "${YELLOW}[OK][4/5]${DEF_COLOR}";
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_2++))
elif [$N -gt 900] && [ $N -lt 1101 ] && [ $control -eq 2]; then
	printf "${RED}[KO][3/5]${DEF_COLOR}";
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_3++))
elif [ $N -gt 1100 ]  && [ $N -lt 1301 ] && [ $control -eq 2 ]; then
	printf "${RED}[KO][2/5]${DEF_COLOR}";
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";

	((res_4++))
elif [ $N -gt 1300 ] || [ $N -eq 1300 ] && [ $control -eq 2 ]; then
	printf "${RED}[KO][1/5]${DEF_COLOR}";
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_5++))
elif [ $control -eq 3 ]; then
	printf "${CYAN} Moves:$N${DEF_COLOR}\n";
	((res_err++))
fi
((cont++))
done

((val--))
printf	"${WHITE}\n\nTest ${DEF_COLOR}${GREEN}[5/5] ${WHITE}$res_1/$val"
if [ $res_1 == $val ]; then
	printf "${GREEN} Congrats , all tests with 100 inputs have been completed successfully 🥳✅"
fi
if [ $res_2 != 0 ]; then
printf	"${WHITE}\nTest ${DEF_COLOR}${YELLOW}[4/5] ${WHITE}$res_2/$val"
fi
if [ $res_3 != 0 ]; then
printf	"${WHITE}\nTest ${DEF_COLOR}${RED}[3/5] ${WHITE}$res_3/$val"
fi
if [ $res_4 != 0 ]; then
printf	"${WHITE}\nTest ${DEF_COLOR}${RED}[2/5] ${WHITE}$res_4/$val"
fi
if [ $res_5 != 0 ]; then
printf	"${WHITE}\nTest ${DEF_COLOR}${RED}[1/5] ${WHITE}$res_5/$val\n"
fi
if [ $res_err != 0 ]; then
printf	"${WHITE}\nTest ${DEF_COLOR}${RED}[NO SORTED] ${WHITE}$res_err/$val\n"
fi
if [ $res_1  != $val ]; then
	printf "${CYAN}\nCheck traces $PWD/traces.txt\n"
fi
#FIVE HUNDRED
#printf ${BLUE}"500 inputs\n"${DEF_COLOR};
fi