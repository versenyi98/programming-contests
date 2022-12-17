class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token.isnumeric() or token[1:].isnumeric():
                stack.append(int(token))
            else:
                operand1 = stack[-2]
                operand2 = stack.pop(-1)

                if token == "/":
                    token = "//"
                    actual = eval(f"{operand1} {token} {operand2}")
                    candidate = eval(f"{abs(operand1)} {token} {abs(operand2)}")
                    if abs(actual) != abs(candidate):
                        stack[-1] = -1 * candidate
                    else:
                        stack[-1] = actual
                else:
                    stack[-1] = eval(f"{operand1} {token} {operand2}")
        return stack[-1]