class Solution {
#define ALL(x) x.begin(),x.end()
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int,int> > pp;
        vector<int> sorted;
        vector<int> reverse;
        int n = numbers.size();
        for(int i=0; i<n; i++)
            pp.push_back(make_pair(numbers[i], i));
        sort(ALL(pp));
        for(int i=0; i<n; i++)
            reverse[i] = pp[i].second, sorted[i] = pp[i].first;
        
        vector<int> index;
 /*       for(int i=0; i<n; i++) {
            int y = target - sorted[i];
            if (y < sorted[i]) {
                break;
            }
            int idx = upper_bound(ALL(sorted), y) - sorted.begin() - 1;
            if (idx>=0 && idx<n && i != idx && sorted[idx] == y) {
                index.push_back(reverse[idx]+1);
                index.push_back(reverse[i]+1);
                break;
            }
        }*/
        if (!index.size())
            index.push_back(0) , index.push_back(1);
        sort(ALL(index));
        return index;
    }
};