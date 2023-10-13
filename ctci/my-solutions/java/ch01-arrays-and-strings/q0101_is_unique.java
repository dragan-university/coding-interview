/*
Q 1.1 java

See cpp for full description.

Build:
javac <file>.java
Run:
java <file>
*/
import java.util.*;

public class q0101_is_unique {
    public static boolean hasUniqueChars(String s) {
        Set sChars = new HashSet();

        for (int i=0; i<s.length(); i++) {
            if (sChars.contains(s.charAt(i))) {
                return false;
            }

            sChars.add(s.charAt(i));
        }

        return true;
    }

    public static void test_hasUniqueChars(String s, boolean expected) {
        System.out.println("Check '" + s + "' - expected " + expected);
        boolean actual = hasUniqueChars(s);

        if (actual == expected) {
            System.out.println("PASS!");
        } else {
            System.out.println("FAIL!");
        }
    }

    public static void main(String[] args) {
        test_hasUniqueChars("dragan", false);
        test_hasUniqueChars("zoran", true);
    }
}
