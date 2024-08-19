class Solution {
    public boolean isValidSudoku(char[][] board) {
		Set<Character> setHorizontal;
		Set<Character> setVertical;
		Set<Character> subBoxes;
		
		for(int i = 0; i < 9; i++) {
			setHorizontal = new HashSet<>();
			setVertical = new HashSet<>();
			
			for(int j = 0; j < 9;  j++) {
				char horizontalChar = board[i][j];
				char verticalChar = board[j][i];
				
				if(horizontalChar != '.') {
					if(setHorizontal.contains(horizontalChar)) return false;
					else setHorizontal.add(horizontalChar);
				}
				
				if(verticalChar != '.') {
					if(setVertical.contains(verticalChar)) return false;
					else setVertical.add(verticalChar);
				}
			}
		}
		
		for(int i = 0; i < 3; i++) {
			subBoxes = new HashSet<>();
			for(int j =i*3; j < (i*3+3); j++) {
				for(int k = 0; k < 3; k++) {
					char character = board[j][k];
					
					if(character != '.') {
						if(subBoxes.contains(character)) return false;
						else subBoxes.add(character);
					}
				}
			}

			subBoxes = new HashSet<>();
			for(int j = i*3; j < (i*3+3); j++) {
				for(int k = 3; k < 6; k++) {
					char character = board[j][k];
					
					if(character != '.') {
						if(subBoxes.contains(character)) return false;
						else subBoxes.add(character);
					}
				}
			}

			subBoxes = new HashSet<>();
			for(int j = i*3; j < (i*3+3); j++) {
				for(int k = 6; k < 9; k++) {
					char character = board[j][k];
					
					if(character != '.') {
						if(subBoxes.contains(character)) return false;
						else subBoxes.add(character);
					}
				}
			}
		}

		return true;
	}
}