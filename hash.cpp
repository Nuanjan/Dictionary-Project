#include <cstdlib>
#include <iostream>
#include<fstream>
#include <string>
#include "hash.h"

using std::cout;
using std::endl;


hash::hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new words;  //point to the beginning of table
		HashTable[i]->eng = " ";
		HashTable[i]->pOfs = " ";
		HashTable[i]->german = " ";
		HashTable[i]->french = " ";
		HashTable[i]->hebrew = " ";
		HashTable[i]->latin = " ";
		HashTable[i]->next = NULL;
	}
}
void hash::AddWord(string eng, string pOfs, string german, string french, string hebrew, string latin)
{
	int index = Hash(eng);   //hold the location in HashTable where we want to store.
	if (HashTable[index]->eng == " ") //check if current index is empty
	{
		HashTable[index]->eng = eng;
		HashTable[index]->pOfs = pOfs;
		HashTable[index]->german = german;
		HashTable[index]->french = french;
		HashTable[index]->hebrew = hebrew;
		HashTable[index]->latin = latin;
	}
	else
	{
		words* Ptr = HashTable[index]; //poin to the current index
		words* n = new words; 
		n->eng = eng;
		n->pOfs = pOfs;
		n->german = german;
		n->french = french;
		n->hebrew = hebrew;
		n->latin = latin;
		n->next = NULL;

		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}

		Ptr->next = n;
	}


}

int hash::NumberOfItemInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->eng == " ")
	{
		return count;
	}
	else
	{
		count++;
		words* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

int hash::Hash(std::string key)
{
	int hash = 0;
	int index;
	
	index = key.length();

	for (int i = 0; i < index; i++) {
		key[index] = key[i];
		cout << "key is = " << key[index] << endl;
	}
	


	return index;
}

void hash::printTable()
{
	int number;
	
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemInIndex(i);
	
		cout << "--------------------------\n";
		cout << "index = " << i <<"\t";
		cout << HashTable[i]->eng<<"\t";
		cout << HashTable[i]->pOfs<<"\t";
		cout << HashTable[i]->french<<"\t";
		cout << HashTable[i]->hebrew<<"\t";
		cout << HashTable[i]->latin<<"\t";
		cout << "number of words = " << number << endl;
		cout << "--------------------------\n";
	}
	
}
void hash::RetriveGertoEngNoun(string german) {
	int index = Hash(german);
	bool isFound = false;
	string eng;
	words* Ptr = HashTable[index]; //find with the key
	while (Ptr != NULL) //pointing to some word
	{
		if (Ptr->german == german )
		{
			isFound = true;
			eng = Ptr->eng;
		}
		else if (Ptr->french == german) {
			isFound = true;
			eng = Ptr->eng;
		}
		else if (Ptr->hebrew== german) {
			isFound = true;
			eng = Ptr->eng;
		}
		else if (Ptr->latin == german) {
			isFound = true;
			eng = Ptr->eng;
		}
		Ptr = Ptr->next; //moving pointer to the next until hit the NULL value
	}
	if (isFound == true) { //found word
		cout <<german<< " in English is " << eng << endl;
	}
	else
	{
		cout << german<<" is not found! " << endl;
		cout << "index = " << index << endl;
		cout << "isfound = " << isFound << endl;
	}
}

void hash::RetriveEngtoGerNoun(string eng) {
	int index = Hash(eng);
	bool isFound = false;
	string german,french,hebrew,latin;
	words* Ptr = HashTable[index]; //find with the key
	while (Ptr != NULL) //pointing to some word
	{
		if (Ptr->eng == eng)
		{
			isFound = true;
			german = Ptr->german;
			french = Ptr->french;
			hebrew = Ptr->hebrew;
			latin = Ptr->latin;
		}
		else if (Ptr->french == german) {
			isFound = true;
			german = Ptr->german;
			french = Ptr->french;
			hebrew = Ptr->hebrew;
			latin = Ptr->latin;
		}
		else if (Ptr->hebrew == german) {
			isFound = true;
			german = Ptr->german;
			french = Ptr->french;
			hebrew = Ptr->hebrew;
			latin = Ptr->latin;
		}
		else if (Ptr->latin == german) {
			isFound = true;
			german = Ptr->german;
			french = Ptr->french;
			hebrew = Ptr->hebrew;
			latin = Ptr->latin;
		}
		Ptr = Ptr->next; //moving pointer to the next until hit the NULL value
	}
	if (isFound == true) { //found word
		cout << eng << " in german french hebrew latin are "
			<<"\t"<< german 
			<<"\t"<<french
			<<"\t"<<hebrew
			<<"\t"<<latin
			<< endl;
	}
	else
	{
		cout << eng << " is not found! " << endl;
		cout << "index = " << index << endl;
		cout << "isfound = " << isFound << endl;
	}
}
