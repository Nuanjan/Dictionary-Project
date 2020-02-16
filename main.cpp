#include <cstdlib>
#include <iostream>
#include <string>
#include<fstream>
#include "hash.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

string eng,pOfs,german,french,latin,hebrew;
string result = "";

int Menu();

int c = 0;

int main(int argc, char** argv) 
{
		hash Hashy;
		ofstream dic("Dictionary.txt");
		
			int option = Menu();
			do
			{
				
				switch (option)
				{
					dic.open("dictionary.txt");
				case 1: 
				
						cout << "Create the English word now" << endl;
						cin >> eng;
						cout << "part of speed is " << endl;
						cin >> pOfs;
						cout << "Word in German language with gender (m) for male (f) for female and (u) for uni-sex" << endl;
						cin >> german;
						cout << "Word in French language with gender (m) for male or (f) for female" << endl;
						cin >> french;
						cout << " word in Hebrew language" << endl;
						cin >> hebrew;
						cout << "Word in latin language" << endl;
						cin >> latin;
						cout << "Add more word? Yes? hit 1 NO? hit 0" << endl;
						cin>> c;
						
						Hashy.AddWord(eng, pOfs, german, french, hebrew, latin);
						Hashy.printTable();
					if (!dic.is_open())
					{
						cout << "error opening file" << endl;
					}
					else
					{
						
						
						dic << eng << endl;
						dic << pOfs << endl;
						dic << german << endl;
						dic << french << endl;
						dic << hebrew << endl;
						dic << latin <<"|" <<endl;
						cout << "saved word!" << endl;
						
					}
					if (c == 0) {
						option = Menu();

					}
					else {
						cout << "Invalid number" << endl;
					}
					break;
				case 2:
					while (result != "exit")
					{
						cout << "search the word or type exist to exist the program" << endl;
						cin >> result;
						if (result != "exist")
						{
							Hashy.RetriveGertoEngNoun(result);
						}
					}
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					while (result != "exit")
					{
						cout << "search the word or type exist to exist the program" << endl;
						cin >> result;
						if (result != "exist")
						{
							Hashy.RetriveEngtoGerNoun(result);
						}
					}
					break;
				case10:
					break;
				case 11:
					break;
				case 12:
					break;
				case 13:
					break;
				case 14:
					break;
				case 16:
					break;
				case 17:
					break;
				default :
					cout << "Invalit choice" << endl;
				}
			} while (option != 17);
			dic.close();
	
	return 0;

}

int Menu()
{
	int choice;
	cout << "                     _____________________________________________________________________" << endl;
	cout << "                    |  1--Creat rhe word list                                             | " << endl;
	cout << "                    |  2--German(French,Latin,Hebrew) to English nouns                    |" << endl;
	cout << "                    |  3--German(French,Latin,Hebrew) to English verbs                    |" << endl;
	cout << "                    |  4--German(French,Latin,Hebrew) to English prepositions             |" << endl;
	cout << "                    |  5--German(French,Latin,Hebrew) to English adjectives               |" << endl;
	cout << "                    |  6--German(French,Latin,Hebrew) to English adverbs                  |" << endl;
	cout << "                    |  7--German(French,Latin,Hebrew) to English cardinal numbers         |" << endl;
	cout << "                    |  8--German(French,Latin,Hebrew) to English all                      |" << endl;
	cout << "                    |  9--English to (German,French,Latin,Hebrew) nouns                   |" << endl;
	cout << "                    |  10--English to (German,French,Latin,Hebrew) verbs                  |" << endl;
	cout << "                    |  11--English to (German,French,Latin,Hebrew) prepositions           |" << endl;
	cout << "                    |  12--English to (German,French,Latin,Hebrew) adjectives             |" << endl;
	cout << "                    |  13--English to (German,French,Latin,Hebrew) adverbs                |" << endl;
	cout << "                    |  14--English to (German,French,Latin,Hebrew) cardinal numbers       |" << endl;
	cout << "                    |  15--English to (German,French,Latin,Hebrew) all                    |" << endl;
	cout << "                    |  Search for a word in one language and return other                 |" << endl;
	cout << "                    |  Quit                                                               |" << endl;
	cout << "                     ______________________________________________________________________" << endl;
	cout << endl;
	cout << "please chose the choice from menu" << endl;
	cin >> choice;
	return choice;
}