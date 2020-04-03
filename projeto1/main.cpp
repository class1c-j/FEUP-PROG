#ifdef _WIN32
#include <windows.h>
#include <ios>
#undef max
#define WHITE 15
#define BLUE 9
#define GREEN 10
#else
#define WHITE "\033[1;37m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#endif

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>

/**
    Shows the instructions of the game "OWARE"
 */
void showInstructions();

/**
    Shows the main menu and allows the user to select between it's options"
 */
int menu();

/**
    Sets the name of the players to show in the board and dialogs
    @param mode The game mode, to know if it is Player vs Player or Player vs Bot
 */
std::vector<std::string> selectNames(int mode);

/**
    Shows the board, as well as info about the scores
    @param board The current state of the game board
    @param scores The current scores of the players
    @param names The names of the players
 */
void showBoard(const std::vector<int>& board, const std::vector<int>& scores, const std::vector<std::string>& names);

/**
    Moves the seeds to their new places after a play
    @param seeds The amount of seeds taken by the player
    @param house The house from where the player took the seeds
    @param board The current state of the board
 */
void movePieces(int seeds, int house, std::vector<int>& board, std::vector<int> const& scores,
    std::vector<std::string> const& names);

/**
    Capture the seeds when possible and give points to the player
    @param player The current player, needed so that one player does not capture his own seeds
    @param scores The current scores, used to give the player the points from the seeds he captured
    @param board The current state of the board
    @param last The position where the last seed landed, useful for knowing which seeds can be captured
 */
void capture(int player, std::vector<int>& scores, std::vector<int>& board, int last);

/**
    Makes a human play. Asks the player here he wants to play and moves the seeds and captures, checking if
    the game has finished. In the end, changes into the next player and calls the adequate function.
    @param player The current player
    @param board The current state of the board
    @param scores The current scores of the players
    @param names The names of the players
 */
void playerPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names);

/**
    Makes an easy bot play. Picks a valid random house and takes it's seeds, checking if the game has finished.
    In the end, changes into the next player and calls the human player.
    @param player The current player
    @param board The current state of the board
    @param scores The current scores of the players
    @param names The names of the players
 */
void easyPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names);

/**
    Calculates all the outcomes of a player's choice in house. Invalid plays are marked as -1
    @param player The current player
    @param board The current state of the board
    @return outcomes The points in the end of each possible play
 */
std::vector<int> outcomes(std::vector<int>& board, int player);

/**
    Makes a hard bot play. Picks the house that gives it more points and takes it's seeds, checking if the game has
    finished. In the end, changes into the next player and calls the human player.
    @param player The current player
    @param board The current state of the board
    @param scores The current scores of the players
    @param names The names of the players
 */
void hardPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names);

/**
    Calculates the number of the house where the last seed will land
    @param board The current state of the board
    @param seeds The amount of seeds taken during the play
    @param house The house from which the seeds where taken
 */
int lastHouse(const std::vector<int>& board, int seeds, int house);

/**
    Clears the console screen, method based on operating system
 */
void clrScr();

/**
    Changes text color on windows
 */
void setColor(unsigned int color);

/**
    Changes text color on other OS
 */
void setColor(const std::string& color);

/**
    Chooses who starts the game
    @param names The names of the players to show on the prompt
    @return The player who will start the game
 */
int choosePlayer(std::vector<std::string> names);

/**
    Asks the user, at the end of every game, if they want to leave or go back to the menu
    @return Whether the user wants to keep playing or leave
 */
int endPrompt();

