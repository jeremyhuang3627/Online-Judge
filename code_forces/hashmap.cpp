class Node{
private:
	int key,value;
public:
	Node(int k,int v){
		this->key = k; 
		this->value = v;
	}

	int getKey(){
		return key;
	}

	int getValue(){
		return value;
	}
};

const int TABLE_SIZE = 128;

class HashMap{
private:
	Node ** table;
public:
	HashMap(){
		table = new HashEntry*[TABLE_SIZE]; 
		for(int i=0;i<TABLE_SIZE;i++){
			table[i] = NULL;
		}
	}

	int get(int key){
		int hash = (key % TABLE_SIZE);
		while(table[hash] != NULL && table[hash]->getKey() != key){
			hash  = (hash + 1) % TABLE_SIZE;
		}
		if(table[hash] == NULL){
			return -1;
		}else{
			return table[hash]->getValue();
		}
	}

	void put(int key,int value){
		int hash = (key % TABLE_SIZE);
		while(table[hash] != NULL && table[hash]->getKey() != key)
		{
			hash = (hash + 1)%TABLE_SIZE;
		}
		if(table[hash] != NULL)
				delete table[hash];
		table[hash] = new Node(key,value);
	}

	~HashMap(){
		for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
         delete[] table;
	}
};

