#include "room.h"
#include <cstring>
#include <iostream>

// Using the standard namespace for cout and strcmp
using namespace std;

// Constructor
Room::Room() {
    initializeArrays();
}

// Destructor
Room::~Room() {
    cleanupArrays();
}

// Initialize dynamic arrays for name, description, exits, and items
void Room::initializeArrays() {
    name = new char[50];
    description = new char[200];
    for (int i = 0; i < 4; ++i) {
        exits[i] = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        items[i] = nullptr;
    }
    itemCount = 0;
}

// Clean up dynamic arrays
void Room::cleanupArrays() {
    delete[] name;
    delete[] description;
    for (int i = 0; i < 5; ++i) {
        delete[] items[i];
    }
}

// Set room information
void Room::setRoom(const char* roomName, const char* roomDescription, Room* north, Room* south, Room* east, Room* west) {
    strcpy(name, roomName);
    strcpy(description, roomDescription);
    exits[0] = north;
    exits[1] = south;
    exits[2] = east;
    exits[3] = west;
}

// Display room information
void Room::displayRoomInfo() {
    cout << "You are in " << name << ". " << description << "\n";
    cout << "Exits:";
    for (int i = 0; i < 4; ++i) {
        if (exits[i] != nullptr) {
            cout << " " << (i == 0 ? "NORTH" : (i == 1 ? "SOUTH" : (i == 2 ? "EAST" : "WEST")));
        }
    }
    cout << "\n";

    if (itemCount > 0) {
        cout << "Items in the room:";
        for (int i = 0; i < itemCount; ++i) {
            cout << " " << items[i];
        }
        cout << "\n";
    }
}

// Add item to the room
void Room::addItem(const char* item) {
    if (itemCount < 5) {
        items[itemCount++] = strdup(item);
        cout << "You have found a " << item << ".\n";
    } else {
        cout << "The room is full of items. You cannot carry more.\n";
    }
}

// Pick up an item from the room
void Room::pickupItem() {
    if (itemCount > 0) {
        cout << "You picked up " << items[--itemCount] << ".\n";
    } else {
        cout << "There are no items to pick up in this room.\n";
    }
}

// Drop an item in the room
void Room::dropItem() {
    if (itemCount > 0) {
        cout << "You dropped " << items[--itemCount] << ".\n";
    } else {
        cout << "You have no items to drop.\n";
    }
}

// Move to the next room based on the specified direction
Room* Room::moveToNextRoom(const char* direction) {
    if (strcmp(direction, "NORTH") == 0 && exits[0] != nullptr) {
        return exits[0];
    } else if (strcmp(direction, "SOUTH") == 0 && exits[1] != nullptr) {
        return exits[1];
    } else if (strcmp(direction, "EAST") == 0 && exits[2] != nullptr) {
        return exits[2];
    } else if (strcmp(direction, "WEST") == 0 && exits[3] != nullptr) {
        return exits[3];
    }
    return nullptr;
}

// Check the winning condition
bool Room::checkWinningCondition() {
    // Check the winning condition (e.g., finding a specific item and reaching a specific room)
    return (strcmp(name, "Secret Lab") == 0 && itemCount > 0 && strcmp(items[0], "Blueprints") == 0);
}
