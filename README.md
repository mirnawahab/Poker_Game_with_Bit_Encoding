# Poker_Game_with_Bit_Encoding
Implementation of a Poker game simulator using bit encoding 


-------------------------------------------------------------------------
LOGIC:   
-------------------------------------------------------------------------

This program is a poker game,but the cards have a fixed value.

The logic behind the program is that we first fill a deck of 52 with cards that are encoded by using BITWISE operations and masking to give them a value. Bits 0 & 1 encode the suit, bit 2 encodes the colour and bits 3, 4, 5, & 6 encode the value. The deck is then shuffled to become a random sequence of cards. After shuffling the deck we deal the hands, giving 5 cards to a total of 5 hands (5x5). The hands are then sorted for ease of finding pairs, after that the sorted hands are then searched for pairs. All hands, pairs and their values found are then printed. 
To finish the game we then determine the winner by finding the highest number of pairs between all hands or drawing the game if all hands have no pairs or two hands have the highest pair equally. The winner is then printed and the game ends.


-------------------------------------------------------------------------
TEST PLAN:
-------------------------------------------------------------------------

Below is my test plan using the MAC terminal, how I compiled my program is included as well as the output.
Test plan was successful, program ends/exits automatically when game is over.

** test output of a game with a winner:

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ gcc CSA.c -o CSA
Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA
Hand 1:	Three of Hearts is Red
	Eight of Hearts is Red
	Ten of Hearts is Red
	Jack of Diamonds is Red
	Queen of Spades is Black
Number of pairs: 0

Hand 2:	Four of Spades is Black
	Five of Clubs is Black
	Eight of Clubs is Black
	Ten of Diamonds is Red
	Queen of Diamonds is Red
Number of pairs: 0

Hand 3:	Two of Diamonds is Red
	Nine of Hearts is Red
	Ten of Clubs is Black
	Jack of Clubs is Black
	King of Spades is Black
Number of pairs: 0

Hand 4:	Ace of Spades is Black
	Three of Spades is Black
	Seven of Diamonds is Red
	Seven of Clubs is Black
	Ten of Spades is Black
Number of pairs: 1
Highest pairs: Seven

Hand 5:	Two of Clubs is Black
	Three of Diamonds is Red
	Six of Clubs is Black
	Jack of Hearts is Red
	Queen of Clubs is Black
Number of pairs: 0

Winner is hand 4 with a pair of Sevens

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA
Hand 1:	Four of Spades is Black
	Four of Diamonds is Red
	Nine of Diamonds is Red
	Nine of Hearts is Red
	Queen of Clubs is Black
Number of pairs: 2
Highest pairs: Nine

Hand 2:	Four of Hearts is Red
	Six of Spades is Black
	Seven of Hearts is Red
	Seven of Spades is Black
	Queen of Diamonds is Red
Number of pairs: 1
Highest pairs: Seven

Hand 3:	Two of Clubs is Black
	Four of Clubs is Black
	Five of Clubs is Black
	Eight of Hearts is Red
	Ten of Hearts is Red
Number of pairs: 0

Hand 4:	Ace of Spades is Black
	Three of Diamonds is Red
	Six of Diamonds is Red
	Eight of Spades is Black
	Queen of Hearts is Red
Number of pairs: 0

Hand 5:	Three of Spades is Black
	Seven of Diamonds is Red
	Seven of Clubs is Black
	Jack of Hearts is Red
	King of Hearts is Red
Number of pairs: 1
Highest pairs: Seven

Winner is hand 1 with a pair of Nines



** test output of a game without a winner:

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA
Hand 1:	Two of Diamonds is Red
	Five of Spades is Black
	Nine of Diamonds is Red
	Ten of Hearts is Red
	Jack of Spades is Black
Number of pairs: 0

Hand 2:	Ace of Spades is Black
	Five of Clubs is Black
	Eight of Spades is Black
	Ten of Spades is Black
	Queen of Hearts is Red
Number of pairs: 0

Hand 3:	Three of Clubs is Black
	Four of Spades is Black
	Nine of Hearts is Red
	Ten of Diamonds is Red
	King of Diamonds is Red
Number of pairs: 0

Hand 4:	Ace of Clubs is Black
	Two of Spades is Black
	Six of Hearts is Red
	Seven of Diamonds is Red
	Nine of Spades is Black
Number of pairs: 0

Hand 5:	Two of Clubs is Black
	Seven of Hearts is Red
	Nine of Clubs is Black
	Ten of Clubs is Black
	King of Clubs is Black
Number of pairs: 0

Drawn game

Mirnas-MacBook-Pro:Case Study A MirnaWahab$ ./CSA
Hand 1:	Two of Hearts is Red
	Three of Hearts is Red
	Four of Diamonds is Red
	Seven of Diamonds is Red
	Eight of Hearts is Red
Number of pairs: 0

Hand 2:	Ace of Clubs is Black
	Five of Hearts is Red
	Six of Spades is Black
	Nine of Clubs is Black
	Queen of Diamonds is Red
Number of pairs: 0

Hand 3:	Four of Clubs is Black
	Four of Hearts is Red
	Five of Diamonds is Red
	Six of Clubs is Black
	Jack of Diamonds is Red
Number of pairs: 1
Highest pairs: Four

Hand 4:	Ace of Diamonds is Red
	Ace of Hearts is Red
	Four of Spades is Black
	Eight of Diamonds is Red
	King of Spades is Black
Number of pairs: 1
Highest pairs: Ace

Hand 5:	Ace of Spades is Black
	Two of Clubs is Black
	Ten of Spades is Black
	Jack of Hearts is Red
	Queen of Hearts is Red
Number of pairs: 0
  
Winner is hand 3 with a pair of Fours
