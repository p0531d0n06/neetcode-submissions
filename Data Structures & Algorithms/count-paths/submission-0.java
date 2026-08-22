class Solution {

    HashMap<Integer, Integer> memo;

    public int uniquePaths(int m, int n) {
        memo = new HashMap<Integer, Integer>();

        return uniquePaths(m,n,0,0,0);
    }

    public int uniquePaths(int m, int n, int y, int x, int i) {
        if(y == m-1 && x == n-1) return 1;
        if(memo.get(y * n + x) != null) return memo.get(y * n + x);

        if(y < m-1) i += uniquePaths(m,n,y+1,x,0);
        if(x < n-1) i += uniquePaths(m,n,y,x+1,0);

        memo.put(y * n + x, i);

        return i;
    }
}
