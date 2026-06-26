class Solution {
public:
    bool isValid(string s) {
        stack<char> store;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '['){
                store.push(s[i]);
            } else {
                if (store.empty()) return false;
                switch(s[i]){
                    case ')':
                        if(store.top() == '('){
                            store.pop();
                        } else {
                            return false;
                        }
                        break;
                    case '}':
                        if(store.top() == '{'){
                            store.pop();
                        } else {
                            return false;
                        }
                        break;
                    case ']':
                        if(store.top() == '['){
                            store.pop();
                        } else {
                            return false;
                        }
                        break;
                }
            }
        }

        return store.empty();
    }
};
