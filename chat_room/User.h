#pragma once

#include <string>
#include <list>
#include <memory>
class Room;
typedef std::weak_ptr<Room> RoomWeakPtr;
typedef std::shared_ptr<Room> RoomPtr;
class User : public std::enable_shared_from_this<User> {
public:
	User(const char* userid);
	void join(RoomPtr& room);
	
	void leave();
	
	void send(std::string msg);
	void recv(std::string from, std::string msg);
	void notify(std::string msg);

	std::string getUserid() ;

	std::shared_ptr<User> getPtr() {
		return shared_from_this();
	}

private:
	//Weak_Ptr<Room>
	RoomWeakPtr room_;
	std::string userid_;
};