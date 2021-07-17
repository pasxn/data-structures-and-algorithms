class Node {
    int x;
    int y;
    Node next;

    Node(int x, int y) {
        this.x = x;
        this.y = y;
        this.next = null;
    }
}

class Linkedlist {
    Node top = null;

    Linkedlist(int x, int y) {
        this.top = new Node(x, y);
    }

    void add(int x, int y) {
        Node newNode = new Node(x, y);

        if(top == null) { 
            top = newNode;
        }else{
            Node tmp;
            for(tmp = top; tmp.next != null; tmp = tmp.next);
            tmp.next = newNode;
        }
    }

    void printList() {
        for(Node tmp = top; tmp != null; tmp = tmp.next){
            System.out.printf("%d, %d \n", tmp.x, tmp.y);
        }
    }

}


class Main {
    public static void main(String[] args) {
        Linkedlist ll = new Linkedlist(1, 1);
        ll.add(2, 2);
        ll.add(3, 3);
        ll.printList();
    }
}
