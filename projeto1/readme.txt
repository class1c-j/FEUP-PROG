-------------------------------------------------------------------
                             OWARE GAME                           
-------------------------------------------------------------------
Author: Rita Miguel Matos Mendes (up201907877)
Course: Programming (EIC0012) - 1st year of Master in Informatics and
Computing Engineering in FEUP
Version: 1.0 (April 2020)

-------------------------------------------------------------------
                            WORK OVERVIEW
-------------------------------------------------------------------
This project is a simple implementation of the traditional Oware game
that runs in the console and allows the player to play against a 
friend or against the computer.

The main goal here was to learn and get used to C++, as well as 
making organized and readable code.

The code could be a bit cleaner if structs or classes were used, but given
that I had no experience with those and they weren't covered in class during
the time in which this project was developed, I did not use them.
That made it so that the functions had to take more argumments, which ended
up making it look cluttered.
Header files and splitting the code in different files could have helped as well.

---------------------------------------------------------------------
                           DEVELOPMENT STATE                         
---------------------------------------------------------------------
The proposed objective were:

    1 - Display the board in its starting position, as well as during and after
    each move.
    --- Achieved, the board is displayed every play, including the sowing 
    "animation" that refreshes the board every time a seed is dropped.
    
    2 - Allow each playe, on his turn,to do his move, by collecting his seeds,
    sowing them and capturing the opponent seeds, if possible.
    --- Achieved, every play the player selects a house and it's seeds are 
    collected and sowed. In the end of the play, it checks for possible captures
    and makes them.
    
    3 - After each move, detect if the game ended and announce the winner or 
    declare a draw.
    --- Achieved, each play it is checked if there is someone with more than 24 
    points of score, the game is tied, or there are no more possible plays to 
    make. If so, the game declares the winner (or a draw).
    
    4 - The program must execute in console mode. You are free to choose the 
    interface of the program. The seeds in each hole can be indicated by 
    numbers, instead of other symbols. Colored numbers may be used to 
    distinguish the seeds of each player.
    --- Achieved, the seeds are indicated bu numbers and colours were used 
    for the names and scores of the players
    
    
    5 - It is suggested that you start by implementing a "random player 
    version" that simply looks at the available choices and picks one of them, 
    randomly.
    --- Achieved, the EasyBot checks if he is in a situation in which he needs
    to make a specific play to follow the rule of "Let the opponent play", and, 
    if not, he picks a house at random and plays.
    
    6 - Alternatively you can calculate the score from every possible move and 
    pick the one with the highest immediate payoff.
    --- Achieved, the HardBot checks if he is in a situation in which he needs
    to make a specific play to follow the rule of "Let the opponent play", and, 
    if not, he calculates the score that he will get from each house and 
    chooses the best. In case all houses give the same points, he picks one 
    at random and plays.
    
---------------------------------------------------------------------
                          KNOWN ISSUES                         
---------------------------------------------------------------------

This game was developed and tested on a linux environments, so, even after 
following the provided instructions to add things like the colours and 
the screen clearing for windows platforms, I could not find a way to
make the annimations achieved with std::this_thread::sleep_for(std::chrono::milliseconds())
work without flickering.

Other than that, the game does not deal well with "big slam" situations, instead 
it should only leave the last seed uncaptured.

---------------------------------------------------------------------
                      OBSERVATIONS AND ADDED FEATURES                         
---------------------------------------------------------------------

A menu interface was added to the game allowing the user to keep playing
in the different modes after an individual game ended as well as reading
the game instructions before starting to play.

When the game goes into infinite loop, there is no way to stop it without quitting
the program, but after 50 human plays (99 or 100 total plays), the game will 
end in a tie.

The "outcomes" function was made for the HardBot, but also supports
input from player 1, because initially it was made thinking of a spectator mode
(watching the bots play against each other), but that idea was discarded.


---------------------------------------------------------------------
                          SCREENS FROM THE GAME                         
---------------------------------------------------------------------

MAIN MENU:

 _____                          _____                      
|  _  |                        |  __ \                     
| | | |_      ____ _ _ __ ___  | |  \/ __ _ _ __ ___   ___ 
| | | \ \ /\ / / _` | '__/ _ \ | | __ / _` | '_ ` _ \ / _ \
\ \_/ /\ V  V / (_| | | |  __/ | |_\ \ (_| | | | | | |  __/
 \___/  \_/\_/ \__,_|_|  \___|  \____/\__,_|_| |_| |_|\___|
                                                           
                                                           

(1) - Play against a friend

(2) - Play against easy bot

(3) - Play against hard bot

(4) - Show instructions

(5) - Quit game 



INSTRUCTIONS:
  _____           _                   _   _                 
 |_   _|         | |                 | | (_)                
   | |  _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __  ___ 
   | | | '_ \/ __| __| '__| | | |/ __| __| |/ _ \| '_ \/ __|
  _| |_| | | \__ \ |_| |  | |_| | (__| |_| | (_) | | | \__ \
 |_____|_| |_|___/\__|_|   \__,_|\___|\__|_|\___/|_| |_|___/
                                                            
                                                            
OBJECTIVE
The game starts with four seeds in each house. The goal of the game is to 
capture more seeds than the opponent

SOWING
Players take turns moving the seeds. On their turn, the player chooses one of 
the six houses under their control and removes its seeds.
They then distribute the seeds, dropping one in each house counter-clockwise 
from there until their hand is empty.
The starting house is always left empty.

CAPTURING
Capturing occurs when a player brings the count of an opponent's house to 
exactly two or three with the final seed he sowed in that turn.
If the previous-to-last seed also brought an opponent's house to two or three, 
these are captured as well, and so on. However, if a move could capture all of 
an opponent's seeds, the capture is forfeited.

LET THE OPPONENT PLAY
If an opponent's houses are all empty, the current player must make a move that 
gives the opponent seeds.
If no such move is possible, the current player captures all seeds in their 
territory, ending the game.

CONTROLS
Each house has a number (1-6). To play, select one with your keyboard.

Press ENTER to go back to the menu.



PLAYER SELECTION:

Insert your name, player1 : P1
Insert your name, player2 : P2


Who starts playing?

(1) - P1

(2) - P2

(3) - Random



BOARD:

P2                                                                                                              Score: 0
-------------------------------------------------------------------------------------------------------------------------
|         1         |         2         |         3         |         4         |         5         |         6         | 
-------------------------------------------------------------------------------- ----------------------------------------
|                   |                   |                   |                   |                   |                   |
|         4         |         4         |         4         |         4         |         4         |         4         |
|                   |                   |                   |                   |                   |                   |
-------------------------------------------------------------------------------------------------------------------------
|                   |                   |                   |                   |                   |                   |
|         4         |         4         |         4         |         4         |         4         |         4         |
|                   |                   |                   |                   |                   |                   |
-------------------------------------------------------------------------------------------------------------------------
|         1         |         2         |         3         |         4         |         5         |         6         |
-------------------------------------------------------------------------------------------------------------------------
P1                                                                                                              Score: 0
Your turn to play, P2: 



  
