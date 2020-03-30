#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

inline int getPos(char c){
	if (c == 'a') return 0;
	else if (c == 'c') return 1;
	else if (c == 'g') return 2;
	else return 3;
}

struct TrieNode{
	bool isEndOfWord = false;
	struct TrieNode* children[4];
};

struct TrieNode* getNode(){
	struct TrieNode* node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
	for (int i=0; i<4; i++) node -> children[i] = NULL;
	return node;
}

void insert(struct TrieNode *node, string s){
	struct TrieNode *curr = node;
	int n = s.size();
	for (int i=0; i<n; i++){
		int pos = getPos(s[i]);
		if (curr -> children[pos] == NULL) curr -> children[pos] = getNode();
		curr = curr -> children[pos];
	}
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
	//cout << "result " << r << "\n";
	return r;
}

int main(){
	string s1, s2; bool first = true;
	do{
		getline(cin, s1);
		getline(cin, s2);
		if (first) first = false;
		else cout << "\n";
		//cout << "start\n";
		int n1 = s1.size(), n2 = s2.size();
		vector<string> sol(0, "");
		//cout << "initializeing trie\n";
		struct TrieNode *trie = getNode();
		//cout << "_____________________________________\n";
		for (int i=0; i<n1; i++){
			//cout << "substr: " << s1.substr(i, n1-i) << "\n";
			insert(trie, s1.substr(i, n1-i));
		} 
		for (int i=0; i<n2; i++){
			string t = getLongestMatch(trie, s2.substr(i, n2-i));
			if (sol.size() ==  0 || sol[0].size() < t.size()) sol = vector<string>(1, t);
			else if (sol[0].size() == t.size()) sol.push_back(t);
		}
		sort(sol.begin(), sol.end());
		if (sol.size() == 0 || sol[0].size() == 0) cout << "No common sequence.";
		for (int i=0; i<sol.size(); i++) if (i==0 || sol[i].compare(sol[i-1]) != 0)cout << sol[i] << "\n";
	}while (getline(cin, s1));
}