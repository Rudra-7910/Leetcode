class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n+1,0);

        for(int i=0 ; i<shifts.size();i++)
        {
            int left= shifts[i][0];
            int right = shifts[i][1];
            int direction = shifts[i][2];

            if(direction==1)
            {
                diff[left]+=1;
                diff[right+1]+=-1;
            }
            else
            {
                diff[left]-=1;
                diff[right+1]+=1;
            }
        }

        int sum =0 ;

        for(int i=0 ; i<n;i++)
        {
            sum+=diff[i];
            int position = s[i]-'a';

            int newPosition = (position+sum)%26;

            if(newPosition<0)
            {
                newPosition+=26;
            }

            s[i]='a'+newPosition;
        }
        return s;
    }
};