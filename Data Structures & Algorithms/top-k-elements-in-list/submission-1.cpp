class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> values;
        vector<int> freqs;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;

            int freq = 1;

            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    freq++;
                    vis[j] = true;
                }
            }

            values.push_back(nums[i]);
            freqs.push_back(freq);
        }

        vector<int> ans;

        for(int t = 0; t < k; t++) {
            int maxFreq = -1;
            int idx = -1;

            for(int i = 0; i < freqs.size(); i++) {
                if(freqs[i] > maxFreq) {
                    maxFreq = freqs[i];
                    idx = i;
                }
            }

            ans.push_back(values[idx]);
            freqs[idx] = -1; // mark as used
        }

        return ans;
    }
};