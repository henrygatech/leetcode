
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        char symbol[7]={'I','V','X','L','C','D','M'};
        string roman;
        int scale = 1000; //assume 1 to 3999
        for(int i=6;i>=0;i-=2){
            int digit = num/scale;
            if(digit!=0){
                if(digit<=3)
                    roman.append(digit,symbol[i]);
                else if(digit==4){    
                    roman.append(1,symbol[i]);
                    roman.append(1,symbol[i+1]);
                }
                else if(digit==5)
                    roman.append(1,symbol[i+1]);
                else if(digit<=8){
                    roman.append(1,symbol[i+1]);
                    roman.append(digit-5,symbol[i]);
                }
                else{
                    roman.append(1,symbol[i]);
                    roman.append(1,symbol[i+2]);
                }
            }
            num = num%scale;
            scale/=10;
        }
        return roman;
    }
};
