#pragma once
#include <absl/container/flat_hash_set.h>
#include <dpp/snowflake.h>
class User{
public:
	dpp::snowflake ID;
	std::vector<dpp::snowflake> Roles;
};
