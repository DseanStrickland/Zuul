#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    Room();
    ~Room();

    void setRoom(const char* name, const char* description, Room* north, Room* south, Room* east, Room* west);
    void displayRoomInfo();
    void addItem(const char* item);
    void pickupItem();
    void dropItem();
    Room* moveToNextRoom(const char* direction);
    bool checkWinningCondition();

private:
    char* name;
    char* description;
    Room* exits[4];
    char* items[5];
    int itemCount;

    void initializeArrays();
    void cleanupArrays();
};

#endif // ROOM_H
