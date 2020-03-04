#include "Lobby.h"
#include "Room.h"

#include <iostream>
#include <algorithm>
#include <functional>

void Lobby::add(RoomPtr room) {
	rooms.push_back(room);
	std::cout << "¹æ °¹¼ö:" << rooms.size() << std::endl;
}

bool remover(int i, int j) {
	return i == j;
}

void Lobby::remove(RoomPtr room) {

	rooms.remove(room);
	std::cout << "³²Àº ¹æ °¹¼ö:" << rooms.size() << std::endl;
}

void Lobby::print()
{
	for (auto r : rooms) {
		r->info();
	}
}