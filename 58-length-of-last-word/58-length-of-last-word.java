class Solution {
    public int lengthOfLastWord(String s) {
        String[] parts = s.split(" ");
        String lastWord = parts[parts.length - 1];
        return lastWord.length();   
    }
}