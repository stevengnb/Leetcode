class Solution {
    public int removeElement(int[] nums, int val) {
		int k = 0;
        int left = 0;
        int right = nums.length-1;
        
        while(left <= right) {
        	if(left == right && nums[left] == val) {
        		k++;
        		break;
        	}
        
        	if(nums[right] == val) {
        		k++;
        		right--;
        	} else if(nums[left] == val) {
        		int a = nums[left];
        		nums[left] = nums[right];
        		nums[right] = a;
        		
        		left++;
        		right--;
        		k++;
        	} else {
        		left++;
        	}
        }

		return nums.length-k;
    }
}