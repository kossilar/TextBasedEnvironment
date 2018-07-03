class Word
{
	protected:
		string text;
	public:
		Word (string text) 
		{
			this -> text = text;
		}
		virtual string getText(){ return text; }
		~Word(){};
};

class Noun : Word
{
	private:
		Entity* reference;
	public: 
		Noun(string text, Entity* reference) : Word (text) 
		{
			this -> reference = reference;
		}
		Entity* getReference()
		{
			return reference;
		}
};

class Verb : Word
{
	private:
		Action* action;
	public:
		Verb(string text, Action* action) : Word (text)
		{
			this -> action = action;
		}

		string doIt(Entity* target)
		{
			return this -> action -> execute(target);
		}
};

class Phrase 
{
	private:
		vector<Action*> words;
	public:
		void addWord(Word* word) {

		}
};

class Vocabulary
{
	private:
		vector <Word*> contents;
	public:
		Vocabulary(){}
		Vocabulary(vector <Word*> wordVector)
		{
			this -> contents = wordVector;
		}
		~Vocabulary(){}
		Word* searchWord(string text)
		{
			for(int i =0; i < contents.size(); ++i)
			{
				if(contents[i] -> getText() == text)
				{
					return contents[i];
				}
			}
		}
		int addWord(Word* input){
			contents.push_back(input);
			return contents.size();
		}
		int addWord(string input) 
		{
			Word newWord(input);
			return contents.size();
		}
};

