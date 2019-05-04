/* C++ program to apply MArkov-Chain algorithm based on "The Programming Practice" book,
the program using map, vector and deque data structures to maintain the input and generate the output*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <istream>
#include <fstream>

using namespace std;

typedef deque<string> Prefix;
map<Prefix, vector<string> > statetab;

const int NPREF = 2; // number of  prefix words
const char NONWORD[] = "\n";
const int MAXGEN = 10000; // maximum words generated

// Function prototypes
void build(Prefix&, istream&);
void generate(int nwords);
void add(Prefix&, const string&);

// build: read input words, build state table
void build(Prefix& prefix, istream& in, char* sInp) {
	// open the file input.txt, if is not exists it will be created, 
	// and it will be filled with the char array passed in the function
std:ofstream outfile("C:\\Users\\Diana Contreras\\Desktop\\input.txt");
	outfile << sInp;
	outfile.close();
	// open the same file to read it until it finished
	std::ifstream infile("C:\\Users\\Diana Contreras\\Desktop\\input.txt");
	string buf, word;

	while (!infile.eof()) {
		cout << word << endl;
		infile >> word;
		add(prefix, word);
	}
	infile.close();
}

/* add: add word to suffix deque, update prefix */
void add(Prefix& prefix, const string& s)
{
	if (prefix.size() == NPREF) {
		statetab[prefix].push_back(s);
		prefix.pop_front();
	}
	prefix.push_back(s);
}

/* generate: produce output, one word per line within the file */
void generate(int nwords) {
	// prepare a textfile called MarkovChain
	std::ofstream outfile("C:\\Users\\Diana Contreras\\Desktop\\MarkovChain.txt");
	Prefix prefix;

	for (int i = 0; i < NPREF; i++)
		add(prefix, NONWORD);
	for (int i = 0; i < nwords; i++) {
		vector<string>& suf = statetab[prefix];
		const string& w = suf[rand() % suf.size()];
		if (w == NONWORD)
			break;
		cout << w << "\n";
		// write the words in the file
		outfile << w << "\n" << std::endl;
		prefix.pop_front(); // advance
		prefix.push_back(w);
	}
	outfile.close();
}

/* This acts like the main function, as DLL does not have to have a main function,
 I decided to name it run.
 The function initializes the prefix, reads the input as a char array, adds a tail,
 and generates the output in a file.
 */
char run(char* sInp) {
	int nwords = MAXGEN;
	Prefix prefix; // current input prefix
	for (int i = 0; i < NPREF; i++)
		add(prefix, NONWORD);
	build(prefix, cin, sInp);
	add(prefix, NONWORD);
	generate(nwords);
	return 'Y';
}

char MathFuncs::run(char* sInp) {
	int nwords = MAXGEN;
	Prefix prefix; // current input prefix
	for (int i = 0; i < NPREF; i++)
		add(prefix, NONWORD);
	build(prefix, cin, sInp);
	add(prefix, NONWORD);
	generate(nwords);
	return 'Y';
}
