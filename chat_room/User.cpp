#include "User.h"
#include "Room.h"
#include <iostream>

User::User(const char* userid) : userid_(userid) {}

void User::join(RoomPtr& room) {
	room_ = room;
	RoomPtr roomPtr = room_.lock();
	if (roomPtr)
	{
		roomPtr->join(this->getPtr());
	}
}
void User::leave() {
	RoomPtr roomPtr = room_.lock();
	if (roomPtr)
	{
		roomPtr->leave(this->getPtr());
	}
}
void User::send(std::string msg) {
	RoomPtr roomPtr = room_.lock();
	if (roomPtr)
	{
		roomPtr->send(userid_, msg);
	}
}
void User::recv(std::string from, std::string msg) {
	std::cout << "["<< from <<"] "<<msg << std::endl;
}
void User::notify(std::string msg)
{
	std::cout << msg << std::endl;
}

std::string User::getUserid()  {
	return userid_;
}

