class Solution {
public:
    string reverseParentheses(string s) {  
        int open=0;
        stack<char>st;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                st.push(s[i]);
            }
            else if(s[i]==')'){
                open--;
                string word="";
                while(st.top()!='('){
                    word+=st.top();
                    st.pop();
                }
                st.pop();

                if(open!=0 ){
                    for(int k=0;k<word.length();k++){
                        st.push(word[k]);
                    }
                }
                else{
                    str+=word;
                    while(!st.empty()){
                        st.pop();
                    }
                }

            }
            else if(st.empty() && isalpha(s[i])){
                str+=s[i];
            }
        
            else {
                st.push(s[i]);
            }
        }
            return str;
    }
};