// Parser

#include <vector>
#include <map>

const string DIRECTIONS[10] = {"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest", "up", 
"down"};


class Parser
{
	private:
		enum validCommands {examine, get, lock, look, open, quit, read, take, unlock};
		struct commandMap : public map<string, validCommands>
		{
			commandMap()
			{
				this->operator[]("examine") = examine;
				this->operator[]("get") = get;
				this->operator[]("lock") = lock;
				this->operator[]("look") = look;
				this->operator[]("open") = open;
				this->operator[]("quit") = quit;
				this->operator[]("read") = read;
				this->operator[]("take") = take;
				this->operator[]("unlock") = unlock;
			};
		};
		commandMap commands;
	public:
		Parser(){};
		bool parse(string input) {
			vector <string> words;
			while(input.size() > 0)
			{
				int indexOfSpace = input.find_first_of(' ');
				while(indexOfSpace == 0)
				{
					input.erase(0, 1);
					indexOfSpace = input.find_first_of(' ');
				}
				words.push_back(input.substr(0, indexOfSpace));
				input.erase(0, indexOfSpace);
			};
			if(commands.count(words[0]))
			{
				switch(commands[words[0]]) {
					case look: { break; }
					case quit: { exit(EXIT_SUCCESS); break; }
				}
			}
			else
				cout << "I don't know how to " <<  words[0] << "\n";
			return false;			
		};
};


