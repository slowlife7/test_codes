#include <memory>
#include <list>
#include <string>
#include <map>

#include "User.h"
#include "Room.h"
#include "Lobby.h"

static int roomNumber = 1;
static const int maxUser = 8;

std::shared_ptr<Lobby> lobby = std::make_shared<Lobby>();
std::map<int, std::shared_ptr<User>> users;
std::map<std::string, RoomPtr> rooms;

void joinRoom(int fd, const char* room_) {

	auto f = rooms.find(room_);
	if (f != rooms.end()) {
		users[fd]->join(f->second);
		return;
	}
	
	rooms[room_] = std::make_shared<Room>(lobby, room_, maxUser, roomNumber);
	users[fd]->join(rooms[room_]);
	lobby->add(rooms[room_]);
}

void send(int fd, const char* msg_) {
	users[fd]->send(msg_);
}

void leaveRoom(int fd) {
	users[fd]->leave();
	users.erase(fd);
}

int main() {

	int fds[] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i < sizeof(fds) / sizeof(int) +1; i++) {
		std::string t = std::to_string(i) + "billy";
		users[i+1] = std::make_shared<User>(t.c_str());
	}

	joinRoom(1, "test1");
	joinRoom(2, "test1");
	joinRoom(3, "test1");
	joinRoom(4, "test1");
	joinRoom(5, "test2");
	joinRoom(6, "test2");
	joinRoom(7, "test3");
	joinRoom(8, "test3");

	lobby->print();

	send(1, "hello");
	send(2, "hihi");

	leaveRoom(1);
	leaveRoom(2);
	leaveRoom(3);
	leaveRoom(4);
	leaveRoom(5);
	leaveRoom(6);
	leaveRoom(7);
	leaveRoom(8);

	/*std::shared_ptr<User> user1 = std::make_shared<User>("billy");
	std::shared_ptr<User> user2 = std::make_shared<User>("miller");
	std::shared_ptr<User> user3 = std::make_shared<User>("herry");
	std::shared_ptr<User> user4 = std::make_shared<User>("herry1");

	std::shared_ptr<User> user5 = std::make_shared<User>("billy1");
	std::shared_ptr<User> user6 = std::make_shared<User>("miller2");
	std::shared_ptr<User> user7 = std::make_shared<User>("herry3");
	std::shared_ptr<User> user8 = std::make_shared<User>("herry4");

	std::shared_ptr<Room> test1 = std::make_shared<Room>(lobby, "test1", 8, 1);
	std::shared_ptr<Room> test2 = std::make_shared<Room>(lobby, "test2", 8, 2);
	std::shared_ptr<Room> test3 = std::make_shared<Room>(lobby, "test3", 8, 3);
	std::shared_ptr<Room> test4 = std::make_shared<Room>(lobby, "test4", 8, 4);

	lobby->add(test1);
	lobby->add(test2);
	lobby->add(test3);
	lobby->add(test4);

	user1->join(test1);
	user2->join(test1);
	user3->join(test1);
	user4->join(test2);

	user5->join(test1);
	user6->join(test1);
	user7->join(test1);
	user8->join(test3);

	lobby->print();

	user1->send("hello");
	user4->send("hihi");
	user2->send("how are you");

	user1->leave();
	user2->leave();
	user3->leave();
	user4->leave();
	user5->leave();
	user6->leave();
	user7->leave();
	user8->leave(); */

	return 0;
}