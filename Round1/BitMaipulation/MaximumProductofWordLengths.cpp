/*
 * Given a string array words, find the maximum value of 
 * length(word[i]) * length(word[j]) 
 * where the two words do not share common letters. 
 * You may assume that each word will contain only lower case letters. 
 * If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
 *
 */

// http://www.cnblogs.com/grandyang/p/5090058.html

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c: words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if (!(mask[i] & mask[j]) {
                    res = max(res, int(words[i].size() * words[j].size());
                }
            }
        }

        return res;
    }
};
