#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
class hash 
{
private:
	static const int tableSize = 100;
	
	struct words {
		string eng;
		string pOfs;
		string german;
		string french;
		string hebrew;
		string latin;
		words* next;

	};

	words* HashTable[tableSize];  //hold the words pointer.

public:
	hash();
	int Hash(std::string key);
	void AddWord(string eng,string pOfs,string german, string french, string hebrew, string latin);
	int NumberOfItemInIndex(int index);
	void printTable();

	void RetriveGertoEngNoun(string);
	
	void RetriveEngtoGerNoun(string);
	/*
	void RetrieveFortoEngAdj(string, string, string, string);
	void RetrieveFortoEngAdv(string, string, string, string);
	void RetrieveFortoEngCnum(string, string, string, string);
	void RetrieveFortoEngAll(string, string, string, string);
	void RetriveEngtoForNoun(string);
	void RetriveEngtoForVerb(string);
	void RetriveEngtoForAdj(string);
	void RetriveEngtoForAdv(string);
	void RetriveEngtoForCnum(string);
	void RetriveEngtoForAll(string);
	*/
	


};