import java.util.List;

class Solution {
    private int[] visited;
    
    private void dfs(List<List<Integer>> rooms, int room) {
        if (visited[room] == 1)    return;
        visited[room] = 1;
        
        for (int key : rooms.get(room)) {
            dfs(rooms, key);
        }
    }
    
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        visited = new int[rooms.size()];
        
        // Go dfs search
        dfs(rooms, 0);
        
        for (int i = 0; i < visited.length; i++)
            if (visited[i] == 0)    return false;
        
        return true;
    }
}