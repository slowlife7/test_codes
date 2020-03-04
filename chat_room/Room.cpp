
#include "Room.h"
#include "User.h"
#include "Lobby.h"

#include <functional>

void Room::join(UserPtr user) {
	users.push_back(user);
	notify("[" + std::to_string(number_) + "]" + user->getUserid() + "�� �����Ͽ����ϴ�.");
	notify("[" + std::to_string(number_) + "] (" + std::to_string(users.size()) + ")");
}

bool remover1( std::string pred,  std::string pred1) {
	return pred == pred1;
}

void Room::leave(UserPtr user) {
	users.remove(user);
	notify("["+std::to_string(number_)+"]"+user->getUserid() + "�� �������ϴ�.");
	notify("[" + std::to_string(number_) + "] ("+std::to_string(users.size())+")");
	if (users.size() < 1) {
		auto l = lobby_.lock();
		if (l) {
			l->remove(this->getPtr());
		}
	}
}

void Room::notify(std::string msg) {
	for (auto u : users) {
		u->notify(msg);
	}
}

void Room::send(std::string from, std::string msg) {
	for (auto u : users) {
		u->recv(from, msg);
	}
}
