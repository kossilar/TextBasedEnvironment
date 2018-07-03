using namespace std;

#include <iostream>
#include <vector>
#include "./entity.h"
#include "./action.h"
#include "./word.h"
#include "./objects.h"

Open openAction();
Look lookAction();

Verb open("open", * openAction);

vector <Word*> playerVocabulary();
playerVocabulary -> addWord(open);

class Player : public Entity
{
	private:
		Vocabulary vocabulary();
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
		Player(string name, Room location) : Entity(name, location){};

		string parse(string input) {
			int whiteSpaceIndex = input.find(' ');
			while (input.length() > 0)
			{
				while (whiteSpaceIndex == 0)
				{
					input.erase(0,1);
					whiteSpaceIndex = input.find(' ');
				}

			}
		/*	switch(commandMap[input])
			{
				case look:
				{
					break;
				}
				case quit:
				{
					cout << "I quit!" << "/n";
					exit(0);
					break;
				}
			default:
				return  "I don't know how to " + words[0] + "\n";
			}*/
			return "ETC";
		}
		string lookAt()
		{
			return location.getLongDesc();
		}

		string lookAt(Entity target)
		{
			return target.getDescription();
		}
};

int main()
{
	string playerName;
	string input;
	static bool gameover = false;


	cout << "What is your name? -> ";
	getline(cin, playerName);
	Player player(playerName, smallCell);
	cout <<	player.lookAt() << endl;
	do{
		cout << "What do you do? -> ";
		getline(cin, input);
		cout << player.parse(input) << "\n";
	} while(!gameover);
	return 0;
};
