#include <string>
#ifndef WORDANALYSIS_H
#define WORDANALYSIS_H


using namespace std;

struct word {
	int count;
	string w;
};

class WordAnalysis{
	private:
		int timesDoubled;
		word *words;
		int wordCount;
		int index;
		void doubleArrayAndAdd(string);
		bool checkIfCommonWord(string);
		void sortData();
	public:
		bool readDataFile(char*); //returns an error if file not opened
		int getWordCount();
		int getUniqueWordCount();
		int getArrayDoubling();
		void printCommonWords(int);
		WordAnalysis(int);
		~WordAnalysis();
};

#endif