int main() {
    int mode = menu();  // main menu to choose the mode
    // std::vector<std::string> names = selectNames(mode);
    std::vector<int> board = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };  // setting up the board
    std::vector<int> scores = { 0, 0 };  // setting up the scores
    int currPlayer;  // who plays first
    std::srand(std::time(nullptr));  // setting up the randomness
    bool end = false;

    while (!end) {
        std::vector<std::string> names = selectNames(mode);
        std::cout << "\n\n";

        if (mode == 1) {  // single player

            // pick who starts playing
            currPlayer = choosePlayer(names);

            // start playing
            playerPlay(currPlayer, board, scores, names);

            // show prompt asking if user wants to go back to the menu or leave
            int choice = endPrompt();
            if (choice == 1) {  // reset the game data for a new one
                board = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
                scores = { 0, 0 };
                mode = menu();
                names = selectNames(mode);
            }
            else {  // else, break the game loop
                end = true;
            }

        }
        else if (mode == 2) {  // easy bot

         // pick who starts playing
            currPlayer = choosePlayer(names);

            // start the game according to whom the user chose to start
            if (currPlayer == 0) {
                playerPlay(currPlayer, board, scores, names);
            }
            else {
                easyPlay(currPlayer, board, scores, names);
            }

            // show prompt asking if user wants to go back to the menu or leave
            int choice = endPrompt();
            if (choice == 1) {  // reset the game data for a new one
                board = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
                scores = { 0, 0 };
                mode = menu();
                names = selectNames(mode);
            }
            else {  // breaking the game loop in case the user wants to leave
                end = true;
            }


        }
        else if (mode == 3) {  // hard bot

         // choose the player
            currPlayer = choosePlayer(names);

            // start the game according to the player chosen
            if (currPlayer == 0) {
                playerPlay(currPlayer, board, scores, names);
            }
            else {
                hardPlay(currPlayer, board, scores, names);
            }

            // show prompt asking if user wants to go back to the menu or leave
            int choice = endPrompt();
            if (choice == 1) {  // reset the game data for a new one
                board = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
                scores = { 0, 0 };
                mode = menu();
            }
            else {
                end = true;
            }


        }
        else if (mode == 4) {  // show the game instructions
            showInstructions();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            board = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
            scores = { 0, 0 };
            mode = menu();


        }
        else if (mode == 5) {  // leave the game
            end = true;
        }
    }
}

void showInstructions() {
    clrScr();
    std::cout << "  _____           _                   _   _                 \n"
        " |_   _|         | |                 | | (_)                \n"
        "   | |  _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __  ___ \n"
        "   | | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|\n"
        "  _| |_| | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\\n"
        " |_____|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/\n"
        "                                                            \n"
        "                                                            " << std::endl;
    std::cout << "OBJECTIVE\nThe game starts with four seeds in each house. The goal of the game is to capture more"
        " seeds than the opponent\n\nSOWING\nPlayers take turns moving the seeds. On their turn, the player"
        " chooses one of the six houses under their control and removes its seeds.\nThey then distribute the"
        " seeds, dropping one in each house counter-clockwise from there until their hand is empty.\nThe"
        " starting house is always left empty.\n\nCAPTURING\nCapturing occurs when a player brings the count"
        " of an opponent's house to exactly two or three with the final seed he sowed in that turn.\nIf the"
        " previous-to-last seed also brought an opponent's house to two or three, these are captured as well,"
        " and so on. However, if a move could capture all of an opponent's seeds, the capture is forfeited.\n\n"
        "LET THE OPPONENT PLAY\nIf an opponent's houses are all empty, the current player must make a move"
        " that gives the opponent seeds.\nIf no such move is possible, the current player captures all seeds"
        " in their territory, ending the game.\n\nCONTROLS\nEach house has a number (1-6). To play, select one"
        " with your keyboard.\n\nPress ENTER to go back to the menu.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int menu() {
    int mode;
    clrScr();
    std::cout << "\n"
        " _____                          _____                      \n"
        "|  _  |                        |  __ \\                     \n"
        "| | | |_      ____ _ _ __ ___  | |  \\/ __ _ _ __ ___   ___ \n"
        "| | | \\ \\ /\\ / / _` | '__/ _ \\ | | __ / _` | '_ ` _ \\ / _ \\\n"
        "\\ \\_/ /\\ V  V / (_| | | |  __/ | |_\\ \\ (_| | | | | | |  __/\n"
        " \\___/  \\_/\\_/ \\__,_|_|  \\___|  \\____/\\__,_|_| |_| |_|\\___|\n"
        "                                                           \n"
        "                                                           \n"
        "" << std::endl;
    std::cout << "(1) - Play against a friend\n\n";
    std::cout << "(2) - Play against easy bot\n\n";
    std::cout << "(3) - Play against hard bot\n\n";
    std::cout << "(4) - Show instructions\n\n";
    std::cout << "(5) - Quit game\n\n";
    std::cin >> mode;
    while (std::cin.fail() || (!isdigit(std::cin.peek()) && std::cin.peek() != '\n') || mode < 1 || mode > 5) {
        std::cout << "Invalid option. Try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> mode;
    }
    return mode;
}

