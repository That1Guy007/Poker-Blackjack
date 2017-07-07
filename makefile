all: Poker

Poker: Card.o Deck.o Main.o
	g++ Card.o Deck.o Main.o -o Poker    

Card.o: Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.cpp
	g++ -c Deck.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
