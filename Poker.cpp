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

	//keep cards or not, tempV is temp var, choice to play game, the bet you place on the hand, stack of chips, payout
	int keep, tempV, choice = 1, bet, stack ,payout, rigged = 0;
    
    //object creation
    card cards; 
    deck objD;
    //shuffles the deck
    objD.shuffle();
    print objP(objD);//pass deck into the constructors of the print class by reference
    
    cout<<"Welcome to my new and improved poker game!"<<endl<<endl;
    
    //obtain information about the players initial status
    do{
    		cout<<"How much is your initial stack?: ";
    		cin>>stack;
    		if(stack < 0){ //what if its not a number or intiger for that matter?
    			cout<<endl<<"Error: incorrect amount for stack"<<endl;
    		}
    		else if (stack == 0){
    			rigged = 1;
    		}
    	}while(stack < 0);
    
    while (choice != 0){
		
		if(rigged == 0 ){
			//deal cards and ask player which cards to keep
    		objD.deal(5, -1);	
		
			cout<<"Your Hand:"<<endl;
        
        	objP.printCard(objD);
        
        	//ask how much they would like to place as a bet
			do{
				cout<<"\nHow much would you like to bet on this hand?:";
				cin>>bet;
				if(bet>stack){
					cout<<endl<<"Error: betting more than you have in your stack: " << stack<< endl;
				}
			}while (bet > stack);
		
			cout<<endl<<"Would you like to keep the "<<objD.getVal(0)<< " of "<<objD.getSuit(0)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
			cin>>keep;
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
		}
		else{
			bet = 0;
			cout<<"\nTesting initiated... What kind of rigged hand would you like?\n";
			cout<<"\n(1) royal straight flush, (2) straight flush, (3)Full House,\n(4)straight, (5)Flush, (6) Two pair,\n(7) Pair, (8) High Card :";
			cin>>tempV;
			objD.riggedH(tempV);
			objP.printCard(objD);
		}
		
		
		//complicated mess which determines what the cards in your hand make.
		
		// checks on the royal striaght flush, striaght flush, straight
		if ((objD.getVal(0)+1) == (objD.getVal(1)) && (objD.getVal(1) +1) == objD.getVal(2) && (objD.getVal(2) +1) == objD.getVal(3)&&(objD.getVal(3) +1) == objD.getVal(4) || objD.getVal(0) +9 == objD.getVal(1)){
		
					  if (objD.getSuit(0) == objD.getSuit(1) && objD.getSuit(0) == objD.getSuit(2) && objD.getSuit(0) == objD.getSuit(3) &&  objD.getSuit(0) == objD.getSuit(4)){
						  if ((objD.getVal(0) == 1 || objD.getVal(0) == 10) && objD.getVal(4) == 13){ 
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
			
				//checks on the flush
			  else if (objD.getSuit(0) == objD.getSuit(1) && objD.getSuit(0) == objD.getSuit(2) && objD.getSuit(0) == objD.getSuit(3) &&  objD.getSuit(0) == objD.getSuit(4)){ 
					cout<<"you got a flush"<<endl;  
					payout = bet * 8;
					stack = stack + payout;
			  }
			  
			  // checks on two pair, four of a kind, full house, trips and pair
			  else if (objD.getVal(0) == objD.getVal(1)){ 
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
			  
			  // checks on 4 of a kind, trips, two pair, and pair
			  else if(objD.getVal(1) == objD.getVal(2) ){ 
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
			  
			  // checks on trips and pair 
			  else if(objD.getVal(2) == objD.getVal(3)){
				  
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
			  
			  // checks for a pair
			  else if(objD.getVal(3) == objD.getVal(4)){ 
				  cout<<"You have one pair"<<endl;
				  payout = bet;
				  stack = stack + payout;
			  }
			  
			  // checks for a high card
			  else{ 
				  cout << "You have a High card"<<endl;
				  payout = bet;
				  stack = stack + payout;
			  }
		cout<<"Your current balance is: "<< stack<<"\nYou gained: "<<payout<<"\nWould you like to keep playing?  ";
		cin>>choice;
	}
}
