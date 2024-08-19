class Solution {
    public String frequencySort(String s) {
		List<Character>[] aol = new List[s.length() + 1];
		StringBuilder sb = new StringBuilder();
		int array[] = new int[100];
		
		for(Character c : s.toCharArray()) {
			int num = (int)(c - '0');
			// System.out.println(num);
			array[num]++;
		}
		
		// for(int i = 0; i < array.length; i++) {
		// 	if(array[i] != 0) {
		// 		System.out.println("i = " + i + ", array[i] = " + array[i] + ", char = " + ((char)(i+'0')));
		// 	}
		// }
		
		for(int i = 0; i < array.length; i++) {
			int freq = array[i];
			
			if(freq != 0) {
				if(aol[freq] == null) {
					aol[freq] = new ArrayList<>();
				}
				aol[freq].add((char)(i+'0'));
			}
		}
		
		for(int i = aol.length-1; i >= 0 ; i--) {
			if(aol[i] != null) {
				for(int j = 0; j < aol[i].size(); j++) {
					for(int k = 0; k < i; k++) {
						// System.out.println(String.valueOf(aol[i].get(j)));		
						sb.append(String.valueOf(aol[i].get(j)));
					}
				}
			}
		}
        
		return sb.toString();
    }
}