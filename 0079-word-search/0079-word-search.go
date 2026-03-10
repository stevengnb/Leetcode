func exist(board [][]byte, word string) bool {
    idx := 0

    for i := range len(board) {
        for j := range len(board[0]) {
            if board[i][j] == word[idx] {
                if backtrack(board, word, idx, i, j) {
                    return true
                }
            }
        }
    }

    return false
}

func backtrack(board [][]byte, word string, idx int, x int, y int) bool {
    if idx == len(word) {
        return true
    }

    if x < 0 || y < 0 || x >= len(board) || y >= len(board[0]) || board[x][y] != word[idx] {
        return false
    }

    temp := board[x][y]
    board[x][y] = '.'

    res1 := backtrack(board, word, idx+1, x+1, y)
    res2 := backtrack(board, word, idx+1, x-1, y)
    res3 := backtrack(board, word, idx+1, x, y+1)
    res4 := backtrack(board, word, idx+1, x, y-1)

    board[x][y] = temp

    return res1 || res2 || res3 || res4
}