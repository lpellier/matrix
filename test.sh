#!/bin/bash


RED="\e[31m"
GREEN="\e[32m"
CYAN="\e[36m"
BLUE="\e[34m"
MAGENTA="\e[35m"
RESET="\e[0m"

_execute() {
	clear
	g++ -Wall -Werror -Wextra -g3 --std=c++17 $1
	if [[ $? -ne 0 ]]; then
		return 1;
	fi
	./a.out
	rm -rf a.out*
}

if [[ $# -eq 1 && -f "$1" ]]; then
	_execute "$1"
else
	echo -e $CYAN"Enter the following :"
	echo -e $BLUE"path/to/test"$CYAN" -> $BLUE ./test tests/dot_product.cpp"
	exit
fi
