import sys

key = int(sys.argv[1])
word = raw_input("Enter a word to cipher: ")
cipher = ""

for char in word:
    if char >= 'A' and char <= 'Z':
        if ord(char) + key > 90:
            cipher += chr((ord(char)+(key - 91 + 65)))
        else:
            cipher += chr((ord(char)+key))
    elif char >= 'a' and char <= 'z':
        if ord(char) + key > 122:
            cipher += chr((ord(char)+(key - 123 + 97)))
        else:
            cipher += chr((ord(char)+key))
    else:
        cipher += char
        
    #result = ''.join(cipher)
    print cipher
    