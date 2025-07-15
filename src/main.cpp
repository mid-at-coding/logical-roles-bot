#include "../inc/bot.hpp"
#include <string>
int main(){
	const std::string botCommand = ".ping";
	Bot<botCommand> bot("token");
	bot.Wait();
	return 0; // holy OOP
}
