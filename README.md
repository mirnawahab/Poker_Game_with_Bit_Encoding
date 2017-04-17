# Poker_Game_with_Bit_Encoding
Implementation of a Poker game simulator using bit encoding <br/><br/>

This program is a poker game,but the cards have a fixed value.
The logic behind the program is that we first fill a deck of 52 with cards that are encoded by using BITWISE operations and masking to give them a value. Bits 0 & 1 encode the suit, bit 2 encodes the colour and bits 3, 4, 5, & 6 encode the value. The deck is then shuffled to become a random sequence of cards. After shuffling the deck we deal the hands, giving 5 cards to a total of 5 hands (5x5). The hands are then sorted for ease of finding pairs, after that the sorted hands are then searched for pairs. All hands, pairs and their values found are then printed. <br/>
To finish the game we then determine the winner by finding the highest number of pairs between all hands or drawing the game if all hands have no pairs or two hands have the highest pair equally. The winner is then printed and the game ends.
<br/>

 <br />
##TEST PLAN: <br />
 <br />

Below is my test plan using the MAC terminal, how I compiled my program is included as well as the output. <br />
Test plan was successful, program ends/exits automatically when game is over. <br />

** test output of a game with a winner: <br /> <br />

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ gcc CSA.c -o CSA <br/>
Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA <br/>
Hand 1:	Three of Hearts is Red <br/>
	Eight of Hearts is Red <br/>
	Ten of Hearts is Red <br/>
	Jack of Diamonds is Red <br/>
	Queen of Spades is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 2:	Four of Spades is Black <br/>
	Five of Clubs is Black <br/>
	Eight of Clubs is Black <br/>
	Ten of Diamonds is Red <br/>
	Queen of Diamonds is Red <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 3:	Two of Diamonds is Red <br/>
	Nine of Hearts is Red <br/>
	Ten of Clubs is Black <br/>
	Jack of Clubs is Black <br/>
	King of Spades is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 4:	Ace of Spades is Black <br/>
	Three of Spades is Black <br/>
	Seven of Diamonds is Red <br/>
	Seven of Clubs is Black <br/>
	Ten of Spades is Black <br/>
Number of pairs: 1 <br/>
Highest pairs: Seven <br/>
 <br/>
Hand 5:	Two of Clubs is Black <br/>
	Three of Diamonds is Red <br/>
	Six of Clubs is Black <br/>
	Jack of Hearts is Red <br/>
 	Queen of Clubs is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Winner is hand 4 with a pair of Sevens <br/>
 <br/> <br/>

** test output of a game without a winner: <br/> 

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA <br/>
Hand 1:	Two of Diamonds is Red <br/>
	Five of Spades is Black <br/>
	Nine of Diamonds is Red <br/>
	Ten of Hearts is Red <br/>
	Jack of Spades is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 2:	Ace of Spades is Black <br/>
	Five of Clubs is Black <br/>
	Eight of Spades is Black <br/>
	Ten of Spades is Black <br/>
	Queen of Hearts is Red <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 3:	Three of Clubs is Black <br/>
	Four of Spades is Black <br/>
	Nine of Hearts is Red <br/>
	Ten of Diamonds is Red <br/>
	King of Diamonds is Red <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 4:	Ace of Clubs is Black <br/>
	Two of Spades is Black <br/>
	Six of Hearts is Red <br/>
	Seven of Diamonds is Red <br/>
	Nine of Spades is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Hand 5:	Two of Clubs is Black <br/>
	Seven of Hearts is Red <br/>
	Nine of Clubs is Black <br/>
	Ten of Clubs is Black <br/>
	King of Clubs is Black <br/>
Number of pairs: 0 <br/>
 <br/>
Drawn game <br/>

