class Solution {
    public void sortColors(int[] nums) {
        int array[] = new int[3];
        int index = 0;
        
        for(int i = 0; i < nums.length; i++) {
        	array[nums[i]]++;
        }
        
        for(int i = 0; i < array.length; i++) {
        	for(int j = 0; j < array[i]; j++) {
        		nums[index++] = i;
        	}
        }
    }
}