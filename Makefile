bin/main: src/* include/*
	g++ src/main.cpp src/gaal.cpp src/time_measure.cpp -o bin/main -g -Iinclude