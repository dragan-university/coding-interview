/**
 * Given an array of strings, group the strings that are anagrams of each other. Each group should contain all the
 * strings that have the same characters in any order. Return a list of groups of anagrams.
 * 
 * Example Input: ["abc", "bac", "cab", "asd", "dsa", "xyz"]
 * Example Output: [["abc", "bac", "cab"], ["asd", "dsa"], ["xyz"]]
 * 
 * Build: javac <file>.java
 * Run: java <file>
 */

// if package is used then you need to run the app from the root folder that contains folder 'misc'
// package misc.anagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    
    public static List<List<String>> anagramGroups(String[] input) {
        List<List<String>> result = new ArrayList<List<String>>();

        Map<String, List<String>> anagramMap = new HashMap<>();
    
        for (String str: input) {
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);
        
            if (!anagramMap.containsKey(sortedStr)) {
                anagramMap.put(sortedStr, new ArrayList<>());
            }
            anagramMap.get(sortedStr).add(str);
        }
    
        result.addAll(anagramMap.values());

        return result;
}
	
	public static void main(String[] args) {
		String[] strings = {"abc", "bac", "cab", "asd", "dsa", "xyz"};

        List<List<String>> result = anagramGroups(strings);

        int i = 0;
        for (List<String> group: result) {
            i++;
            System.out.println(String.format("=== Group %d ===", i));

            for (String s: group) {
                System.out.println(s);
            }
        }
	}
}
