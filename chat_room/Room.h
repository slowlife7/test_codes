#pragma once
#include <list>
#include <string>
#include <memory>
#include <iostream>

class User;
class Lobby;

typedef std::weak_ptr<Lobby> LobbyWeakPtr;
typedef std::shared_ptr<User> UserPtr;

class Room : public std::enable_shared_from_this<Room> {
public:
	Room(LobbyWeakPtr lobby, const std::string& title, const int max, const int number ) : lobby_(lobby), title_(title), max_(max), number_(number) {}

	void join(UserPtr user);
	void leave(UserPtr user);
	void send(std::string from, std::string msg);
	void notify(std::string msg);

	std::shared_ptr<Room> getPtr() {
		return shared_from_this();
	}

	void info() {
		std::cout << "=====================================================" << std::endl;
		std::cout << "[" << number_ << "]" << title_ << "-" << "(" << users.size() << "/" << max_ << ")" << std::endl;
		std::cout << "=====================================================" << std::endl;
	}

private:
	const int number_;
	const int max_;
	const std::string title_;

	LobbyWeakPtr lobby_;
	std::list<UserPtr> users;
};