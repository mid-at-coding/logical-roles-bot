#pragma once
#include "role.hpp"
#include <dpp/cluster.h>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <string>

class Bot{
public:
	Bot(std::string tokenIn, std::string botCommand) : token(tokenIn), bot(tokenIn, dpp::i_default_intents | dpp::i_message_content) {
		this->botCommand = botCommand;
		bot.on_log(dpp::utility::cout_logger());
		bot.on_message_create([this](const dpp::message_create_t &in){
				if(!in.msg.content.rfind(this->botCommand, 0)){ // if the bot command string is at the beginning of the message
					Command(in, this);
				}
			});
	}

	void Wait();
private:
	absl::flat_hash_map<dpp::snowflake, Role> roles;
	std::string token;
	std::string botCommand;
	dpp::cluster bot;
	void Init();
	void RegenerateRoles();
	static void Command(const dpp::message_create_t &in, Bot *bot);
};
