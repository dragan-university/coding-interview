/*
https://www.hackerrank.com/challenges/ctci-balanced-brackets

Examples:
{[()]} - YES
{[(])} - NO
{{[[(())]]}} - YES

TC1:
Input
5
}][}}(}][))]
[](){()}
()
({}([][]))[]()
{)[](}]}]}))}(())(

Output
NO
YES
YES
YES
NO

Discussion:


How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class Solution
{
    private static final boolean DEBUG = false;

    public static boolean isOpenBracket(char bracket) {
        return ("{[(".indexOf(bracket) != -1);
    }

    public static boolean isPairOfBrackets(char b1, char b2) {
        if ((b1 == '(' && b2 == ')') || (b1 == '[' && b2 == ']') || (b1 == '{' && b2 == '}')) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean isBalanced(String expression) {
        Stack bracketsStack = new Stack();

        for (int i=0; i<expression.length(); i++) {
            char c = expression.charAt(i);

            if (isOpenBracket(c)) {
                bracketsStack.push(c);
            } else {
                char openBracket;
                try {
                    openBracket = (char)bracketsStack.pop();
                } catch (EmptyStackException exc) {
                    if (DEBUG) System.out.println("E Failure at index " + i + " bracket " + c);
                    return false;
                }

                if (!isPairOfBrackets(openBracket, c)) {
                    if (DEBUG) System.out.println("M Failure at index " + i + " bracket " + c);
                    return false;
                }
            }
        }

        if (bracketsStack.empty()) {
            return true;
        } else {
            return false;
        }
    }

    public static void testIsBalanced(String expression, boolean expected, int testNumber) {
        if (DEBUG) System.out.println("expected " + expected);
        boolean actual = isBalanced(expression);

        if (actual == expected) {
            if (testNumber == -1) {
                System.out.println("PASS!");
            } else {
                //System.out.println(testNumber + " PASS!");
            }
        } else {
            if (testNumber == -1) {
                System.out.println("FAIL!");
            } else {
                System.out.println(testNumber + " FAIL!");
                System.out.println(expression);
            }
        }
    }
    
    public static void testIsBalanced(String expression, boolean expected) {
        testIsBalanced(expression, expected, -1);
    }
    
    public static void testHrSample1() {
        testIsBalanced("{[()]}", true);
    }

    public static void testHrSample2() {
        testIsBalanced("{[(])}", false);
    }

    public static void testHrTc1_1() {
        testIsBalanced("}][}}(}][))]", false);
    }

    public static void testsFromFiles(String inFilename, String outFilename, int testToRun) throws FileNotFoundException, IOException {
        File inFile = new File(inFilename);
        File outFile = new File(outFilename);
        FileReader inFileR = new FileReader(inFile);
        FileReader outFileR = new FileReader(outFile);
        BufferedReader inFileBR = new BufferedReader(inFileR);
        BufferedReader outFileBR = new BufferedReader(outFileR);

        String line = inFileBR.readLine();
        int n = Integer.parseInt(line);
        for (int testNumber=0; testNumber<n; testNumber++) {
            String expression = inFileBR.readLine();
            String expected = outFileBR.readLine();

            if (testToRun == -1 || testNumber == testToRun) {
                if (DEBUG) System.out.println("E " + expected);
                testIsBalanced(expression, expected.compareTo("YES") == 0, testNumber);
            }
        }
    }

    public static void testsFromFiles(String inFile, String outFile) throws FileNotFoundException, IOException {
        testsFromFiles(inFile, outFile, -1);
    }
    public static void hackerrank() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            String expression = in.next();
            System.out.println( (isBalanced(expression)) ? "YES" : "NO" );
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        //hackerrank();
        testsFromFiles("input04.txt", "output04.txt");
        //testsFromFiles("input07.txt", "output07.txt", 0);
        //testHrTc1_1();
        //testHrSample1();
        //testHrSample2();
    }
}
