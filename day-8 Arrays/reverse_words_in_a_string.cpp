



class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string ans="";
        int i=0,n=s.size()-1;
        while(i<n && s[i]==' ') i++;
        int j=i;
        while(n>i && s[n]==' ') n--;
        cout<<i<<" "<<n<<endl;
        for(int i=n;i>=j;i--) {
            if(s[i]!=' ') res = s[i]+res ;
            else{
                ans += res + " ";
                res="";
                while(s[i]!='\0' && s[i]==' ') i--;
                i++;
            }
        }

        cout<<ans<<endl;
        ans+=res;
        cout<<ans<<endl;
        return ans;
    }
};
