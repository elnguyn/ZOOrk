//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"
#include <algorithm>
#include <iostream>

Player* Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::removeItem(const std::string& itemName) {
    auto it = std::remove_if(inventory.begin(), inventory.end(), [&](Item* item) {
        return item->getName() == itemName;
        });
    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
    }
}

Item* Player::getItem(const std::string& itemName) {
    for (auto& item : inventory) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

Item* Player::retrieveItem(const std::string& itemName) {
    Item* item = getItem(itemName);
    if (item) {
        removeItem(itemName);
    }
    return item;
}

void Player::showInventory() const {
    if (inventory.empty()) {
        std::cout << "Your inventory is empty.\n";
    }
    else {
        std::cout << "You are carrying:\n";
        for (const auto& item : inventory) {
            std::cout << "- " << item->getName() << ": " << item->getDescription() << "\n";
        }
    }
}
