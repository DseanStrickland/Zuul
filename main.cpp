// Arjun Pai
// Project: ZUUL - Spy Mission Adventure Game
// Credits: Debugging and Logic Help by Ramachandra Pai

#include "room.h"
#include <iostream>
#include <cstring>

// Using the standard namespace for cout and strcmp
using namespace std;

int main() {
    // Create rooms
    Room* rooms[3][5]; // 3 rows, 5 columns

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            rooms[i][j] = new Room();
        }
    }

    // Set room descriptions, items, and exits for the building
    // Row 0
    rooms[0][0]->setRoom("Lobby", "You are in the Lobby. Begin your spy mission here.", nullptr, rooms[0][1], nullptr, nullptr);
    rooms[0][1]->setRoom("Corridor 1", "You are in Corridor 1. Access to multiple rooms.", rooms[0][0], rooms[1][1], rooms[0][2], nullptr);
    rooms[0][2]->setRoom("Storage Room", "You are in the Storage Room. Supplies and tools are scattered around.", nullptr, nullptr, rooms[0][1], rooms[0][3]);
    rooms[0][3]->setRoom("Secret Lab", "You are in the lab. Secret meetings are held here.", nullptr, nullptr, rooms[0][2], rooms[1][0]);
    rooms[0][4]->setRoom("Corridor 2", "You are in Corridor 2. Connects to various rooms.", rooms[0][3], rooms[1][1], rooms[0][5], rooms[0][1]);
    
    // Row 1
    rooms[0][5]->setRoom("CEO's Office", "You are in the CEO's Office. Find valuable intel here.", rooms[0][3], nullptr, rooms[1][1], nullptr);
    rooms[0][6]->setRoom("Escape Tunnel", "You are in the Escape Tunnel. Plan your exit carefully.", rooms[1][0], nullptr, nullptr, nullptr);
    rooms[0][7]->setRoom("Agent Quarters", "You are in Agent Quarters. Rest and gather intelligence.", nullptr, rooms[1][3], nullptr, nullptr);
    rooms[0][8]->setRoom("Surveillance Center", "You are in the Surveillance Center. Monitor enemy activities.", rooms[1][2], nullptr, nullptr, nullptr);

    // Row 2
    rooms[0][9]->setRoom("Training Room", "You are in the Training Room. Sharpen your spy skills.", rooms[0][1], rooms[1][0], rooms[0][4], rooms[0][2]);
    rooms[0][10]->setRoom("Security Room", "You are in the Security Room. Monitor surveillance cameras.", rooms[0][4], rooms[1][0], rooms[0][7], rooms[0][5]);
    rooms[0][11]->setRoom("Corridor 3", "You are in Corridor 3. Access to more rooms.", rooms[0][2], rooms[1][2], nullptr, nullptr);
    rooms[0][12]->setRoom("CEO's Office 2", "You are in the CEO's Office 2. Find valuable intel here.", rooms[0][3], nullptr, rooms[1][1], nullptr);
    rooms[0][13]->setRoom("Escape Tunnel 2", "You are in the Escape Tunnel 2. Plan your exit carefully.", rooms[1][0], nullptr, nullptr, nullptr);
    rooms[0][14]->setRoom("Hidden Room", "You are in the Hidden Room. A secret space with unknown purposes.", nullptr, nullptr, rooms[1][2], nullptr);

    // Set items in rooms
    rooms[0][1]->addItem("Blueprints");  // Winning Item
    rooms[0][2]->addItem("Lockpicking Kit");
    rooms[0][3]->addItem("Night Vision Goggles");
    rooms[0][4]->addItem("Secret Documents");
    rooms[0][0]->addItem("Spyglass");
    rooms[0][1]->addItem("Disguise Kit");
    rooms[0][2]->addItem("First Aid Kit");
    rooms[0][3]->addItem("Smoke Grenade");
    rooms[0][4]->addItem("Invisibility Cloak");
    rooms[0][5]->addItem("Unknown Device");

    // Game loop
    Room* currentRoom = rooms[0][0];
    while (true) {
        currentRoom->displayRoomInfo();
        char input[10];
        cin >> input;

        if (strcmp(input, "QUIT") == 0) {
            cout << "You have quit the game. Better luck next time!\n";
            break;
        } else if (strcmp(input, "PICKUP") == 0) {
            currentRoom->pickupItem();
        } else if (strcmp(input, "DROP") == 0) {
            currentRoom->dropItem();
        } else if (strcmp(input, "NORTH") == 0 || strcmp(input, "SOUTH") == 0 || strcmp(input, "EAST") == 0 || strcmp(input, "WEST") == 0) {
            Room* nextRoom = currentRoom->moveToNextRoom(input);
            if (nextRoom == nullptr) {
                cout << "You can't go that way.\n";
            } else {
                currentRoom = nextRoom;
            }
        } else {
            cout << "Invalid command. Try again.\n";
        }

        // Check winning condition
        if (currentRoom->checkWinningCondition()) {
            cout << "Congratulations! You've completed your spy mission.\n";
            break;
        }
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            delete rooms[i][j];
        }
    }

    return 0;
}
