/*********************************************************\\
Print.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include <clocale>
#include <iostream>
#include "Print.h"

using namespace std;

print::print(){
	setlocale(LC_ALL, "");//trying to print out unicode ....
	deckObj.shuffle();
	deckObj.deal(5);
}

void print::printCard(){
  //edit to print for BJ
  //u know the suit and have it in the hand so take it from the hand and actually plug it into the string
  int modData;
  for(int cardLine = 0; cardLine < 45; cardLine++){
  	modData = cardLine % 5;
  	//find the card here instead of every line
    if(modData == 0){
      cout<<endl;
    }
    if(cardLine < 5){
      cout<< cardDesign[0] << " ";
    }
    else if(cardLine >= 5 && cardLine < 10){
		if(deckObj.getVal(modData) != 10){
			if(deckObj.getVal(modData) == 1){
			    cout<<"|A      | ";
			}
			else if(deckObj.getVal(modData) == 11){
				cout<<"|J      | ";
			}
			else if(deckObj.getVal(modData) == 12){
				cout<<"|Q      | ";
			}
			else if(deckObj.getVal(modData) == 13){
				cout<<"|K      | ";
			}
			else{
				cout<<"|"<<deckObj.getVal(modData)<<"      | ";
			}
		}
		else{
			cout<<"|"<<deckObj.getVal(modData)<<"     | ";
		}
    }
    //algorithm for cards which have two suits on a line
    //and which lines only have 1 suit
    else if(cardLine >=10 && cardLine <35){
      if((deckObj.getVal(modData) > 1 && deckObj.getVal(modData) <6)){
        cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
      }
      else{
      	if(deckObj.getVal(modData) == 6){
      		if(deckObj.getBool(modData)){
        		cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
			}
			else{
				deckObj.counterUp(modData);
        		cout<<"|  "<< deckObj.getSuit(modData)<< " " <<deckObj.getSuit(modData)<<"  | ";
        		
        		if(deckObj.getCounter(modData) + 5 == deckObj.getVal(modData)){
        			deckObj.setBool(modData, true);
        		}
			}
        }
		else if(deckObj.getVal(modData) == 7){
      		if(deckObj.getBool(modData)){
        		cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
			}
			else{
				deckObj.counterUp(modData);
        		cout<<"|  "<< deckObj.getSuit(modData)<< " " <<deckObj.getSuit(modData)<<"  | ";
        		
        		if(deckObj.getCounter(modData) + 5 == deckObj.getVal(modData)){
        			deckObj.setBool(modData, true);
        		}
			}
        }
        else if(deckObj.getVal(modData) == 8){
      		if(deckObj.getBool(modData)){
        		cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
			}
			else{
				deckObj.counterUp(modData);
        		cout<<"|  "<< deckObj.getSuit(modData)<< " " <<deckObj.getSuit(modData)<<"  | ";
        		
        		if(deckObj.getCounter(modData) + 5 == deckObj.getVal(modData)){
        			deckObj.setBool(modData, true);
        		}
			}
        }
        else if(deckObj.getVal(modData) == 9){
      		if(deckObj.getBool(modData)){
        		cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
			}
			else{
				deckObj.counterUp(modData);
        		cout<<"|  "<< deckObj.getSuit(modData)<< " " <<deckObj.getSuit(modData)<<"  | ";
        		
        		if(deckObj.getCounter(modData) + 5 == deckObj.getVal(modData)){
        			deckObj.setBool(modData, true);
        		}
			}
        }
        else if(deckObj.getVal(modData) == 10){
      		if(deckObj.getBool(modData)){
        		cout<<"|   "<< deckObj.getSuit(modData) <<"   | ";
			}
			else{
				deckObj.counterUp(modData);
        		cout<<"|  "<< deckObj.getSuit(modData)<< " " <<deckObj.getSuit(modData)<<"  | ";
        		
        		if(deckObj.getCounter(modData) + 5 == deckObj.getVal(modData)){
        			deckObj.setBool(modData, true);
        		}
			}
        }
        else{
        	cout<< cardDesign[1] << " ";
        }
      }
    }
    else if(cardLine >= 35 && cardLine < 40){
    	if(deckObj.getVal(modData) != 10){
			if(deckObj.getVal(modData) == 1){
			    cout<<"|      A| ";
			}
			else if(deckObj.getVal(modData) == 11){
				cout<<"|      J| ";
			}
			else if(deckObj.getVal(modData) == 12){
				cout<<"|      Q| ";
			}
			else if(deckObj.getVal(modData) == 13){
				cout<<"|      K| ";
			}
			else{
				cout<<"|      "<<deckObj.getVal(modData)<<"| ";
			}
		}
		else{
			cout<<"|"<<deckObj.getVal(modData)<<"     | ";
		}
    }
    else{
        cout<< cardDesign[0] << " ";
    }
  }
}
