// bool cmp(const& char c1, const& char c2){
//     if(vowel){

//     }
// }
class Solution {
public:
    string vowels = "aeiouAEIOU";
    string sortVowels(string s) {
        // sort(begin(s),end(s),cmp);

        int length = s.size();
        string myString(length, ' ');
        string vwls;
        int k = 0;

        for(int i=0;i<length;i++){
            if(vowels.find(s[i]) == string::npos){
                myString[i] = s[i];
            }else vwls += s[i];
        }

        sort(vwls.begin(),vwls.end());
        for(int i=0;i<length;i++){
            if(myString[i]==' '){
                myString[i] = vwls[k++];
            }
        }

        return myString;




        // cout<<vow<<" "<<con;
        return myString;
    }
};