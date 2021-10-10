import java.util.*;

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

    int getCost() {
        return this.cost;
    }
}

class Vertex2 {
    char vertex_name;
    LinkedList<Character> list = new LinkedList<>();

    Vertex2(char vertex_name, char to) {
        this.vertex_name = vertex_name;
        list.add(to);
    }
}

public class Kruskals {

    static Vertex adjList[] = new Vertex[100];
    static int numVertices = 0;
    static int numEdges = 0;
    static int intMax = 2147483647;
    static LinkedList<Vertex2> adj = new LinkedList<Vertex2>();
    static LinkedList<Character> adj_util = new LinkedList<Character>();

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
    
    static int lookup(MSTNode[] MSTlist, int cost) {
    	int result = 0;
        for(int i = 0; i<numVertices; i++) {
            if(cost == MSTlist[i].cost)
                result = i;
        }
		return result;
    }

    static MSTNode lookupMSTlist(MSTNode[] MSTlist, char start, char stop) {
    	MSTNode result = new MSTNode(' ', ' ', 0);
        for(int i = 0; i<MSTlist.length; i++) {
            if( (start == MSTlist[i].from && stop == MSTlist[i].to) || (start == MSTlist[i].to && stop == MSTlist[i].from))
                result = MSTlist[i];
        }
		return result;
    }

    static void kruskals(char start) {
        MSTNode[] MSTlistUndir = new MSTNode[50];
        MSTNode[] MSTlistDir = new MSTNode[50];
        int NumMSTNodes = 0;
        int NumMSTUndirNodes = 0;

        for(int i = 0; i<50; i++) {
            MSTlistUndir[i] = new MSTNode(' ', ' ', 0);
            MSTlistDir[i] = new MSTNode(' ', ' ', 0);
        }

        for(int i= 0; i < numVertices; i++) {
            for(Vertex tmp = adjList[i].next; tmp != null; tmp = tmp.next) {
                
                MSTlistUndir[NumMSTNodes].from = adjList[i].vertex_name;
                MSTlistUndir[NumMSTNodes].to = tmp.vertex_name;
                MSTlistUndir[NumMSTNodes].cost = tmp.cost;

                NumMSTNodes++;

            }
        }

        for(int i = 0; MSTlistUndir[i].from != ' '; i++) {
            if(lookupMSTlist(MSTlistDir, MSTlistUndir[i].from, MSTlistUndir[i].to).from == ' ')
                MSTlistDir[NumMSTUndirNodes++] = MSTlistUndir[i];
        }

        List<MSTNode> MSTlistDirSorted = new ArrayList<MSTNode>();
        for(MSTNode item :MSTlistDir) {
            if(item.from != ' ') {
                MSTlistDirSorted.add(item); 
            }
        }

        // sorting the ArrayList by cost
        MSTlistDirSorted.sort(Comparator.comparing(MSTNode::getCost));


        for(int i = 0; i<MSTlistDirSorted.size(); i++) {
            System.out.printf("%c, %c, %d \n", MSTlistDirSorted.get(i).from, MSTlistDirSorted.get(i).to, MSTlistDirSorted.get(i).cost);
        }

        List<MSTNode> MinSpanningTree = new ArrayList<MSTNode>();

        for(int i=0; i<MSTlistDirSorted.size(); i++) {
            MSTNode subject = MSTlistDirSorted.get(i);
            if(!isCycle(subject))
                MinSpanningTree.add(subject);
        }

        /*for(int i = 0; i<adj.size(); i++) {
            System.out.print(adj.get(i).vertex_name + " -> ");
            System.out.println(adj.get(i).list.toString());

        }*/
        
        for(int i = 0; i<MinSpanningTree.size(); i++) {
            System.out.printf("%c, %c, %d \n", MinSpanningTree.get(i).from, MinSpanningTree.get(i).to, MSTlistDirSorted.get(i).cost);
        }

    }
    
    static Boolean isCycle(MSTNode node) {
        
        if(adj_util.contains(node.from)) {
            int index =  adj_util.indexOf(node.from);
            adj.get(index).list.add(node.to);
        }else{
            adj_util.add(node.to);
            adj.add(new Vertex2(node.from, node.to));
        }
 
        Boolean visited[] = new Boolean[adj.size()];
        for (int i = 0; i < adj.size(); i++)
            visited[i] = false;

        for (int u = 0; u < adj.size(); u++) { 
            if (!visited[u])
                if (isCyclicUtil(u, visited, -1))
                    return true;
        }
 
        return false;
    }

    static Boolean isCyclicUtil(int v, Boolean visited[], int parent) {
        visited[v] = true;

        for(int i = 0; i<adj.size(); i++) {

            if (!visited[i]) {
                if (isCyclicUtil(i, visited, v))
                    return true;
            }

            else if (i != parent)
                return true;
        }
        return false;
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
        addUndirEdge('D', 'E', 9);
        addUndirEdge('D', 'F', 14);
        addUndirEdge('E', 'F', 10);
        addUndirEdge('G', 'F', 2);
        addUndirEdge('G', 'H', 1);
        addUndirEdge('G', 'I', 6);
        addUndirEdge('H', 'I', 7);

        printGraph(adjList);
        kruskals('A');
    }

}