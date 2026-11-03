class Solution {
public:
    string multiply(string num1, string num2) {
        int n= num1.size();
        int m= num2.size();
        vector<int> result(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j= m-1;j>=0;j--)
            {
                int a= num1[i]-'0';
                int b= num2[j]-'0';
                int mul = a*b;

                int sum = mul + result.at(i+j+1);
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

                string answer = "";
        for (int i = 0; i < n + m; i++) {

            if (answer == "" && result[i] == 0) {
                continue;
            }

            answer += (result[i] + '0');
        }

        if (answer == "") return "0";

        return answer;

    }
};