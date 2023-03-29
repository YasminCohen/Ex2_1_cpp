#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 0")
{
    Player p1("one");
    CHECK_THROWS(Game {p1,p1});//A player cannot play against himself.
    Player p2("");
    CHECK_THROWS(Game {p1,p2});//A player cannot play against someone unspecified who does not have a name.
}

TEST_CASE("Test 1")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    bool flag1 = ((p1.stacksize() == 26) && (p2.stacksize() == 26)); //prints the amount of cards left.
    //At the beginning of the game both players have the same number of cards.
    CHECK(flag1);
    bool flag2 = ((p1.cardesTaken() == 0) && (p2.cardesTaken() == 0)); // prints the amount of cards this player has won.
    //But nobody won because they didn't play even one turn in the game. Therefore both players will have 0 cards.
    CHECK(flag2);
}

TEST_CASE("Test 2")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);

    int i =0;
    while (i < 3)
    {
        game.playTurn();
        i++;
    }
    bool flag1 = ((p1.stacksize() <= 23 )&& (p2.stacksize() <= 23)); //prints the amount of cards left. should be 23 but can be less if a draw was played
    CHECK(flag1); 
    CHECK_THROWS(game.printWiner()); //It is not possible to print the winner yet because the game is not over yet.
}

TEST_CASE("Test 3")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn()); //It is impossible to print the player of the last turn because the game hasn't started yet so there was no last turn.
    game.playTurn();
    bool flag = (p1.stacksize() < 26);
    bool flag2 = (p2.stacksize() < 26);
    CHECK(flag); //There was one turn so each player took down at least one card, if there was a tie then more.
    CHECK(flag2); //There was one turn so each player took down at least one card, if there was a tie then more.
}


TEST_CASE("Test 4")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    game.printStats();
    CHECK_THROWS(game.printWiner()); //You can't print the winner if you haven't started playing yet.

}

TEST_CASE("Test 5")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    CHECK_THROWS(game.printLog()); //It is impossible to print because the game has not yet started.
    game.playAll(); //playes the game untill the end
    CHECK_THROWS(game.playAll());//You can't play everything again after the game is over.
}

TEST_CASE("Test 6")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());//You cannot play another turn after the game is over.
    CHECK(((p1.stacksize()==0)&&(p2.stacksize()==0))); //After the game is over, the number of cards left by the players should be 0.
}

TEST_CASE("Test 7")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn()); //The function should return the last row and should not return an error.
    CHECK_NOTHROW(game.printStats());    //The function should not return an error.
}
TEST_CASE("Test 8")
{
    Player p1("one");
    Player p2("two");
    Game game(p1, p2);
    game.playAll();
    CHECK((p1.cardesTaken()+ p2.cardesTaken()+p1.stacksize()+p2.stacksize()) == 52);
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Test 9")
{
    Player p1("one");
    Player p2("two");
//Because the game hasn't started yet, the players' fields should be 0. The cards have not been dealt yet.
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}