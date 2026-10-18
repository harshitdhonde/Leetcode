class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                ch.push(c);
            }
            else{
                if(ch.empty())
                    return false;

                char temp = ch.top();
                ch.pop();

                if((c==')'&&temp!='(')||(c=='}'&&temp!='{')||(c==']'&&temp!='['))
                    return false;

            }
        }
        return ch.empty();
        
    }
};