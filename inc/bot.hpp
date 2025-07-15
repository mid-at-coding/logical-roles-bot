#pragma once
#include <dpp/cluster.h>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>

class Bot{
public:
	Bot(std::string tokenIn);
	void Wait();
private:
	std::string token;
	dpp::cluster bot;
	static void Command(const dpp::message_create_t &in, dpp::cluster &bot);
};
