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

class MSTNode {
    char from;
    char to;
    int cost;

    MSTNode(char from, char to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}

public class Kruskals {

    static Vertex adjList[] = new Vertex[100];
    static int numVertices = 0;
    static int numEdges = 0;
    static int intMax = 2147483647;

    static void addVertex(char vertex){
        adjList[numVertices] = new Vertex(vertex);
        numVertices++;
    }

    static void addUndirEdge(char v1, char v2, int cost) {
        numEdges++;
        for(int i=0; i<numVertices ; i++) {
            
            if( adjList[i].vertex_name == v1 )
                addToList( (adjList[i]), v2, cost);

            if( adjList[i].vertex_name == v2 )
                addToList( (adjList[i]), v1, cost);

        }
    }

    static void addDirEdge(char v1, char v2, int cost) {
        numEdges++;
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

    static MSTNode lookupMSTlist(MSTNode[] MSTlist, char start) {
    	MSTNode result = new MSTNode('0', '0', 0);
        for(int i = 0; i<MSTlist.length; i++) {
            if(start == MSTlist[i].from)
                result = MSTlist[i];
        }
		return result;
    }

    static void kruskals(char start) {

        PriorityQueue<Character> pq = new PriorityQueue<Character>();
        MSTNode[] MSTlist = new MSTNode[numEdges];


    }
    

    public static void main(String args[]) {
    	
    	addVertex('A');
        addVertex('B');
        addVertex('C');
        addVertex('D');
        addVertex('E');
        addVertex('F');
        addVertex('G');
        addVertex('H');
        addVertex('I');
    
        addUndirEdge('A', 'B', 4);
        addUndirEdge('A', 'H', 8);
        addUndirEdge('B', 'C', 8);
        addUndirEdge('B', 'H', 11);
        addUndirEdge('C', 'D', 7);
        addUndirEdge('C', 'F', 4);
        addUndirEdge('C', 'I', 2);
        addUndirEdge('E', 'F', 10);
        addUndirEdge('G', 'H', 1);
        addUndirEdge('G', 'I', 6);
        addUndirEdge('H', 'I', 7);

        printGraph(adjList);
        kruskals('A');
    }

}