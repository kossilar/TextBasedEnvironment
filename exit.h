class Exit
{
        private:
                string shortDesc;
                Room firstRoom, secondRoom;
        public:
                // Default contsructor
                Exit(string shortDesc, Room firstRoom, Room secondRoom) {
                        this -> shortDesc = shortDesc;
                        this -> firstRoom = firstRoom;
                        this -> secondRoom = secondRoom;
                }
		string getShortDescription() {
			return shortDesc;

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
		bool checkIsOpen(){
			return isOpen;
		}
};
