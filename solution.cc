// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> myQue;
        unordered_set<string> inQue;
        myQue.push(start);
        inQue.insert(start);
        int lvl1 = 1, lvl2 = 0;
        int minDist = 0;
        while(!myQue.empty()) {
            ++minDist;
            while(lvl1) {
                string curWord = myQue.front();
                myQue.pop();
                --lvl1;
                for(int i = 0; i < curWord.size(); ++i) {
                    for(char c = 'a'; c <= 'z'; ++c) {
                        string newWord = curWord;
                        newWord[i] = c;
                        if(newWord == end) {
                            return minDist+1;
                        }
                        if(newWord != curWord && dict.count(newWord) && !inQue.count(newWord)) {
                            myQue.push(newWord);
                            inQue.insert(newWord);
                            ++lvl2;
                        }
                    }
                }
            }
            lvl1 = lvl2;
            lvl2 = 0;
        }
        return 0;
    }
};
