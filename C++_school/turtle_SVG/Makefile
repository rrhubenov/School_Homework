#--------------------------------
# NAME: Radoslav Hubenov
# CLASS: XIa
# NUMBER: 22
# PROBLEM: 1
# FILE NAME: Makefile
# FILE PURPOSE:
# Makefile that will create the object files and compile
#--------------------------------

CC=clang++

CFLAGS=-c -Wall

all: hexagon star

hexagon: hexagon.o turtle.o turtleSVG.o
	$(CC) hexagon.o turtle.o turtleSVG.o -o hexagon

star: star.o turtle.o turtleSVG.o
	$(CC) star.o turtle.o turtleSVG.o -o star

hexagon.o: hexagon.cc
	$(CC) $(CFLAGS) hexagon.cc

star.o: star.cc
	$(CC) $(CFLAGS) star.cc

turtle.o: turtle.cc
	$(CC) $(CFLAGS) turtle.cc

turtleSVG.o: turtleSVG.cc
	$(CC) $(CFLAGS) turtleSVG.cc

clean:
	rm -rf *o hexagon star
	
