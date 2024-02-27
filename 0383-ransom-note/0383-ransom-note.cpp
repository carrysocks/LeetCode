class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> maga;
        unordered_map<char, int> note;

        for(int i=0;i<magazine.size();i++) maga[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++) if(maga[ransomNote[i]]-- < 1) return false;
        return true;
    }
};