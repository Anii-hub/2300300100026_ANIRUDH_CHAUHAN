class Solution {
public:
    string frequencySort(string s) {
        
      
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

   
        priority_queue<pair<int, char>> pq;
        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

      
        string result = "";
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int count = top.first;
            char ch = top.second;

            result += string(count, ch); 
        }

        return result;
    }
};