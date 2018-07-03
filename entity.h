#include <map>
const string DIRECTIONS[10] = {"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest", "up",
"down"};

class Room
{
	private:
		string shortDesc, longDesc;
	public:
		string getShortDesc() { return shortDesc; }
		string getLongDesc() { return longDesc; }

		// Default constructor
		Room() {
			this -> shortDesc = "The void.";
			this -> longDesc = "An empty space outside the universe.";
		}

		// Constructor
		Room(string shortDesc, string longDesc)
		{
			this -> shortDesc = shortDesc;
			this -> longDesc = longDesc;
		}
		void addExit() {
		}

};

class Entity
{
	protected:
		string name = "";
		string description;
		Room location;
	public:
		Entity(string name) {
			this -> name = name;
		}
		Entity(string name, Room location)
		{
			this -> name = name;
			this -> location = location;
		}

		string getName() { return name; }
		string getDescription() { return description; }
		Room getLocation() { return location; }
		virtual ~Entity(){};
};

class Exit : public Entity
{
        private:
                string shortDesc;
                Room firstRoom, secondRoom;
        public:
                // Default contsructor
                Exit(string shortDesc, Room firstRoom, Room secondRoom) : Entity (shortDesc){
                        this -> firstRoom = firstRoom;
                        this -> secondRoom = secondRoom;
                }
                string getShortDescription() {
                        return this -> name;
                }
};

// isOpenable interface
class IsOpenable
{
        public:
                ~IsOpenable();
                virtual string open();
                virtual string close();
                virtual bool checkIsOpen();
};

class Door : public IsOpenable, public Exit
{
        private:
                bool isOpen;
        public:
                // Default constructor
                Door(string shortDesc, Room firstRoom, Room secondRoom, bool isOpen) : Exit(shortDesc, firstRoom,
secondRoom)
                {
                        this -> isOpen = isOpen;
                }

                string open()
                {
                        if (this -> isOpen)
                                return this -> getShortDescription() + " is already open.";
                        else
                        {
                                this -> isOpen = true;
                                return this -> getShortDescription() + " is now open.";
                        }
                }
                string close()
                {
                        if (!this -> isOpen)
                                return this -> getShortDescription() + " is already closed.";
                        else
                        {
                                this -> isOpen = false;
                                return this -> getShortDescription() + "is now closed.";
                        }
                }

};

// Room instantiations
