
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2, 0);

        int counter = 0;
        int score = 0;

        for(int i = 0; i < events.size(); i++)
        {
            if(events[i] == "W")
            {
                counter++;

                if(counter == 10)
                {
                    break;
                }
            }
            else if(events[i] == "WD" || events[i] == "NB")
            {
                score++;
            }
            else
            {
                score += stoi(events[i]);
            }
        }

        ans[0] = score;
        ans[1] = counter;

        return ans;
    }
};
