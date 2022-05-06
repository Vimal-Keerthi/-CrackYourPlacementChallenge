/*
Group anagrams
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        auto it = mp.begin();
        while(it!=mp.end()){
            auto it1 = it->second.begin();
            vector<string> vec;
            while(it1!=it->second.end()){
                vec.push_back(strs[*it1]);
                ++it1;
            }
            v.push_back(vec);
            ++it;
        }
        //sort(v.begin(),v.end());
        return v;
    }
};
