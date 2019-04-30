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

const int NPREF = 2;
const char NONWORD[] = "\n";
const int MAXGEN = 10000; // maximum words generated

/// Functions
void build(Prefix&, istream&);
void generate(int nwords);
void add(Prefix&, const string&);

// build: read input words, build state table
void build(Prefix& prefix, istream& in, char* sInp) {
	std:ofstream outfile("C:\\Users\\Diana Contreras\\Desktop\\input.txt");
	outfile << sInp;
	outfile.close();
	std::ifstream infile("C:\\Users\\Diana Contreras\\Desktop\\input.txt");
	string buf, word;

	while (!infile.eof()) {
		cout << word << endl;
		infile >> word;
		add(prefix, word);
	}
	infile.close();
}

// add: add word to suffix deque, update prefix
void add(Prefix& prefix, const string& s)
{
	if (prefix.size() == NPREF) {
		statetab[prefix].push_back(s);
		prefix.pop_front();
	}
	prefix.push_back(s);
}

// generate: produce output, one word per line
void generate(int nwords) {
	std::ofstream outfile("C:\\Users\\Diana Contreras\\Desktop\\MarkovChain.txt");
	
	Prefix prefix;
	int i;
	for (i = 0; i < NPREF; i++)
		add(prefix, NONWORD);
	for (i = 0; i < nwords; i++) {
		vector<string>& suf = statetab[prefix];
		const string& w = suf[rand() % suf.size()];
		if (w == NONWORD)
			break;
		cout << w << "\n";
		outfile << w << "\n" << std::endl;
		prefix.pop_front(); // advance
		prefix.push_back(w);
	}
	outfile.close();
}

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
