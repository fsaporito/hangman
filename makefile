# C++ compiler
CC=/usr/bin/g++

# Output Path
OUT=./Bin

# Source Code
SOURCE = ./Src/main.cpp \
		 ./Src/hangman.cpp

# HEADERS
HEADERS = ./Src/main.hpp \
		 ./Src/hangman.hpp

# Prefix Path
PREFIX=/usr/local

# Software Name
NAME=hangman

# Compiler Flags:
# -O3  =>  Maximum Optimisation Level
# -finline_functions =>  Consider All Functions For Inlining
# -findirect-inlining => 
# -fexpensive-optimizations => Add More Minor TIme Consuming Optimisations
# -g => Adds Debug Informations To The Executable File
# -Wall => Turns On Most Of Compiler Warnings
# -iquote => Add The Following Dir To The Source Code Path
CFLAGS=-O3 -finline-functions -findirect-inlining -fexpensive-optimizations #-g -Wall


# Functions Source Code Files



# Make
all:
	make clean
	${CC} -o ${OUT}/${NAME} ${SOURCE} ${HEADERS} ${CFLAGS}
	cp ${OUT}/${NAME} ${NAME}
	
clean:
	-rm -f ${NAME}
	-rm -f ${OUT}/${NAME}

install:
	install -s ${OUT}/${NAME} ${PREFIX}/bin

uninstall:
	-rm -f ${PREFIX}/bin/${NAME}

