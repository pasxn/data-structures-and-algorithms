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
    static Node top = null;

    public static void main(String[] args) {
        linkedList(1, 1);
        linkedList(2, 2);
        linkedList(3, 3);
    
        printList();
    }

    static void linkedList(int x, int y) {
        Node newNode = new Node(x, y);

        if(top == null) { 
            top = newNode;
        }else{
            Node tmp;
            for(tmp = top; tmp.next != null; tmp = tmp.next);
            tmp.next = newNode;
        }
    }

    static void printList() {
        for(Node tmp = top; tmp != null; tmp = tmp.next){
            System.out.printf("%d, %d \n", tmp.x, tmp.y);
        }
    }

}