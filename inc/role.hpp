#pragma once
#include <absl/container/flat_hash_map.h>
#include <absl/container/flat_hash_set.h>
#include <dpp/snowflake.h>
#include <vector>
#include "user.hpp"
class RoleSet{
	absl::flat_hash_set<dpp::snowflake> Users;
public:
	RoleSet (const RoleSet&) = delete;
	RoleSet& operator= (const RoleSet&) = delete;
	absl::flat_hash_set<dpp::snowflake>& GetUsers();
	RoleSet& operator* (const RoleSet&); // AND
	RoleSet& operator^ (const RoleSet&); // XOR
	RoleSet& operator+ (const RoleSet&); // OR
};
class Role{
public:
	Role(dpp::snowflake RoleID, std::vector<User> &users);
	RoleSet& GetAllUsers(bool complement = false);
private:
	RoleSet UsersWithRole;
	RoleSet UsersWithoutRole;
};
