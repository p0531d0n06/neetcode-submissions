class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> o;
        int a;
        int b;
        for(string i : tokens){
            if(i == "+"){
                a = o.top();
                o.pop();
                b = o.top();
                o.pop();
                o.push(a+b);
            }
            else if (i == "-"){
                a = o.top();
                o.pop();
                b = o.top();
                o.pop();
                o.push(b-a);
            }
            else if (i == "*"){
                a = o.top();
                o.pop();
                b = o.top();
                o.pop();
                o.push(a*b);
            }
            else if (i == "/"){
                a = o.top();
                o.pop();
                b = o.top();
                o.pop();
                o.push(b/a);
            }
            else {
                o.push(stoi(i));
            }
        }

        return o.top();
    }
};
