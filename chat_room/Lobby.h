#pragma once

#include <list>
#include <memory>

class Room;
typedef std::shared_ptr<Room> RoomPtr;

class Lobby {
public:
	void add(RoomPtr room);
	void remove(RoomPtr room);
	void print();

private:
	std::list<RoomPtr> rooms;
};