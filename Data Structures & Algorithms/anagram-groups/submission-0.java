class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> store = new HashMap<>();

        for(int i = 0; i < strs.length; i++){
            int[] a = new int[26];

            for(char z : strs[i].toCharArray()){
                a[(int)z-97] += 1;
            }
            
            String key = Arrays.toString(a);

            if(store.containsKey(key)){
                store.get(key).add(strs[i]);
            } else {
                store.put(key, new ArrayList<String>());
                store.get(key).add(strs[i]);
            }
        }

        List<List<String>> result = new ArrayList<>();

        for(List<String> v : store.values()){
            result.add(v);
        }
            
        return result;
    }
}
