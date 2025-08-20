
def isValid(holder, row, column):
    for i in range(row):
        if holder[i] == column:
            return False
    
    return True

def recursively(board, holder, sizeBoard, numChess, row, count):
    if count == numChess:
        return 1
    
    if row == sizeBoard:
        return 0
    
    pathway = 0

    for i in range(sizeBoard):
        if board[row][i] == '#' and isValid(holder, row, i):
            holder[row] = i
            pathway += recursively(board, holder, sizeBoard, numChess, row + 1, count + 1)
            holder[row] = -1

    pathway += recursively(board, holder, sizeBoard, numChess, row + 1, count)
    return pathway

if __name__ == '__main__':

    size, num = map(int, input().split())

    board = [list(input().strip()) for _ in range(size)]
    holder = [-1]*size

    count = recursively(board, holder, size, num, 0, 0)
    print(count)