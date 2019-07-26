import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Collections;

class Solution {   
    public void DFS(String[][] tickets, List<String> result, int[] visited, int target) {    
        for (int i = 0; i < tickets.length; i++) {
            if (tickets[i][0].equals(tickets[target][1]) && visited[i] == 0) {
                visited[i] = 1;    // Update visited array
                result.add(tickets[i][1]);    

                //Recursion
                DFS(tickets, result, visited, i);

                // Once find one solution, return all the way up
                if (result.size() == tickets.length + 1)    return; 
            }      
        }
        
        // When find a route, return
        if (result.size() == tickets.length + 1)    return;
        
        // If the route is unreachable, reset visited array and result list, return
        visited[target] = 0;
        result.remove(result.size() - 1);
        return;
    }
    
    public List<String> findItinerary(String[][] tickets) {   
        /////////////////////////////////////////////////////////////////////
		// Create Map
        HashMap<String, List<String>> map = new HashMap<>();
		for (String[] s : tickets) {
			if (map.containsKey(s[0])) {
				map.get(s[0]).add(s[1]);
			} else {
				List<String> l = new ArrayList<>();
				l.add(s[1]);
				map.put(s[0], l);
			}
		}

		// sort the graph in lexi-graphic Order
		for (HashMap.Entry<String, List<String>> entry : map.entrySet()) {
			Collections.sort(entry.getValue());
		}

        // Update array tickets
        int k = 0;
        for (String s : map.keySet()) {
            for (String v : map.get(s)) {
                tickets[k][0] = s;
                tickets[k][1] = v;
                k++;
            }
        }
        
        
        /////////////////////////////////////////////////////////////////////        
        List<String> result = new ArrayList<String>();
        result.add("JFK");

        int[] visited = new int[tickets.length];
        
               
        for (int i = 0; i < tickets.length; i++) {
            if (tickets[i][0].equals("JFK") && visited[i] == 0) {
                visited[i] = 1;
                result.add(tickets[i][1]);
                DFS(tickets, result, visited, i);
            }         
        }

        
        return result;
    }   
}