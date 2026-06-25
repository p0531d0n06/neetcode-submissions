class Solution {

    public String encode(List<String> strs) {
        String result = "";

        for(String str : strs){
            result += "" + str.length() + "#" + str;
        }

        return result;
    }

    public List<String> decode(String str) {
        if(str.length() == 0) return new ArrayList<String>();

        List<String> result = new ArrayList<String>();

        int i = 0;

        while(i < str.length()){
            String num = ""; 

            while(str.charAt(i) != '#'){
                num += str.charAt(i);
                i++;
            }

            int val = Integer.parseInt(num) + i;

            i++;

            String s = "";

            while(i <= val){ 
                s += str.charAt(i);
                i++;
            }

            result.add(s);
        }

        return result;
    }
}