std::vector<std::string> selectNames(int mode) {
    std::string name1, name2;
    if (mode == 1) {
        std::cout << "Insert your name, player1 : ";
        std::cin >> name1;
        while (std::cin.fail() || std::cin.peek() != '\n' || name1 == "EasyBot" || name1 == "HardBot") {
            std::cout << "Invalid name (whitespaces are not valid). Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> name1;
        }
        std::cout << "Insert your name, player2 : ";
        std::cin >> name2;
        while (std::cin.fail() || std::cin.peek() != '\n'|| name2 == "EasyBot" || name2 == "HardBot") {
            std::cout << "Invalid name (whitespaces are not valid). Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> name2;
        }
    }
    else if (mode == 2 || mode == 3) {
        std::cout << "Insert your name, player1 : ";
        std::cin >> name1;
        while (std::cin.fail() || std::cin.peek() != '\n' || name1 == "EasyBot" || name1 == "HardBot") {
            std::cout << "Invalid name (whitespaces are not valid). Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> name1;
        }
        (mode == 2) ? name2 = "EasyBot" : name2 = "HardBot";
    }
    std::vector<std::string> names = { name1, name2 };
    return names;
}

int choosePlayer(std::vector<std::string> names) {
    int currPlayer;

    std::cout << "Who starts playing?\n\n(1) - " << names.at(0) << "\n\n(2) - " << names.at(1)
        << "\n\n(3) - Random\n\n";

    std::cin >> currPlayer;
    while (std::cin.fail() || !isdigit(std::cin.peek()) && std::cin.peek() != '\n' ||
        (currPlayer != 1 && currPlayer != 2 && currPlayer != 3)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Pick either (1), (2) or (3) to choose who starts the game: ";
        std::cin >> currPlayer;
    }

    currPlayer -= 1;  // because of the indexes starting at 0
    if (currPlayer == 2) {
        currPlayer = rand() % 2;
    }
    return currPlayer;
}

int endPrompt() {
    std::cout << "(1) - Back to main menu\t(2) - Exit the game" << std::endl;
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || !isdigit(std::cin.peek()) && std::cin.peek() != '\n' ||
        (choice != 1 && choice != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Pick either (1) to go back to the menu or (2) to leave: ";
        std::cin >> choice;
    }
    return choice;
}

