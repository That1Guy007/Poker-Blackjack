all: Poker

Poker: Card.o Deck.o Print.o Poker.o Main.o
	g++ Card.o Deck.o Print.o Poker.o Main.o -o Poker    

Card.o: Card.cpp
	g++ -std=c++11 -c Card.cpp

Deck.o: Deck.cpp
	g++ -std=c++11 -c Deck.cpp

Print.o: Print.cpp
	g++ -std=c++11 -c Print.cpp
	
Poker.o: Poker.cpp
	g++ -std=c++11 -c Poker.cpp

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp
