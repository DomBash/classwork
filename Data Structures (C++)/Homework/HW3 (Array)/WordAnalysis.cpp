#include<iostream>
#include "WordAnalysis.h"

WordAnalysis::WordAnalysis(int wa)
{

}
bool WordAnalysis::readDataFile(filename)
{
	string line;
	
	string commonWords[50] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she", "or", "an", "will", "my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get", "which", "go", "me"};
	
	int arraySpace = 100;
	int arrayDouble = 0;
	int unique = 0;
	int uncommon = 0;
	int count = 0;
	string check;
	bool notCommon;
	words *wordArray = new words[arraySpace]; //Create struct array using int created in main
	
	ifstream filename;
	filename.open(argv[1]);//Open file
	
	if (filename.is_open())
	{
		while (filename>>check) //read each line
		{
			int i,j;
			notCommon = true;
			for(i = 0; i < 50; i++)//loop through common words
			{	
				if(check.compare(commonWords[i]) == 0) //Check if word is common
				{
					notCommon = false;
				}
				
			}
			if(notCommon == true)//if the word is not a common word
			{
				uncommon++;
				count++;
				bool iu;
				iu = true;
				for(i = 0; i < unique; i++)
				{
					if(check.compare(wordArray[i].word) == 0)//if word is already in array increase count
					{
						wordArray[i].count++;
						iu = false;
					}
				}
				if(iu == true)//if word is not already in array add it and increase count
				{
					wordArray[unique].word = check;
					wordArray[unique].count++;
					unique++;
				}
			}
			if(unique == arraySpace)//check if number of spaces used in the array is equal to total number of spaces
			{			
				arraySpace = arraySpace*2; //double array size
				words *wordArray2 = new words[arraySpace];//create temp array
				for(j = 0; j < arraySpace/2; j++) //loop through array and put elements in temp
				{
					if(j <= arraySpace)
					{
						wordArray2[j].word = wordArray[j].word;
						wordArray2[j].count = wordArray[j].count;
					}
					
				}
				delete[]wordArray;//delete old array
				wordArray = wordArray2;//set fresh array equal to temp array
				arrayDouble++;	
				
			}
		}
		filename.close();//close file
	}
	sort(wordArray, wordArray + unique, wordscompare);//sort array
	int top = atoi(argv[2]); //get number of results requested from CLA
	for(int j = 0; j < top; j++)//loop through sorted array
	{
		cout<<wordArray[j].count<<" - "<<wordArray[j].word<<endl;
	}
	cout<<"#"<<endl;
	cout<<"Array doubled: "<<arrayDouble<<endl;
	cout<<"#"<<endl;
	cout<<"Unique non-common words: "<<unique<<endl;
	cout<<"#"<<endl;
	cout<<"Total non-common words: "<<count<<endl;
	
	

}

void WordAnalysis::getWordCount()
{
	
}

void WordAnalysis::getUniqueWordCount()
{
	
}

void WordAnalysis::getArrayDoubling()
{
	
}

void WordAnalysis::printCommonWords()
{
	
}
