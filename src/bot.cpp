#include "../inc/bot.hpp"
#include <dpp/dispatcher.h>
#include <dpp/intents.h>

void Bot::Wait(){
	bot.start(dpp::st_wait);
}
