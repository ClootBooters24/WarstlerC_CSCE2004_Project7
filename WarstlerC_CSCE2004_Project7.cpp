// WarstlerC_CSCE2004_Project7.cpp : This file contains the 'main' function. Program execution begins and ends there.

//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
// Author:  John Gauch (Clayton Warstler)
//------------------------------------------------------------
#include "cave.h"

int main()
{
    // Initialize game
    srand(time(NULL));

    // Initialize player
    Player player;

    //Create player
    player.setName("Grett");
    player.setHealth(MAX_HEALTH);
    player.setGold(0);
    player.setItems("");

    player.Print();

    // Initialize cave
    Cave cave;

    // TO BE ADDED
    cave.ReadRooms("rooms.txt");
    cave.ReadMap("map.txt");
    cave.WriteRooms("WriteRooms.txt");
    cave.WriteMap("WriteMap.txt");

    // Explore cave until player wins or dies
    // TO BE ADDED
    int roomNum = 0;

    //As long as player has health and not maximum gold, go to the next room
    while ((player.getHealth() != 0) && (player.getGold() < MAX_GOLD))
    {
        player.Print();
        cout << "\nRoom Number: " << roomNum;
        cave.VisitRoom(roomNum, player);
        roomNum = cave.NextRoom(roomNum);
    }

    // Print final message
    if (player.getHealth() == 0)
        cout << "\nSorry, you died exploring the cave." << endl;
    else
        cout << "\nYou leave the cave with " << MAX_GOLD << " gold coins!" << endl;
    return 0;
}