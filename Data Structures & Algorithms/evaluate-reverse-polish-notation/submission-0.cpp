class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n=tokens.size();
        for (int i=0;i<n;i++){
            if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                s.push(stoi(tokens[i]));
            }else{
                int n2=s.top();
                s.pop();
                int n1=s.top();
                s.pop();
                if (tokens[i]=="+"){
                    s.push(int(n2)+int(n1));
                }if(tokens[i]=="-"){
                    s.push(int(n1)-int(n2));
                }if(tokens[i]=="*"){
                    s.push(int(n2)*int(n1));
                }if(tokens[i]=="/"){
                    s.push(int(n1)/int(n2));
                }
            }
        }
        return s.top();
    }
};
