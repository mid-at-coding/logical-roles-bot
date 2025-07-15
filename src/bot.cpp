#include "../inc/bot.hpp"
#include <dpp/dispatcher.h>
#include <dpp/intents.h>

Bot::Bot(std::string tokenIn) : token(tokenIn), bot(tokenIn, dpp::i_default_intents | dpp::i_message_content) {
	bot.on_log(dpp::utility::cout_logger());
	bot.on_message_create([this](const dpp::message_create_t &in){
			Command(in, this->bot);
		});
}

void Bot::Wait(){
	bot.start(dpp::st_wait);
}
