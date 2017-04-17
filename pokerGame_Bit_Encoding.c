#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char card;
typedef unsigned char pairs;

/* arrays for the names of things */
static char *suits[] = {"Hearts","Diamonds","Clubs","Spades"};
static char *values[]= {"Ace","Two","Three","Four","Five","Six",\
                        "Seven","Eight","Nine","Ten","Jack",\
                        "Queen","King"};
static char *colour[]= {"Black","Red"};

/* function prototypes */
void printcard(card c); /* Displays the value of a card*/

void printdeck(card deck[52]); /* prints an entire deck of cards*/

void filldeck(card deck[52]); /* Populates a deck of cards */

void shuffle(card deck[52]); /* Randomizes the order of cards */

int compareface(const void* c1,const void *c2); 
/* compares the face value of 2 cards, suitable to pass to qsort
   as the fourth argument */

pairs findpairs(card *hand); /* finds any pairs in a hand */

int main()
{
  card c;
  card deck[52],*deckp;
  card hands[5][5],handssorted[5][5];
  pairs numpairs[5],highest, drawHighestPair;
  int hand,cd,winner, winningHand;
  int cd1, winningPair, pv1;
  int dIndex=0;  
  int samePairCnt = 0; // samePairCnt represents the number of pair value pairs 

  
  srand(time(NULL));       /* seed the random number generator */

  /*populate and shuffle the deck */
  filldeck(deck);

  //print deck before shuffle
  printf("\n *  *  *  BEFORE SHUFFLING DECK  *  *  *  \n");
  printdeck(deck);


  shuffle(deck);

  // Print deck after shuffling deck
  printf("\n *  *  *  AFTER SHUFFLING DECK  *  *  *  \n");
  printdeck(deck);
  printf("\n");




  // Dealing the hands: Assigns all 5 hands with 1 card each loop, till all 5 hands have 5 cards (5x5)
  for(cd = 0; cd < 5; cd++){
     for(hand = 0; hand < 5; hand++){

        hands[cd][hand] = deck[dIndex]; // assign hand with card from, e.g hand 0,0 will get deck[0]
        dIndex++; // increments deck index to give next card to next hand 
     }
  }


  // Loops 5x5 times for 5 hands, sorts deck, prints hands
  for(hand = 0; hand < 5; hand++){

    // sorts cards-hands by order of face value
    for(int i=0; i < 5; i++){
      qsort(hands[i], 5, sizeof(card), compareface);
    }

    // puts sorted hands in array
    for(int i=0; i < 5; i++){
      handssorted[hand][i] = hands[hand][i];
    }

    // gets number of pairs from sorted hands
    numpairs[hand]=findpairs(handssorted[hand]);

    /*  *  *  PRINTING OF HANDS  *  *  */ 

    printf("Hand %i:", hand+1); // prints hand number

    /* print the hands here */
    for(cd=0; cd < 5; cd++){
      printf("\t");
      printcard(hands[hand][cd]); // prints 5 cards for each hand (5 hands)
    }
    
    /*  *  *  PRINTING OF PAIRS  *  *  */

    /* print the number and value of any pairs here */
    printf("Number of pairs: %i\n", numpairs[hand]&0xf); // BITWISE bits 0-3 to get pairs' value, then print it

    // if there's a pair get highest pair value
    if((numpairs[hand]&0xf) > 0 ){
      highest = numpairs[hand] >> 4; // shift right by 4 to get value of card (bits 4-7)
      printf("Highest pairs: %s\n\n", values[highest]); // prints highest card pair value
    }
    else{
      printf("\n"); // if there's NO pair just prints a new line for user readability 
    }
  }

    /*  *  *  DETERMINE WINNER  *  *  */

  /* determine the winner and print it */
  // checks for highest pair VALUE in hands and if there's a draw instead

 pv1 = numpairs[0]&0xf; // p1 represents the first pair to compare to other pair Values
for(hand = 0; hand < 5; hand++){

    if((numpairs[hand]&0xf) > 0 ){
      highest = numpairs[hand] >> 4; // shift right by 4 to get value of card (bits 4-7)

      // if val to compare is greater, pv1 becomes highest value
      if (pv1 <= highest){
        pv1 = highest;
        winningHand = hand+1;

        for (int i = hand+1; i < 5; i++){ 
          //checks for pairs of number pair values between hands
          if (pv1 != 0){
            if((numpairs[hand]>>4) == (numpairs[i]>> 4)){
               drawHighestPair = (numpairs[hand]>>4); 
                samePairCnt++;
            }
          }
        }
      }
    }
}
	// if highest winning value > highest draw, no draw
  	if (drawHighestPair < highest){ 
    	samePairCnt = 0;
  	}

    if(winningHand > 5 || (samePairCnt == 1 )){
        winner = 0; //if game drawn winner = 0 (no winner)
      }
      else{ // if theres a winner assign winner value
        winner =  winningHand;
      }

  // if there's a winner print winner info
  if(winner > 0){
    printf("Winner is hand %i with a pair of %ss\n\n", winner, values[pv1]);
  }
  else{ // else print if game is drawn
    printf("Drawn game\n\n");
  }


  return 0;
} // END OF MAIN 


