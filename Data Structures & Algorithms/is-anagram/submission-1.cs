public class Solution {
    public bool IsAnagram(string s, string t) {
        List<char> characters = s.ToCharArray().ToList();

        foreach(char a in t){
            if(characters.Contains(a)){
                characters.Remove(a);
            } else {
                return false;
            }
        }
        
        return characters.Count == 0;
    }
}
