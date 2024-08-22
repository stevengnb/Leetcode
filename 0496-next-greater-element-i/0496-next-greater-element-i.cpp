class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> map;
        vector<int> vect;

        for(int i = nums2.size()-1; i >= 0; i--) {
            if(stack.empty()) {
                map[nums2[i]] = -1;
                stack.push(nums2[i]);
            } else {
                while(!stack.empty() && stack.top() < nums2[i]) {
                    stack.pop();
                }

                if(stack.empty()) {
                    map[nums2[i]] = -1;
                    stack.push(nums2[i]);
                } else {
                    map[nums2[i]] = stack.top();
                    stack.push(nums2[i]);
                }
            }
        }

        for(int i = 0; i < nums1.size(); i++) {
            vect.push_back(map[nums1[i]]);
        }

        return vect;
    }
};