/* finds pairs in hand */
pairs findpairs(card *hand)
{
  pairs numpairs=0;
  int index, cd1, cd2, cd3, count;  count = 0;
  /* index represents the hand index (0-4), 
     cd1 & cd2 represent card 1, 2 & 3 that're being compared for pairs 
     and count represents the pair count */

  // up to 5 (5 hands)
  for(index = 0; index < 4; index++){
    /* compares card at index i with the next card at index i+1,
       and so on until all cards in each hand are compared for pairs */

    // BITWISE AND card 1, 2 & 3 with mask: 0111 100, then shift right by 3 to get card's value 
    cd1 = (hand[index]&0x78) >> 3; 
    cd2 = (hand[index+1]&0x78) >> 3;
    cd3 = (hand[index+2]&0x78) >> 3;

    /* compare card (i) with next card (i+1) and compare
       card i with card i+2 to check for a three of a kind and only count it as one pair */
    if(cd1 == cd2 && cd1 != cd3) {
      // number of pairs (bit 0-3) = 0000 0000 + pair counter, (bits 0-3 countain number of pairs) 
      numpairs = (0x0 + ++count); 

      //number of pairs (bits 4-7) = numpairs BITWISE OR card 1 with 0000 1111 mask to get card value
      numpairs = (numpairs|((cd1&0xf) << 4)); 
    }
  }
  
  return numpairs; // numpairs will return 8 bits: bits 0-3: pairs value & bits 4-7: card value
}

/* fills deck with card */
void filldeck(card deck[52])
{
  /* populate the deck here */
  // NOTE: bits 3, 4, 5, & 6 encode the value

  card c = 0x0; // masks card: card = 0000 0000
  int face, suit, dIndex = 0; // dIndex represents the deck's index 

  for(suit = 0; suit < 4; suit++){

    int mask = 0; // mask needs to be declared in this for loop!

    for(face = 0; face <= 12; face++){
      /* assigning this sequence of numbers to c & f orders 
         cards according to suits, values & colors arrays */

      if(suit == 0){ // if Hearts
        c = 0x1;  // card = 0000 0001, 1, Two 
      }
      else if(suit == 1){ // if Diamonds
        c = 0x2; // card = 0000 0010, 2, Three
      }
      else if(suit == 2){ // if Clubs
        c = 0x4; // card = 0000 0100, 4, Five
      }
      else if(suit == 3){ // if Spades
        c = 0x6; // card = 0000 0110, 6, Seven
      }

      if(face == 0){ // if Ace 
        c = c|0x0; // card = card BITWISE OR 0000 0000
      }
      else if(face != 0){ // if not Ace
        c = c|mask; // card = card BITWISE OR += 0000 1000
      }

      mask += 8; // increments mask by 8 after every loop, += 0000 1000. should start at 0 and end at 12x8 (96)
      deck[dIndex] = c; // fills deck with card just put together by above sequence 
      dIndex++; // increments deck index after every loop, to assign next card
    }
  }

  return;
}

// Prints deck of cards
void printdeck(card deck[52])
{
  int i;

  for(i = 0; i < 52; i++){
    printcard(deck[i]);
  }

  return;
}

// Prints individual card
void printcard(card c)
{
  int face, col, suit;

  // Bit 0 encodes the colour
  col =   (c&0x1); // color = card BITWISE AND 0000 0001  
  // Bits 1 & 2 encodes the suit
  suit =  (c&0x6)>>1; // suit = card BITWISE AND 0000 0110, shift right by 1
  // Bits 3, 4, 5, & 6 encode the value
  face =  (c&0x78)>>3; // face = card BITWISE AND 0111 100, shift right by 3.



  // Prints "[Value] of [Suit], is [Color]"
  printf("%s of ", values[face]);   // prints face value of card
  printf("%s is ", suits[suit]);    // prints suit of card
  printf("%s\n", colour[col]);      // prints color of card

  return;
}

// Shuffles deck randomly
void shuffle(card deck[52])
{
  int i,rnd; // i represents the counter, rnd represents the randomly generated number
  card c;
   
  for(i = 0; i < 52; i++){
    
    /* generates a random number between 0 & 51 */
    rnd = rand() * 52.0 / RAND_MAX; 
	  
    // shuffling of the deck then assigning shuffled deck back to deck
    c = deck[rnd];         // assign random deck index between 0 & 51 to card
    deck[rnd] = deck[i];   // now assign that shuffled (random) deck to the deck
    deck[i] = c;           // technically ordering the shuffled deck and assigning it to the card again
  }

  return;
}

// compares card values 
int compareface(const void* c1, const void *c2)
{
/* This function extracts the two cards face values
   and returns 1 if cd1 > cd2, 0 if cd1 == cd2, and
   -1 otherwise. The weird argument types are for
   compatibility with qsort(), the first two lines
   decode the arguments back into "card".
   */
    card cd1,cd2;
    
    cd1=*((card*) c1);
    cd2=*((card*) c2);
    
    cd1= (cd1&0x78)>>3; // ">> means 'shift right' "
    cd2= (cd2&0x78)>>3;
    
    if(cd1>cd2)
      return 1;
    if(cd1==cd2)
      return 0;
      
    return -1;
}