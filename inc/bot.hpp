#pragma once
#include <dpp/cluster.h>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <string>

template <std::string BotCommand>
class Bot{
public:
	Bot(std::string tokenIn) : token(tokenIn), bot(tokenIn, dpp::i_default_intents | dpp::i_message_content) {
		bot.on_log(dpp::utility::cout_logger());
		bot.on_message_create([this](const dpp::message_create_t &in){
				if(!in.msg.content.rfind(botCommand, 0)){ // if the bot command string is at the beginning of the message
					Command(in, this->bot);
				}
			});
	}

	void Wait();
private:
	std::string token;
	dpp::cluster bot;
	static void Command(const dpp::message_create_t &in, dpp::cluster &bot);
};
