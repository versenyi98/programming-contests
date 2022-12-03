class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = s.lower()
        half_length = len(s) // 2
        first_half = s[:half_length]
        second_half = s[half_length:]

        vowels = list("aeiou")
        count = 0

        for first_char, second_char in zip(list(first_half), list(second_half)):
            if first_char in vowels:
                count += 1
            if second_char in vowels:
                count -= 1

        return count == 0