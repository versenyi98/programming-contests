You have a deck of N cards. Initially, the cards are numbered in order from 1 to N.

A shuffle consists of:

    Bring the cards at odd positions on top of the deck, in order.
    Place the first card on the table. On top of it, place the last card. Then take the first card in the remaining deck and place on top of the cards on the table, then the last one, and so on.
    The cards on the table form the new deck. 

For example, let's say we have N=6N=6N=6 cards:

    Initially the deck is [1, 2, 3, 4, 5, 6]
    The we bring the cards at odd positions on top: [1, 3, 5, 2, 4, 6]
    After placing them on the table, the new deck is: [2, 5, 4, 3, 6, 1] 

Find the order of the cards in the deck after K successive shuffles.
Standard input

The first line contains two integers N and K.
Standard output

On the first line print N integers representing the order of the cards in the deck after all the shuffles. 