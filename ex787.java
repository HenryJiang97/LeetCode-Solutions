// Dijkstra (BFS)

import java.lang.Integer;
import java.util.Arrays;
import java.util.Queue;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    private class fair {
        int des;    int fair;
        private fair(int d, int f) {des = d; fair = f;}
    }
    
    private class stop {
        int station;    int layer;
        private stop(int s, int l) {station = s; layer = l;}
    }
    
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        // Transfer edges to adjacent table
        HashMap<Integer, ArrayList<fair>> adj = new HashMap<>();
        for (int[] flight : flights) {
            if (adj.containsKey(flight[0]))    adj.get(flight[0]).add(new fair(flight[1], flight[2]));
            else    adj.put(flight[0], new ArrayList<>(Arrays.asList(new fair(flight[1], flight[2]))));
        }

        // Build and init price array
        int[] price = new int[n];
        Arrays.fill(price, Integer.MAX_VALUE);
        price[src] = 0;
        
        // BFS
        Queue<stop> BFSQueue = new LinkedList<stop>();
        BFSQueue.offer(new stop(src, 0));
        
        while (!BFSQueue.isEmpty()) {
            stop out = BFSQueue.poll();
            
            // When there's out edge from node "out"
            if (adj.containsKey(out.station)){
                for (fair d : adj.get(out.station)) {
                    // Over required stops
                    if (out.layer == K && d.des != dst)    continue;
                    
                    // Update price when necessary
                    if (price[out.station] + d.fair < price[d.des]) {
                        price[d.des] = price[out.station] + d.fair;
                        BFSQueue.offer(new stop(d.des, out.layer + 1));
                    }
                }
            }
        }
        
        return (price[dst] != Integer.MAX_VALUE) ? price[dst] : -1;
    }
}