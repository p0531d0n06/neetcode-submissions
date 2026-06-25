class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> freq_map = new HashMap<>();

        for(int i : nums) {
            if(freq_map.containsKey(i)) {
                freq_map.put(i, freq_map.get(i) + 1);
            } else {
                freq_map.put(i,1);
            }
        }    

        List<Integer>[] num_map = new List[nums.length + 1];

        for(int i : freq_map.keySet()){
            if(num_map[freq_map.get(i)] == null) num_map[freq_map.get(i)] = new ArrayList<>();
            num_map[freq_map.get(i)].add(i);
        }

        int[] result = new int[k];
        k -= 1; 

        int j = num_map.length - 1;
        while(k >= 0) {
            if(num_map[j] == null || num_map[j].size() == 0){
                j--;
                continue;
            }

            result[k] = num_map[j].get(0);
            k -= 1;
            num_map[j].remove(0);
        }

        return result;
    }
}
