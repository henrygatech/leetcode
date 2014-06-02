
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows==1) return s;
        string result;
        if(s.size()==0) return result;
        
        for(int i=0;i<nRows;i++){
            for(int index=i; index<s.size(); index+=(2*nRows-2)){
                result.append(1,s[index]);
                if(i==0 || i==nRows-1)
                    continue;
                if(index+2*(nRows-i-1)<s.size())
                    result.append(1,s[index+2*(nRows-i-1)]);
            }
        }
        
        return result;
    }
};
