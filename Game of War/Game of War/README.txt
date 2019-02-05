Game of War Information and implementation

First I started off by using enum just like how we learned it in class for each of the main elements/faces in the cards such as
diamonds, clubs, hearts and spades. I had to create two players and the two players would battle it out. In the game the card
is divided evenly among the players. Each person in my game gets a turn. Player 1 shows a card and player 2 shows a card whoever
has the highest element for example diamond they would win. Aces and suits are ignored. If the two cards are equal in value they
go into a "war" where both players place the next cards face down and the player who gets the higher face card will win the war.

Somethings I did code wise would be I created classes for card then I created constructors to intialize a new cards and output
the text representation of each cards. I created a class randomIntegers to get the game to be more random. I made a class for 
the deck and made a class for the players. I created void function to add the points to determine who got the higher card, I also
created void functions that allows last card played to be replaced with new card. My main function displays the results which 
allow the computer to determine who got the higher points each round and declare who the winner is.
