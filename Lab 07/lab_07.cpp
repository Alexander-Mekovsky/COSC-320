#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "d_hash.h"
#include "d_hashf.h"

using namespace std;

//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}

int main()
{
    ifstream file;
    file.open("dict.dat");
    if(!file.is_open())
    {
        cout << "File Does Not Exist" << endl;
        exit(EXIT_FAILURE);
    }
    string txt, word;
    cout << "Run:" << endl << endl;
    cout << "Enter the Document Name: ";
    cin >> txt;
    ifstream textFile;
    textFile.open(txt);
    if(!textFile.is_open())
    {
        cout << "File Does Not Exist" << endl;
        exit(EXIT_FAILURE);
    }
    myhash <string, hFstring> hashTable(1373);
    while(!file.eof())
    {
        getWord(file, word);
        hashTable.insert(word);
    }
    cout << "Misspelled Words: " << endl;
    while(!textFile.eof())
    {
        getWord(textFile, word);
        if(hashTable.find(word) == hashTable.end())
            cout << word << endl;
    }
    file.close();
    return 0;
}

