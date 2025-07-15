#include "../inc/bot.hpp"
#include <string>
int main(int argc, char **argv){
	if(argc < 2){
		std::cout << "Input bot token!" << std::endl;
		exit(0);
	}
	std::string botCommand = ".ping";
	std::string token = argv[1];
	Bot bot(token, botCommand);
	bot.Wait();
	return 0; // holy OOP
}
