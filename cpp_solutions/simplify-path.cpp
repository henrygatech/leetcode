class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i=0;
        while(i<path.size()){
            while(i<path.size() && path[i]=='/') i++;
            if(i==path.size()) break;
            int start=i;
            while(i<path.size() && path[i]!='/') i++;
            string dir=path.substr(start,i-start);
            if(dir==".."){
                if(!s.empty()) s.pop();
            }
            else if(dir!=".") s.push(dir);
        }
        if(s.empty()) return "/";
        string ret;
        while(!s.empty()){
            ret="/"+s.top()+ret;
            s.pop();
        }
        return ret;
    }
};
