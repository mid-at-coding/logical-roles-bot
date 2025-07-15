#pragma once
#include "role.hpp"
class Parser{
	std::vector<Role> &roles;
public:
	Parser(std::vector<Role> &rolesIn);
	RoleSet &Parse(std::string);
};
