#include "../inc/bot.hpp"
#include <dpp/dispatcher.h>
#include <dpp/intents.h>

void Bot::Wait(){
	bot.start(dpp::st_wait);
}

void Bot::Init(){
	RegenerateRoles();
}

void Bot::RegenerateRoles(){
	// get a list of all roles
	// DPP manages these as a cache which is a hash map, so there's not exactly a better way to do this...
	// TODO: surely there is a better way
	std::vector<dpp::snowflake> roles_tmp;
	for(uint64_t i = 0; i != UINT64_MAX; i++){
		dpp::snowflake role = dpp::find_role(i)->id;
		if(role)
			roles_tmp.push_back(role);
	}
	// ...
	std::vector<dpp::snowflake> users;
	std::vector<User> Users;
	for(uint64_t i = 0; i != UINT64_MAX; i++){
		dpp::guild_member user = dpp::find_guild_member(guildId, i);
		if(user.user_id){
			User tmp;
			tmp.ID = user.user_id;
			tmp.Roles = user.get_roles();
		}
	}
	for(const dpp::snowflake &roleID : roles_tmp)
		roles.emplace(roleID, Role(roleID, Users));
}
