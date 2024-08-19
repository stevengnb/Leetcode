class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
		Set<List<Integer>> set = new HashSet<>();
		
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length-2; i++) {
        	int left = i + 1;
        	int right = nums.length-1;
   
        	while(left < right) {
        		if(nums[i] + nums[left] + nums[right] == 0) {
        			List<Integer> list = Arrays.asList(nums[i], nums[left], nums[right]);
        			set.add(list);
        			left++;
        			right--;
        		} else if(nums[left] + nums[right] < Math.abs(0-nums[i])) {
        			left++;
        		} else if(nums[left] + nums[right] > Math.abs(0-nums[i])) {
        			right--;
        		}
        	}
        }
        
        return new ArrayList<List<Integer>>(set);
    }
}