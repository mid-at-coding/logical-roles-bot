#pragma once
#include <absl/container/flat_hash_set.h>
#include <dpp/snowflake.h>
class User{
public:
	dpp::snowflake ID;
	absl::flat_hash_set<dpp::snowflake> Roles;
};
