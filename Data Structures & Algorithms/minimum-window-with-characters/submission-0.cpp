class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        map<char, int> store;
        for(int i = 0; i < t.size(); i++){
            if(store.contains(t[i])){
                store[t[i]]++;
            } else {
                store.insert({t[i],1});
            }
        }


        int l = 0;
        int required = store.size();
        int minPos = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            if(store.contains(s[r])){
                store[s[r]]--;
                if(store[s[r]]==0){
                    required--;
                }
            }

            while(required == 0){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    minPos = l;
                }

                if (store.contains(s[l])) {
                    store[s[l]]++;
                    if (store[s[l]] > 0) {
                        required++;
                    }
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "": s.substr(minPos, minLen);

    }
};
