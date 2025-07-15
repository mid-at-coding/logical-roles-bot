#include "../inc/bot.hpp"
#include <string>
int main(int argc, char **argv){
	if(argc < 2){
		std::cout << "Input bot token!" << std::endl;
		exit(0);
	}
	if(argc < 3){
		std::cout << "Input guild id!" << std::endl;
		exit(0);
	}
	std::string botCommand = ".ping";
	std::string token = argv[1];
	dpp::snowflake guildId = std::stoi(argv[2]);
	Bot bot(token, botCommand, guildId);
	bot.Wait();
	return 0; // holy OOP
}
