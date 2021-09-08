class Vertex {
    char name;
    Vertex next = null;

    Vertex(char name) {
        this.name = name;
    }
}

class Graph {

    static Vertex list[] = new Vertex[100];
    static int vertices_added = 0;

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
       	for(int i=0; list[i] != null; i++) {
            System.out.print("list["+list[i].name+"]: ");
            
            Vertex tmp;
            for(tmp=list[i].next; tmp!=null;tmp=tmp.next) {
                System.out.print("->("+tmp.name+")");
            }
            System.out.println();
       	}
    }

    static void addVertex(char name) {
        list[vertices_added] = new Vertex(name);
        vertices_added++;
    }

    static void addUndirEdge(char first, char second) {
      for(int i=0; list[i] != null; i++) {
          if(list[i].name == first) 
              addToList(i, second);
          if(list[i].name == second)
              addToList(i, first);
      }
  }

    static void addToList(int loc, char name) {
        if(list[loc].next == null) {
            list[loc].next = new Vertex(name);
        }else{
            Vertex tmp;
            for(tmp=list[loc].next; tmp.next!=null; tmp=tmp.next);
            tmp.next = new Vertex(name);
        }
    }
}