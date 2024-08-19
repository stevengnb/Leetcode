class Solution {
    public int longestPalindrome(String s) {
		int array[] = new int[100];
		
		for(Character c : s.toCharArray()) {
			int charInNum = (int)(c);
			
			if(charInNum > 96) {
				array[c - 'A' - 6]++;
			} else {
				array[c - 'A']++;
			}
		}
		
		int sum = 0;
		int odd = 0;
		
		for(int i = 0; i < 52; i++) {
			if(array[i] % 2 == 1) {
				sum += array[i] - 1;
				odd++;
			} else {
				sum += array[i];
			}
		}
		
		return odd > 0 ? sum+1 : sum;
    }
}