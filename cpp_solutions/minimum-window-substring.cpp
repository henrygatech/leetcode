class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size()<T.size()) return "";
        int expect[256]={0};
        int appear[256]={0};
        
        for(int i=0;i<T.size();i++)
            expect[T[i]]++;
        
        int len=INT_MAX, minstart=0, start=0, appeared=0;
        for(int end=0;end<S.size();end++){
            if(expect[S[end]]>0){
                appear[S[end]]++;
                if(appear[S[end]]<=expect[S[end]])
                    appeared++;
            }
            if(appeared==T.size()){
                while(appear[S[start]]>expect[S[start]] || expect[S[start]]==0){
                    appear[S[start]]--;
                    start++;
                }
                if(len>end-start+1){
                    minstart=start;
                    len=end-start+1;
                }
            }
        }
        if(len==INT_MAX) return "";
        else return S.substr(minstart,len);
    }
};
