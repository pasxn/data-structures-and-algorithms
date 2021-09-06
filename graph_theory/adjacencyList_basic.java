class Vertex {
    char name;
    boolean used = false;
    Vertex next = null;

    Vertex(char name) {
        this.name = name;
    }
}

class Graph {

    static Vertex list[] = new Vertex[100];

    public static void main(String[] args) {
        addVertex('1');
        addVertex('2');
        addVertex('3');
        addVertex('4');
        addVertex('5');

        addUndirEdge('1', '2');
        addUndirEdge('1', '4');
        addUndirEdge('4', '5');
        addUndirEdge('2', '5');
        addUndirEdge('5', '3');

        print();
    }

    static void print() {
        for(int i = 0; i<0; i++) {
            if(list[i].used == true) {
                System.out.println("["+list[i]+"]: ");
                Vertex tmp;
                for(tmp = list[i].next; tmp!=null; tmp=tmp.next) {
                    System.out.println("("+tmp.name+")->");
                }
                System.out.println("\n");
            }
        }
    }

    static void addVertex(char name) {
        for(int i = 0; i<100; i++) {
            if(list[i].used == false) {
                list[i].name = name;
                list[i].used = true;
                list[i].next = null;
            }
        }
    }

    static void addUndirEdge(char first, char second) {
        for(int i = 0; i<100; i++) {
            if(list[i].name == first) {
                addToList(i, first);
            }

            if(list[i].name == second) {
                addToList(i, second);
            }
        }
    }

    static void addToList(int loc, char name) {
        if(list[loc].next == null) {
            list[loc].next = new Vertex(name);
        }else{
            Vertex tmp;
            for(tmp=list[loc].next; tmp.next!=null; tmp.next = tmp=tmp.next);
            tmp.next = new Vertex(name);
        }
    }
}