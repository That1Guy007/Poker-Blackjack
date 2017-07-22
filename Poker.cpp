/*********************************************************\\
Poker.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include "Poker.h"
#include <iostream>

using namespace std;

Poker::Poker(){
	
}


void Poker::pokerGame(){

int keep, tempV, choice = 1, bet, stack ,payout;//keep cards or not, tempV is temp var, choice to play game, the bet you place on the hand, and  your stack of chips
    card cards;
    deck objD;
	objD.shuffle();    
    cout<<"Welcome to my new and improved poker game!"<<endl<<endl;
    
    do{
    		cout<<"How much is your initial stack?: ";
    		cin>>stack;
    		if(stack < 0 || stack == NULL){
    			cout<<endl<<"Error: incorrect amount for stack"<<endl;
    		}
    	}while(stack == NULL || stack <= 0);
    
    while (choice != 0){

    	objD.deal(5, -1);
    	print objP(objD);//pass deck into the constructors of the print class by reference
		cout<<"Your Hand:"<<endl;
        objP.printCard(objD);
        
		do{
			cout<<"\nHow much would you like to bet on this hand?:";
			cin>>bet;
			if(bet>stack){
				cout<<endl<<"Error: betting more than you have in your stack: " << stack<< endl;
			}
		}while (bet> stack);	
	//need to rigg hand for testing	
			
        //resend object????
		cout<<endl<<"Would you like to keep the "<<objD.getVal(0)<< " of "<<objD.getSuit(0)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		//adding a function to redeal the card or not
		objD.reDeal(keep, 0);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(1)<< " of "<<objD.getSuit(1)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 1);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(2)<< " of "<<objD.getSuit(2)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 2);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(3)<< " of "<<objD.getSuit(3)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 3);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(4)<< " of "<<objD.getSuit(4)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 4);
		objP.printCard(objD);//print needs the updated object sent to it? why idk but it works		
		
		cout<<endl;
		
		if ((objD.getVal(0)+1) == (objD.getVal(1)) && (objD.getVal(1) +1) == objD.getVal(2) && (objD.getVal(2) +1) == objD.getVal(3)&&(objD.getVal(3) +1) == objD.getVal(4) || objD.getVal(0) +9 == objD.getVal(1)){ // checks on the royal striaght flush, striaght flush, straight
					  if (objD.getSuit(0) == objD.getSuit(1) && objD.getSuit(0) == objD.getSuit(2) && objD.getSuit(0) == objD.getSuit(3) &&  objD.getSuit(0) == objD.getSuit(4)){
						  if ((objD.getVal(0) == 1 || objD.getVal(0) == 10) && objD.getVal(4) == 12){ //changed from 13 to 12
							  cout << "You drew a Royal Flush!!"<<endl;
							  payout= bet * 10000;
							  stack = stack + payout;
						  }
						  else{
						  cout << "The straight flush" << endl;
						  payout = bet *1000;
						  stack = stack + payout;
						  }
					  }
					  
					 else {
					 cout<< "You got a straight"<<endl;
					  payout = bet * 6;
					  stack = stack + payout;
					 }
			}
			  else if (objD.getSuit(0) == objD.getSuit(1) && objD.getSuit(0) == objD.getSuit(2) && objD.getSuit(0) == objD.getSuit(3) &&  objD.getSuit(0) == objD.getSuit(4)){ //checks on the flush
					cout<<"you got a flush"<<endl;  
					payout = bet * 8;
					stack = stack + payout;
			  }
			  else if (objD.getVal(0) == objD.getVal(1)){ // checks on two pair, four of a kind, full house, trips and pair
				  if(objD.getVal(0) ==objD.getVal(2)){
					  if(objD.getVal(0) == objD.getVal(3)){
						cout<<"Four of a kind!"<<endl;  
						payout = bet * 20;
						stack = stack + payout;
					  }
					  else if(objD.getVal(3)==objD.getVal(4)){
						cout<<"Full House!!!"<<endl;  
						payout = bet * 10;
						stack = stack + payout;
					  }
					  else{
					  cout<<"You have trips"<<endl;
					  payout = bet * 4;
					  stack = stack + payout;
					  }
				  }
				  else if(objD.getVal(2) == objD.getVal(3) || objD.getVal(3) == objD.getVal(4)){
					  cout<<"You have two pair"<<endl;
					  payout = bet * 2;
					  stack = stack + payout;
				  }

			     else  if(objD.getVal(1) == objD.getVal(2)){
					  cout<<"You have two pair"<<endl;
					  payout = bet *2;
					  stack = stack + payout;
				  }
				  else{
					  cout<<"You have one pair"<<endl;
				  payout = bet;
				  stack = stack + payout;
				  }
			  }
			  else if(objD.getVal(1) == objD.getVal(2) ){ // checks on 4 of a kind, trips, two pair, and pair
				   if(objD.getVal(1) == objD.getVal(3) ){
					   if(objD.getVal(1) == objD.getVal(4)){
						   cout<<"You have four of a kind"<<endl;
						   payout = bet *20;
						   stack = stack + payout;
					   }
					   cout<<"You have trips"<<endl;
					   payout = bet *4;
					   stack = stack + payout;
				   }
				   else if(objD.getVal(3) == objD.getVal(4)){
					  cout<<"You have two pair"<<endl;
					  payout = bet *2;
					  stack = stack + payout;
					  
				  }
				 else{
					 cout<<"You have one pair"<<endl;
				  payout = bet;
				  stack = stack + payout;
				 }
			  }
			  else if(objD.getVal(2) == objD.getVal(3)){ // checks on trips and pair 
				  
				  if(objD.getVal(2) == objD.getVal(4)){
					  cout<<"You have trips"<<endl;
					  payout = bet *4;
					  stack = stack + payout;
				  }
				  else{ 
					  cout<<"You have one pair"<<endl;
				  payout = bet;
				  stack = stack + payout;
				  }
			  }
			  else if(objD.getVal(3) == objD.getVal(4)){ // checks for a pair
				  cout<<"You have one pair"<<endl;
				  payout = bet;
				  stack = stack + payout;
			  }
			  else{ // checks for a high card
				  cout << "You have a High card"<<endl;
				  payout = bet;
				  stack = stack + payout;
			  }
		cout<<"Your current balance is: "<< stack<<"\nYou gained: "<<payout<<"\nWould you like to keep playing?  ";
		cin>>choice;
	}
}
