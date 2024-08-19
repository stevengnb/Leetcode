class Solution {
    public boolean closeStrings(String word1, String word2) {
		Set<Character> s = new HashSet<>();
		Set<Character> s2 = new HashSet<>();
		int array[] = new int[100];
		int array2[] = new int[100];
		
		if(word1.length() != word2.length()) return false;
		
		for(int i = 0; i < word1.length(); i++) {
			int a = (int)(word1.charAt(i)-'A');
			int b = (int)(word2.charAt(i)-'A');
			
			s.add(word1.charAt(i));
			s2.add(word2.charAt(i));
			array[a]++;
			array2[b]++;
		}
		
		if(!s.equals(s2)) return false;
		
		Arrays.sort(array);
		Arrays.sort(array2);
		
		
		
        return Arrays.equals(array, array2);
    }
}