import java.io.File;
import java.util.Scanner;

public class Basic_dfs {
    static boolean[] visit;
    static int[][] arr;
    static int[] path;
    static int p, N, E;

    static void rec(int cur, int end) {
        // if we have reached the end node, the we print the path and exit
        if (cur == end) {
            for (int i=0; i<p; i++) {
                System.out.print(path[i] + ", ");
            }
            System.out.println(end);
            return;
        }

        // we only come here if we haven't reached the end

        visit[cur] = true;  // mark the current node as visited
        path[p++] = cur;    // add the current node to the path

        // check all the outgoing edges from this node
        for (int i=1; i<=N; i++)
            // if the path exists (non-zero weight) AND the destination is not visited yet
            // (we check visitation to avoid getting caught in a cycle)
            if (arr[cur][i] > 0 && !visit[i])
                // we recurse to the next node
                rec(i, end);

        // this is backtracking; on the way back we:
        p--;                    // remove the current node from the path
        visit[cur] = false;     // mark node as unvisited
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("graph.in"));

        // read the number of nodes and edges
        N = in.nextInt();
        E = in.nextInt();

        // create weighted adjacency matrix to hold the graph in memory
        arr = new int[N+1][N+1];

        // create an array to store the visit status of each node during DFS
        visit = new boolean[N+1];

        // create space to store temporary path while DFS traversal
        path = new int[N*N];

        // read the weights of each edge and store in the graph
        for (int i=0; i<E; i++) {
            int st = in.nextInt();
            int et = in.nextInt();
            int w = in.nextInt();
            arr[st][et] = w;
        }
        in.close();

        // print the graph to check if everything was read correctly
        // this is good practice, saves time during a competition!
        for (int i=1; i<=N; i++) {
            for (int j = 1; j <= N; j++)
                System.out.print(arr[i][j] + " ");
            System.out.println();
        }
        System.out.println();

        // recurse from node 1 to until we find node 6
        rec(1,6);
    }
}