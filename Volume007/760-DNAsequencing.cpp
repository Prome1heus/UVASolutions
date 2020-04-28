#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

/*
 * The problem statement can be found here: https://onlinejudge.org/external/7/760.pdf
 * I documented this solution to use it as a sample of my work
 * This problem can be solved easily with a suffix trie
 */

inline int getPos(char c){
	//map dna base to index
	if (c == 'a') return 0;
	else if (c == 'c') return 1;
	else if (c == 'g') return 2;
	else return 3;
}

struct TrieNode{
	/*
	 * Trie data structure that stores 
	 */
	bool isEndOfWord = false;
	struct TrieNode* children[4];
};

struct TrieNode* getNode(){
	/*
	 * creates a new empty node
	 */

	struct TrieNode* node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
	for (int i=0; i<4; i++) node -> children[i] = NULL;
	return node;
}

void insert(struct TrieNode *node, string s){
	/*
	 * insert a string into the trie
	 */	

	struct TrieNode *curr = node;
	int n = s.size();
	for (int i=0; i<n; i++){
		//insert next letter
		int pos = getPos(s[i]);

		//creates next node in path if it doesn't exist already
		if (curr -> children[pos] == NULL) curr -> children[pos] = getNode();
		curr = curr -> children[pos];
	}
	//signal that a word ends here
	curr -> isEndOfWord = true;
}

string getLongestMatch(struct TrieNode *node, string s){
	string r = "";
	struct TrieNode *curr = node;
	int i = 0, n = s.size();
	while (i<n && curr -> children[getPos(s[i])] != NULL){
		curr = curr -> children[getPos(s[i])];
		r += s[i++];
	}
	return r;
}

/*
 * The input of this problems consists of multiple cases
 * For each case, 2 dna sequences are given
 * The task is to calculate all common sequences of maximal length
 *	
 * How I solved it:
 * 1. Store all suffixes of the first dna sequence in a trie 
 * 2. Iterate through all suffices of the second dna sequence and calculate the longest common sequence
 * 		while keeping track of all currently longest sequences
 */

int main(){
	string s1, s2; bool first = true;
	do{
		//read input
		getline(cin, s1);
		getline(cin, s2);
		if (first) first = false;
		else cout << "\n";
		
		//setup
		int n1 = s1.size(), n2 = s2.size();
		vector<string> sol(0, "");
		//create a new empty trie
		struct TrieNode *trie = getNode();
		
		//insert all suffixes of the first string into the trie
		for (int i=0; i<n1; i++){
			insert(trie, s1.substr(i, n1-i));
		} 

		//for each suffix of s2 compute the length of the part contained in s1
		for (int i=0; i<n2; i++){
			string t = getLongestMatch(trie, s2.substr(i, n2-i));
			if (sol.size() ==  0 || sol[0].size() < t.size()) sol = vector<string>(1, t);
			else if (sol[0].size() == t.size()) sol.push_back(t);
		}

		//sort results alphabetically
		sort(sol.begin(), sol.end());

		//format output
		if (sol.size() == 0 || sol[0].size() == 0) cout << "No common sequence.";
		for (int i=0; i<sol.size(); i++) if (i==0 || sol[i].compare(sol[i-1]) != 0) cout << sol[i] << "\n";

	}while (getline(cin, s1)); //checks for eof and clears empty line in input
}