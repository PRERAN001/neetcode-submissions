class Solution:
    def isPalindrome(self, s: str) -> bool:
        text=s.lower()        
        text2=""
        for char in text:
            if char.isalnum():
                text2+=char
        return text2==text2[::-1]