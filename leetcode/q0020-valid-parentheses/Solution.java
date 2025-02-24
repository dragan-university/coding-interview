import java.util.*;

class Solution {
    public static boolean isValid(String s) {
        Stack<Character> ss = new Stack<Character>();

        for (char c : s.toCharArray()) {
            if (isOpenBracket(c)) {
                ss.push(c);
            } else {
                if (ss.isEmpty()) {
                    return false;
                }

                if (ss.pop() != invert(c)) {
                    return false;
                } 
            }
        }

        return ss.isEmpty();
    }

    private static char invert(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';

        throw new IllegalArgumentException("Invalid bracket!");
    }

    private static boolean isOpenBracket(char c) {
        List<Character> openBrackets = Arrays.asList('(', '[', '{');

        return openBrackets.contains(c);
    }

    public static void main(String[] args) {
        System.out.println(isValid("([]){}"));
        System.out.println(isValid(")"));
        System.out.println(isValid("){"));
        System.out.println(isValid("(){}}{"));
    }    
}
