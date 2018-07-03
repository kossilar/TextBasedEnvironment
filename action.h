// command functions

class Action
{
	private:
	public:
		virtual string execute(Entity* target) = 0;
		virtual ~Action() {};
};

class Open : public Action {
	public:
		Open(){}
		~Open(){}
		string execute(Entity* target) {
			Door* door = dynamic_cast<Door*>(target);
			if (door) {
				return door -> open();

			} else {
				cout << "I can't open that." << "\n";
			}
		}
};

class Look : public Action {
	public:
		string execute(Entity* target)
		{
			return target -> getDescription() + "\n";
		}
};
