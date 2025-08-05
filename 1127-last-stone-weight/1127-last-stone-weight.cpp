class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue;

        for(int i : stones) {
            queue.push(i);
        }

        while(queue.size() >= 2) {
            int first = queue.top();
            queue.pop();

            int second = queue.top();
            queue.pop();

            if(first > second) queue.push(first - second);
            else if(first == second && queue.size() == 0) queue.push(0);
        }

        return queue.top();
    }
};