class Solution {
    public int[] productExceptSelf(int[] nums) {
	     int zero = 0;
	     int sum = 1;
	     int sums[] = new int[nums.length];
		 
	     for(int i = 0; i < nums.length; i++) {
	    	 if(nums[i] != 0) sum *= nums[i];
	    	 else zero++;
	     }
	     
//	     System.out.println("sum = " + sum);
//	     System.out.println("zero  = " + zero);
	     
	     if(zero > 1) {
	    	 return new int[nums.length];
	     } else if(zero == 1){
	    	 for(int i = 0; i < nums.length; i++) {
		    	 if(nums[i] == 0) sums[i] = sum;
		    	 else sums[i] = 0;
		     }
	     } else {
	    	 for(int i = 0; i < nums.length; i++) sums[i] = sum / nums[i];
	     }
	     
//	     for(int i = 0; i < sums.length; i++) {
//	    	 System.out.println(sums[i]);
//	     }
	     
		 return sums;
	 }
}