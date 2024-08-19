class Solution {
    public int[] topKFrequent(int[] nums, int k) {
		List<Integer>[] bucket = new List[nums.length + 1];
		HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++) {
        	hm.put(nums[i], hm.getOrDefault(nums[i], 0) + 1);
        }
        
        for(int key : hm.keySet()) {
        	int freq = hm.get(key);
        	if(bucket[freq] == null) {
        		bucket[freq] = new ArrayList<>();
        	}
        	bucket[freq].add(key);
        }
        
        int result[] = new int[k];
        
        for(int i = bucket.length-1; i >= 0; i--) {
//        	System.out.println(bucket[i]);
        	if(bucket[i] != null) {
        		for(int j = bucket[i].size()-1; j >= 0; j--) {
        			if(k > 0) {
        				result[--k] = bucket[i].get(j);
        			}
        		}
        	}
        }
        
//        for(int i = 0; i < result.length; i++) {
//        	System.out.println(result[i]);
//        }
//        
        return result;
    }
}