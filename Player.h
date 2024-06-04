//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include "Item.h"
#include <vector>

class Player : public Character {
public:
    static Player* instance() {
        if (!playerInstance) {
            playerInstance = new Player();
        }
        return Player::playerInstance;
    }

    void setCurrentRoom(Room*);
    Room* getCurrentRoom() const;

    void addItem(Item*);
    void removeItem(const std::string&);
    Item* getItem(const std::string&);
    Item* retrieveItem(const std::string&);
    void showInventory() const;

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

private:
    static Player* playerInstance;
    Room* currentRoom;
    std::vector<Item*> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you."),
        currentRoom(new NullRoom()) {}
};

#endif //ZOORK_PLAYER_H
