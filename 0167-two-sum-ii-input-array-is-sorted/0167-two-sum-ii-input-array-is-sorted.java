class Solution {
   public int[] twoSum(int[] numbers, int target) {
		int back[] = new int[2];
		int left = 0;
		int right = numbers.length - 1;
		
		while(left <= right) {
			if(numbers[left] + numbers[right] == target) break;
			else if (numbers[left] + numbers[right] < target) left++;
			else if(numbers[left] + numbers[right] > target) right--;
		}
		
		back[0] = left+1;
		back[1] = right+1;
		
		return back;
    }
}