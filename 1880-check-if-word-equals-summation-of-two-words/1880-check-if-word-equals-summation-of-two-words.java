class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
		StringBuilder firstNum = new StringBuilder();
		StringBuilder secondNum = new StringBuilder();
		StringBuilder targetNum = new StringBuilder();
		
		for(Character c : firstWord.toCharArray()) {
			firstNum.append(Character.getNumericValue(c)-10);
		}
		
		for(Character c : secondWord.toCharArray()) {
			secondNum.append(Character.getNumericValue(c)-10);
		}
		
		for(Character c : targetWord.toCharArray()) {
			targetNum.append(Character.getNumericValue(c)-10);
		}
		
		return Integer.parseInt(firstNum.toString()) + Integer.parseInt(secondNum.toString()) == Integer.parseInt(targetNum.toString());
    }
}