void showBoard(std::vector<int> const& board, std::vector<int> const& scores, std::vector<std::string> const& names) {
    clrScr();
    const int W = 20;

    // player 2 info
    setColor(GREEN);
    std::cout << names.at(1) << std::setw(115) << "Score: " << scores.at(1) << std::endl;
    setColor(WHITE);

    std::cout << "-------------------------------------------------------------------------------------------------"
        "------------------------\n";

    // show house position numbers
    std::cout << "|" << std::setw(W / 2) << 1 << std::setw(W / 2) << '|' << std::setw(W / 2) << 2
        << std::setw(W / 2) << '|' << std::setw(W / 2) << 3 << std::setw(W / 2) << '|'
        << std::setw(W / 2) << 4 << std::setw(W / 2) << '|' << std::setw(W / 2) << 5
        << std::setw(W / 2) << '|' << std::setw(W / 2) << 6 << std::setw(W / 2) << '|'
        << std::setw(W / 2) << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------"
        "------------------------\n";

    // blank line
    std::cout << "|" << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W)
        << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::endl;

    // player 2 seeds
    std::cout << "|" << std::setw(W / 2) << board.at(11) << std::setw(W / 2) << '|' << std::setw(W / 2)
        << board.at(10) << std::setw(W / 2) << '|' << std::setw(W / 2) << board.at(9)
        << std::setw(W / 2) << '|' << std::setw(W / 2) << board.at(8) << std::setw(W / 2)
        << '|' << std::setw(W / 2) << board.at(7) << std::setw(W / 2) << '|' << std::setw(W / 2)
        << board.at(6) << std::setw(W / 2) << '|' << std::endl;

    // blank line
    std::cout << "|" << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W)
        << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------"
        "------------------------\n";

    // blank line
    std::cout << "|" << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W)
        << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::endl;

    // player 1 seeds
    std::cout << "|" << std::setw(W / 2) << board.at(0) << std::setw(W / 2) << '|' << std::setw(W / 2)
        << board.at(1) << std::setw(W / 2) << '|' << std::setw(W / 2) << board.at(2)
        << std::setw(W / 2) << '|' << std::setw(W / 2) << board.at(3) << std::setw(W / 2)
        << '|' << std::setw(W / 2) << board.at(4) << std::setw(W / 2) << '|' << std::setw(W / 2)
        << board.at(5) << std::setw(W / 2) << '|' << std::endl;

    // blank line
    std::cout << "|" << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::setw(W)
        << '|' << std::setw(W) << '|' << std::setw(W) << '|' << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------"
        "------------------------\n";

    // house position numbers
    std::cout << "|" << std::setw(W / 2) << 1 << std::setw(W / 2) << '|' << std::setw(W / 2) << 2
        << std::setw(W / 2) << '|' << std::setw(W / 2) << 3 << std::setw(W / 2) << '|'
        << std::setw(W / 2) << 4 << std::setw(W / 2) << '|' << std::setw(W / 2) << 5
        << std::setw(W / 2) << '|' << std::setw(W / 2) << 6 << std::setw(W / 2) << '|' << std::endl;


    std::cout << "-------------------------------------------------------------------------------------------------"
        "------------------------\n";

    // player 1 info
    setColor(BLUE);
    std::cout << names.at(0) << std::setw(115) << "Score: " << scores.at(0) << std::endl;
    setColor(WHITE);
}

void movePieces(int seeds, int house, std::vector<int>& board, std::vector<int> const& scores,
    std::vector<std::string> const& names) {
    int left = seeds;
    int max = house + seeds + ((house + seeds) / 12);
    for (int i = house + 1; i <= max; i++) {
        int curr = (i > 11) ? i - 12 : i;
        curr = (curr > 11) ? curr - 12 : curr;
        if (i != house && i - 12 != house && i - 24 != house && left > 0) {
            board.at(curr)++;
            left--;
            if (!names.at(1).empty()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                showBoard(board, scores, names);
                std::cout << "SOWING (DO NOT PRESS ANY KEY) ..." << std::endl;
            }
        }
    }
}

int lastHouse(const std::vector<int>& board, int seeds, int house) {
    int left = seeds;
    int final{};
    int max = house + seeds + ((house + seeds) / 12);
    for (int i = house + 1; i <= max; i++) {
        int curr = (i > 11) ? i - 12 : i;
        if (i != house && i - 12 != house && i - 24 != house && left > 0) {
            final = curr;
            left--;
        }
    }
    return final;
}

void capture(int player, std::vector<int>& scores, std::vector<int>& board, int last) {
    // calculating the amount of seeds to later check if a move will make the opponent lose all his seeds
    int sumP1 = board.at(0) + board.at(1) + board.at(2) + board.at(3) + board.at(4) + board.at(5);
    int sumP2 = board.at(6) + board.at(7) + board.at(8) + board.at(9) + board.at(10) + board.at(11);

    if (player == 0 && last > 5) {  // player 1 captures
        for (int i = last; i >= 6; i--) {
            if ((board.at(i) == 2 || board.at(i) == 3) && sumP2 - board.at(i) != 0 && i > 5) {
                scores.at(0) += board.at(i);
                board.at(i) = 0;
            }
            else {
                break;  // no more continuous possible captures
            }
        }
    }
    else if (player == 1 && last < 6) {  // player 2 captures
        for (int i = last; i >= 0; i--) {
            if ((board.at(i) == 2 || board.at(i) == 3) && sumP1 - board.at(i) != 0 && i < 6) {
                scores.at(1) += board.at(i);
                board.at(i) = 0;
            }
            else {
                break;  // no more continuous possible captures
            }
        }
    }
}

void playerPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names) {
    int house = 0;
    int winner, houseTaken;
    static int plays = 0;
    bool finished = (scores.at(0) >= 25 || scores.at(1) >= 25 || (scores.at(0) == scores.at(1) &&
        scores.at(0) == 24));
    bool fEarly = false;  // flag that goes true if the game ends before any of the players reaches 25
    bool force = false;
    std::vector<int> forcedPlays;

    int sumP1 = board.at(0) + board.at(1) + board.at(2) + board.at(3) + board.at(4) + board.at(5);
    int sumP2 = board.at(6) + board.at(7) + board.at(8) + board.at(9) + board.at(10) + board.at(11);

    if (sumP1 == 0 && player == 1) {  // p2's turn and p1 has no seeds
        int i;
        for (i = 11; i > 5; i--) {  // go through p2's houses
            if (lastHouse(board, i, board.at(i)) < 6 && board[i] != 0) {  // checks if any of them can give p1 seeds
                forcedPlays.push_back(i);
                force = true;
            }
        }
        if (i < 5) {
            scores.at(1) += sumP2;
            fEarly = true;
            finished = true;  // game ended because p1 has 0 seeds and p2 cant give them any
            winner = 1;  // the winner is player 2
        }
    }
    else if (sumP2 == 0 && player == 0) {  // p1's turn and p2 has no seeds
        int i;
        for (i = 0; i < 6; i++) {  // go through p1's houses
            if (i + board.at(i) > 5 && board[i] != 0) {
                forcedPlays.push_back(i);
                force = true;
            }
        }
        if (i > 6) {
            scores.at(1) += sumP1;
            fEarly = true;
            finished = true;  // game ended because p1 has 0 seeds and p2 cant give them any
            winner = 0;  // the winner is player 1
        }
    }

    if (!finished) {
        showBoard(board, scores, names);

        std::cout << "Your turn to play, " << names.at(player) << ": ";
        if (force) {
            std::cout << "\nYou have to give one seed to your opponent!!\nPlay one of the following ( ";
            for (int i : forcedPlays) {
                int sug = (i < 6) ? (i + 1) : (12 - i);
                std::cout << sug << " ";
            }
            std::cout << "): ";
            std::cin >> house;
            houseTaken = (player == 0) ? (house - 1) : (12 - house);
            auto it = find(forcedPlays.begin(), forcedPlays.end(), 30);
            while (std::cin.fail() || !isdigit(std::cin.peek()) && std::cin.peek() != '\n' || it == forcedPlays.end()) {
                std::cout << "Invalid input. Play one house that will give seeds to your opponent: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> house;
                houseTaken = (player == 0) ? (house - 1) : (12 - house);
                it = find(forcedPlays.begin(), forcedPlays.end(), houseTaken);
            }

        }
        else {
            std::cin >> house;
            houseTaken = (player == 0) ? (house - 1) : (12 - house);  // the index depends on the current player
            while (std::cin.fail() || !isdigit(std::cin.peek()) && std::cin.peek() != '\n' || house < 0 || house > 6
                || board.at(houseTaken) == 0) {
                if (house < 0 || house > 6) {
                    std::cout << "Please, enter a house number between 1 and 6: ";
                }
                else if (board.at(houseTaken) == 0) {
                    std::cout << "That house is empty! Please, select one with seeds: ";
                }
                else {
                    std::cout << "Invalid input! Please, try again: ";
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> house;
                houseTaken = (player == 0) ? (house - 1) : (12 - house);
            }  // check for invalid input or invalid house choice
        }

        int seedsTaken = board.at(houseTaken);
        int last = lastHouse(board, seedsTaken, houseTaken);
        board.at(houseTaken) = 0;

        // play
        movePieces(seedsTaken, houseTaken, board, scores, names);
        capture(player, scores, board, last);
        showBoard(board, scores, names);

        // switch to next player
        if (names.at(1) != "EasyBot" && names.at(1) != "HardBot" && !finished) {  // player vs player
            player = (player == 0) ? 1 : 0;
            playerPlay(player, board, scores, names);
        }
        else if (names.at(1) == "EasyBot") {
            easyPlay(player, board, scores, names);
        }
        else if (names.at(1) == "HardBot") {
            hardPlay(player, board, scores, names);
        }

        plays++;  // keeping track of plays to end game if it becomes an endless cycle
    }
    else if (plays > 50) {
        std::cout << "This game has been going for a while... So, it can be considered a tie.\n";
    }
    else {
        if (fEarly) {  // the winner has been determined before because game ended early (no possible plays)
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else if (scores.at(0) != scores.at(1)) {  // the game ends because someone has reached 25
            winner = (scores.at(0) > scores.at(1)) ? 0 : 1;
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else {
            std::cout << "Game finished. Both players tied with 24 points.\n";
        }
    }
}

void easyPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names) {
    player = 1;
    int houseTaken, winner;
    bool finished = (scores.at(0) >= 25 || scores.at(1) >= 25 || (scores.at(0) == scores.at(1) &&
        scores.at(0) == 24));
    bool fEarly = false;  // flag that goes true if the game ends before any of the players reaches 25

    int sumP1 = board.at(0) + board.at(1) + board.at(2) + board.at(3) + board.at(4) + board.at(5);
    int sumP2 = board.at(6) + board.at(7) + board.at(8) + board.at(9) + board.at(10) + board.at(11);

    if (sumP1 == 0) {  // p2's turn and p1 has no seeds
        int i;
        for (i = 11; i > 5; i--) {  // go through p2's houses
            if (((i + board.at(i)) % 12 < 6) && board[i] != 0) {  // checks if any of them can give p1 seeds
                houseTaken = i;
                break;  // found a valid play to give p1 a piece
            }
        }
        if (i < 5) {
            scores.at(1) += sumP2;
            fEarly = true;
            finished = true;  // game ended because p1 has 0 seeds and p2 cant give them any
            winner = 1;  // the winner is player 2
        }
    }
    else {
        houseTaken = 6 + (rand() % 6);
        while (board.at(houseTaken) == 0) {  // choosing a random hause, making sure it has seeds
            houseTaken = 6 + (rand() % 6);
        }
    }

    if (!finished) {
        int seedsTaken = board.at(houseTaken);
        int last = lastHouse(board, seedsTaken, houseTaken);
        board.at(houseTaken) = 0;

        std::cout << "EasyBot chose house number " << 12 - houseTaken << std::endl;
        std::cout << "Press ENTER to continue...\n";
        std::getchar();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // plays for EasyBot
        movePieces(seedsTaken, houseTaken, board, scores, names);
        capture(player, scores, board, last);
        showBoard(board, scores, names);

        // calls human turn
        player = 0;  // change player
        playerPlay(player, board, scores, names);

    }
    else {
        if (fEarly) {  // the winner has been determined before
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else if (scores.at(0) != scores.at(1)) {  // the game ends because someone has reached 25
            winner = (scores.at(0) > scores.at(1)) ? 0 : 1;
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else {
            std::cout << "Game finished. Both players tied with 24 points.\n";
        }
    }
}

void hardPlay(int& player, std::vector<int>& board, std::vector<int>& scores, std::vector<std::string> const& names) {
    player = 1;
    int houseTaken, winner;
    bool finished = (scores.at(0) >= 25 || scores.at(1) >= 25 || (scores.at(0) == scores.at(1) &&
        scores.at(0) == 24));
    bool fEarly = false;  // flag that goes true if the game ends before any of the players reaches 25

    int sumP1 = board.at(0) + board.at(1) + board.at(2) + board.at(3) + board.at(4) + board.at(5);
    int sumP2 = board.at(6) + board.at(7) + board.at(8) + board.at(9) + board.at(10) + board.at(11);

    if (sumP1 == 0) {  // p2's turn and p1 has no seeds
        int i;
        for (i = 11; i > 5; i--) {  // go through p2's houses
            if (((i + board.at(i)) % 12 < 6) && board[i] != 0) {  // checks if any of them can give p1 seeds
                houseTaken = i;
                std::cout << "Forced house: " << houseTaken << std::endl;
                break;  // found a valid play to give p1 a piece
            }
        }
        if (i < 5) {
            scores.at(1) += sumP2;
            std::cout << "decided to end early bc i is " << i << std::endl;
            fEarly = true;
            finished = true;  // game ended because p1 has 0 seeds and p2 cant give them any
            winner = 1;  // the winner is player 2
        }
    }
    else {
        int max = 0;
        std::vector<int> possible = outcomes(board, player);

        for (int i = 11; i > 6; i--) {
            if (board.at(i) != 0 && possible.at(11 - i) > max) {
                max = possible.at(11 - i);
                houseTaken = i;
            }
        }
        if (max == 0) {  // no house gives any points, then play random
            houseTaken = 6 + (rand() % 6);
            while (board.at(houseTaken) == 0) {  // choosing a random hause, making sure it has seeds
                houseTaken = 6 + (rand() % 6);
            }
        }
    }

    if (!finished) {
        showBoard(board, scores, names);

        int seedsTaken = board.at(houseTaken);
        int last = lastHouse(board, seedsTaken, houseTaken);
        board.at(houseTaken) = 0;

        std::cout << "HardBot chose house number " << 12 - houseTaken << std::endl;
        std::cout << "Press ENTER to continue...\n";
        std::getchar();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // plays for HardBot
        movePieces(seedsTaken, houseTaken, board, scores, names);
        capture(player, scores, board, last);
        showBoard(board, scores, names);

        // calls human turn
        player = 0;  // change player
        playerPlay(player, board, scores, names);

    }
    else {
        if (fEarly) {  // the winner has been determined before
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else if (scores.at(0) != scores.at(1)) {  // the game ends because someone has reached 25
            winner = (scores.at(0) > scores.at(1)) ? 0 : 1;
            std::cout << "Game finished. The winner is " << names.at(winner) << " with " << scores.at(winner)
                << " points!\n";
        }
        else {
            std::cout << "Game finished. Both players tied with 24 points.\n";
        }
    }
}

std::vector<int> outcomes(std::vector<int>& board, int player) {
    std::vector<int> tempBoard = board;
    std::vector<int> scores = { 0, 0 };
    std::vector<int> outcomes;
    if (player == 1) {
        for (int i = 11; i > 5; i--) {
            int last = lastHouse(board, board.at(i), i);
            if (tempBoard.at(i) != 0) {
                std::cout << "checking bot plays at " << i << std::endl;
                movePieces(tempBoard.at(i), i, tempBoard, scores, { "", "" });
                capture(player, scores, tempBoard, last);
                if (tempBoard.at(0) + tempBoard.at(1) + tempBoard.at(2) + tempBoard.at(3) + tempBoard.at(4) +
                    tempBoard.at(5) != 0) {
                    outcomes.push_back(scores.at(player));
                }
                else {
                    outcomes.push_back(-1);
                }
                scores = { 0, 0 };
                tempBoard = board;
            }
            else {
                outcomes.push_back(-1);  // marks invalid plays with -1
            }
        }
    }
    else {
        for (int i = 0; i < 6; i++) {
            if (tempBoard.at(i) != 0) {
                movePieces(tempBoard.at(i), i, tempBoard, scores, { "", "" });
                capture(player, scores, tempBoard, (i + tempBoard.at(i) % 12));
                outcomes.push_back(scores.at(player));
                scores = { 0, 0 };
            }
            else {
                outcomes.push_back(-1);
            }
        }
    }
    return outcomes;
}

void clrScr() {
#ifdef _WIN32

    COORD coordScreen = { 0, 0 };  // upper left corner
    DWORD cCharsWritten;
    DWORD dwConSize;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hCon, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // fill with spaces
    FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hCon, &csbi);
    FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

    // cursor to upper left corner
    SetConsoleCursorPosition(hCon, coordScreen);

#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

#ifdef _WIN32
void setColor(unsigned int color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}
#else

void setColor(const std::string& color) {
    std::cout << color;
}

#endif
