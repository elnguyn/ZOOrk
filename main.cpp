#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"


int main() {
    std::shared_ptr<Room> start = std::make_shared<Room>("start-room",
                           "You are standing in an open field west of a white house, with a boarded front door.\n");

    std::shared_ptr<Room> south_of_house = std::make_shared<Room>("south-of-house",
                                    "You are facing the south side of a white house.  There is no door here, and all the windows are barred.\n");

    std::shared_ptr<Room> behind_house = std::make_shared<Room>("behind-house",
                                  "You are behind the white house. A path leads into the forest to the east. In one corner of the house there is a small window which is slightly ajar.\n");
    
    std::shared_ptr<Room> forest = std::make_shared<Room>("forest",
                                  "You are in a dark and mysterious forest.\n");
    
    std::shared_ptr<Room> cave = std::make_shared<Room>("cave", 
                                  "You are in a damp and musty cave.\n");
   
    std::shared_ptr<Room> mountain = std::make_shared<Room>("mountain", 
                                  "You are standing at the foot of a tall mountain.\n");
    
    std::shared_ptr<Room> valley = std::make_shared<Room>("valley",
                                  "You are in a green and peaceful valley.\n");
    
    std::shared_ptr<Room> river = std::make_shared<Room>("river", 
                                  "You are standing on the banks of a fast-flowing river.\n");
    
    std::shared_ptr<Room> lake = std::make_shared<Room>("lake",
                                  "You are standing on the shores of a serene lake.\n");
    
    std::shared_ptr<Room> island = std::make_shared<Room>("island", 
                                  "You are standing on a small island in the middle of the lake.\n");

    Passage::createBasicPassage(start.get(), south_of_house.get(), "south", true);
    Passage::createBasicPassage(south_of_house.get(), behind_house.get(), "east", true);
    Passage::createBasicPassage(behind_house.get(), forest.get(), "east", true);
    Passage::createBasicPassage(forest.get(), cave.get(), "north", true);
    Passage::createBasicPassage(cave.get(), mountain.get(), "east", true);
    Passage::createBasicPassage(mountain.get(), valley.get(), "south", true);
    Passage::createBasicPassage(valley.get(), river.get(), "east", true);
    Passage::createBasicPassage(river.get(), lake.get(), "north", true);
    Passage::createBasicPassage(lake.get(), island.get(), "east", true);

    ZOOrkEngine zoork(start);

    zoork.run();

    return 0;
}
