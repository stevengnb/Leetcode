class Solution {
    public int longestConsecutive(int[] nums) {
        int maxLength = 0;
        int currLength = 0;

		Arrays.sort(nums);
		for(int i = 0; i < nums.length; i++) {
        	if(i != 0) {
        		if(nums[i-1] == nums[i] - 1) currLength++;
        		else if(nums[i-1] == nums[i]) continue;
        		else currLength = 1;
        	} else {
        		currLength = 1;
        	}
        	
        	if(currLength > maxLength) maxLength = currLength;
        }
		
        return maxLength;
    }
}