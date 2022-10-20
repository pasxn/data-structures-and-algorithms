class Node {
    char name;
    int weight;
    Node next;

    Node(char name) {
        this.name = name;
        this.weight = 0;
        this.next = null;
    }
}

class GraphMat {

    static int matrix[][] = new int[5][5];
    static Node vertices[] = new Node[5];
    static int vertices_added = 0;

    public static void main(String[] args) {
        addVertex('A');
        addVertex('B');
        addVertex('C');
        addVertex('D');
        addVertex('E');

        addDirEdge('B', 'A');
        addDirEdge('A', 'D');
        addDirEdge('D', 'E');
        addDirEdge('B', 'E');
        addDirEdge('E', 'B');
        addDirEdge('E', 'C');

        printMat();
    }

    static void addVertex(char name) {
        vertices[vertices_added] = new Node(name);
        vertices_added++;
    }

    static void addDirEdge(char v1, char v2) {
        int loc1 = 0;
        int loc2 = 0;
        
        for(int i = 0; i < 5; i++) {
            if(vertices[i].name == v1)
                loc1 = i;
            
            if(vertices[i].name == v2)
                loc2 = i;    
        }
        matrix[loc1][loc2] = 1;
    }

    static void printMat() {
        System.out.print("  ");
        for(int i = 0; i<5; i++) {
            System.out.print(" " + vertices[i].name + "|");
        }
        System.out.println();

        for(int i = 0; i<5; i++) {
            System.out.print(vertices[i].name + "|");

            for(int j = 0; j<5; j++)
                System.out.print(" " + matrix[i][j] + "|");
            System.out.println();
        }
    }
}