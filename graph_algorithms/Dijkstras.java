package assignment;

import java.util.PriorityQueue;

class Vertex {
    char vertex_name;
    boolean visited;
    int cost;
    Vertex next;
    
    Vertex() {
        this.vertex_name = ' ';
        this.visited = false;
        this.cost = 0;
        this.next = null;
    }
    
    Vertex(char vertex) {
        this.vertex_name = vertex;
        this.visited = false;
        this.cost = 0;
        this.next = null;
    }
    
    Vertex(char vertex, int cost) {
        this.vertex_name = vertex;
        this.visited = false;
        this.cost = cost;
        this.next = null;
    }
}

class Node {
	char node_name;
	int dist;
	char prev;
}

public class Dijkstras{

    static Vertex adjList[] = new Vertex[100];
    static int numVertices = 0;
    static int intMax = 2147483647;

    static void addVertex(char vertex){
        adjList[numVertices] = new Vertex(vertex);
        numVertices++;
    }

    static void addUndirEdge(char v1, char v2, int cost) {
        for(int i=0; i<numVertices ; i++) {
            
            if( adjList[i].vertex_name == v1 )
                addToList( (adjList[i]), v2, cost);

            if( adjList[i].vertex_name == v2 )
                addToList( (adjList[i]), v1, cost);

        }
    }

    static void addDirEdge(char v1, char v2, int cost) {
        for(int i=0; i<numVertices ; i++) {
            
            if( adjList[i].vertex_name == v1 )
                addToList( (adjList[i]), v2, cost);
                
        }
    }

    static void addToList(Vertex n, char vertex, int cost) {
        Vertex tmp;
        // move to end of current list
        for(tmp = n; tmp.next != null; tmp = tmp.next);
        tmp.next = new Vertex(vertex, cost);
    }

    static void printGraph(Vertex list[]) {
        for(int i=0; i < numVertices; i++) {
            System.out.printf("[%c] ", list[i].vertex_name);
            for(Vertex tmp=list[i].next; tmp != null; tmp=tmp.next)
                System.out.printf("->(%c: %d)", tmp.vertex_name, tmp.cost);
    
            System.out.printf("\n");
        }
    }
    
    static int lookup(char start) {
    	int result = 0;
        for(int i = 0; i<numVertices; i++) {
            if(start == adjList[i].vertex_name)
                result = i;
        }
		return result;
    }
    
    static void dijkstra(char start) {
    	Node table[] = new Node[numVertices];
    	
    	PriorityQueue<Character> pq = new PriorityQueue<Character>();
    	
        for(int i = 0; i<numVertices; i++) {
        	table[i] = new Node();
            table[i].node_name = adjList[i].vertex_name;
            table[i].prev = 'A';

            if(table[i].node_name == start)
                table[i].dist = 0;
            else {
                table[i].dist = intMax;
            }
            pq.add(table[i].node_name);	
        }
        
        
        while(!pq.isEmpty()) {
        	Node current_node = table[lookup(pq.poll())];
        	
        	for(Vertex tmp = adjList[lookup(current_node.node_name)].next; tmp != null; tmp = tmp.next) {
        		int pos = lookup(tmp.vertex_name); 
        		
            	int distance_from_start = current_node.dist + tmp.cost;
            		  
                if(distance_from_start < table[pos].dist) {
                    table[pos].dist = distance_from_start;
                    table[pos].prev = current_node.node_name;
                }

        	}
        }
        
        System.out.println("---------------------------------------");
        for(int i = 0; i<numVertices; i++)
        	System.out.printf("%c |%d |%c \n", table[i].node_name, table[i].dist, table[i].prev);
    }

    public static void main(String args[]) {
    	
    	addVertex('A');
        addVertex('B');
        addVertex('C');
        addVertex('D');
        addVertex('E');
        addVertex('F');
        addVertex('G');
    
        addDirEdge('A', 'B', 6);
        addDirEdge('A', 'C', 2);
        addDirEdge('A', 'D', 16);
        addDirEdge('B', 'D', 5);
        addDirEdge('B', 'E', 4);
        addDirEdge('C', 'F', 5);
        addDirEdge('C', 'B', 16);
        addDirEdge('C', 'E', 3);
        addDirEdge('D', 'G', 3);
        addDirEdge('E', 'D', 4);
        addDirEdge('E', 'G', 10);
        addDirEdge('F', 'G', 1);
        
        /*
        addVertex('A');
        addVertex('B');
        addVertex('C');
        addVertex('D');
        addVertex('E');
    
        addUndirEdge('A', 'B', 7);
        addUndirEdge('A', 'C', 1);
        addUndirEdge('B', 'C', 3);
        addUndirEdge('B', 'D', 3);
        addUndirEdge('B', 'E', 2);
        addUndirEdge('C', 'D', 1);
        addUndirEdge('D', 'E', 5);
        */

        /*
        addVertex('A');
        addVertex('B');
        addVertex('C');
        addVertex('D');
        addVertex('E');
    
        addUndirEdge('A', 'B', 6);
        addUndirEdge('A', 'D', 1);
        addUndirEdge('B', 'C', 2);
        addUndirEdge('B', 'D', 2);
        addUndirEdge('B', 'E', 2);
        addUndirEdge('C', 'E', 5);
        addUndirEdge('D', 'E', 1);
        */

        printGraph(adjList);
        
        dijkstra('A');
        
    }

}