class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int, int> mp;
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {

            int needed = target - numbers[i];

            if (mp.find(needed) != mp.end()) {

                result.push_back(mp[needed] + 1);
                result.push_back(i + 1);
                return result;
            }

            mp[numbers[i]] = i;
        }

        return result;
    }
};


