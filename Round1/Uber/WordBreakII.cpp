/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

void helper(string &s, int start, unordered_set<string> &dict, string &curr, vector<string> &res) {
    if (start == s.size()) {
        res.push_back(curr.substr(0, curr.size() - 1));
        return;
    }

    for (int i = start; i < s.size(); ++i) {
        string tmp = s.substr(start, i - start + 1);
        if (dict.count(tmp)) {
            curr += tmp + " ";
            helper(s, i + 1, dict, curr, res);
            curr = curr.substr(0, start);
        }
    }
}

vector<string> WordBreak(string s, unordered_set<string> &dict) {
    if (s.empty()) return {};
    vector<string> res;
    string curr;
    helper(s, 0, dict, curr, res);
    return res;
}

int main() {
    unordered_set<string> dict {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = WordBreak("catsanddog", dict);
    for (const auto &sentence : res) {
        std::cout << sentence << std::endl;
    }
}


/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void helper(unordered_set<string> &dict, string &s,
			int start, string &curr, vector<string> &res) {
	if (start == s.size()) {
		res.push_back(curr.substr(0, curr.size() - 1));
		return;
	}

	for (int i = start; i < s.size(); ++i) {
		string tmp = s.substr(start, i - start + 1);
		if (dict.count(tmp)) {
			curr += tmp + " ";
			helper(dict, s, i + 1, curr, res);
			curr = curr.substr(0, curr.size() -  (i - start + 2));
		}
	}
}

vector<string> WordBreak(unordered_set<string> &dict, string s) {
	vector<string> res;
	string curr;
	helper(dict, s, 0, curr, res);
	return res;
}

int main() {
	unordered_set<string> dict {"cat", "cats", "and", "sand", "dog"};
	auto res = WordBreak(dict, "catsanddog");
	for (const auto &s : res) {
		cout << s << endl;
	}
}
