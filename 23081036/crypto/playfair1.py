import numpy as np

def FindIndex(matrix, letter):
    # This function returns the row and column index of the letter in the matrix
    for r, row in enumerate(matrix):
        for c, element in enumerate(row):
            if element == letter:
                return r, c
    return None, None

def EncryptMessage(message, key):
    # message as the stack
    keyMatrix = generateMatrix(key)
    message = message.replace(" ", "")  # Corrected the in-place modification of message
    message = list(message)
    cipherText = ''
    
    # Creating digraphs
    i = 0
    while i < len(message):
        digraph = [message[i]]
        
        if i + 1 < len(message):  # If there's a next character
            if message[i] != message[i + 1]:
                digraph.append(message[i + 1])
                i += 2
            else:
                digraph.append('X')
                i += 1
        else:
            digraph.append('X')
            i += 1
        
        r1, c1 = FindIndex(keyMatrix, digraph[0])
        r2, c2 = FindIndex(keyMatrix, digraph[1])
        
        if r1 == r2:  # Same row
            cipherText += keyMatrix[r1][(c1 + 1) % 5]
            cipherText += keyMatrix[r1][(c2 + 1) % 5]
        elif c1 == c2:  # Same column
            cipherText += keyMatrix[(r1 + 1) % 5][c1]
            cipherText += keyMatrix[(r2 + 1) % 5][c2]
        else:  # Rectangle case
            cipherText += keyMatrix[r1][c2]
            cipherText += keyMatrix[r2][c1]
    
    return cipherText

def generateMatrix(key):
    matrix = []
    keyMatrix = [[None for _ in range(5)] for _ in range(5)]
    key = key.upper()  # Ensure key is uppercase
    for char in key:
        if char not in matrix and char not in ['I', 'J']:  # 'I' and 'J' are considered the same
            matrix.append(char)
        elif char == 'I' and 'J' not in matrix:  # Handle I/J as a single character
            matrix.append('I')
    
    letters = [chr(i) for i in range(65, 91)]  # A-Z
    for letter in letters:
        if letter not in matrix and letter not in ['I', 'J']:
            matrix.append(letter)
        elif letter == 'I' and 'I' not in matrix:
            matrix.append('I')
    
    count = 0
    for r in range(5):
        for c in range(5):
            keyMatrix[r][c] = matrix[count]
            count += 1
    
    return keyMatrix

message = "CRYPTOGRAPHY"
key = "ACHS"
print(EncryptMessage(message.upper(), key.upper()))
