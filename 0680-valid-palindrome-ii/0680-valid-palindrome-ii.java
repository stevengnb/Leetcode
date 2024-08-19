class Solution {
    public boolean validPalindrome(String s) {
		char array[] = s.toCharArray();
        int left = 0;
        int right = s.length()-1;
        int storeLeft = 0;
        int storeRight = 0;
        boolean flag = false;
        
        	while(left < right) {
//        		System.out.println("kiri = " + array[left]);
//        		System.out.println("kanan = " + array[right]);
        		if(array[left] == array[right]) {
        			left++;
        			right--;
        		} else {
        			if(!flag) {
        				storeLeft = left;
            			storeRight = right;
        			}
        			
					if(array[left] == array[right-1] && !flag) {
						flag = true;
						right--;
					} else if(array[left+1] == array[right] && !flag) {
						flag = true;
						left++;
					} else {
//						System.out.printf("coba ulang %d dan %d dari cek kiri dulu\n", storeLeft, storeRight);
						if(storeLeft == storeRight) return false;
						flag = false;
						
						while(storeLeft < storeRight) {
//			        		System.out.println("kiri = " + array[storeLeft]);
//			        		System.out.println("kanan = " + array[storeRight]);
							if(array[storeLeft] == array[storeRight]) {
			        			storeLeft++;
			        			storeRight--;
			        		} else {
			        			if(array[storeLeft+1] == array[storeRight] && !flag) {
									flag = true;
									storeLeft++;
								} else if(array[storeLeft] == array[storeRight-1] && !flag) {
									flag = true;
									storeRight--;
								} else {
									return false;
								}
			        		}
						}
						break;
					}  

        		}
        	} 
        
        return true;
    }
}