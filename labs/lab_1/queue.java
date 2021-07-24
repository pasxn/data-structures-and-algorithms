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

class Queue {

    Node top = null;

    Queue(int x, int y) {
        this.top = new Node(x, y);
    }

    void addQ(int x, int y) {
        Node newNode = new Node(x, y);

        if(top == null) { 
            top = newNode;
        }else{
            Node tmp;
            for(tmp = top; tmp.next != null; tmp = tmp.next);
            tmp.next = newNode;
        }
    }

    Node removeQ() {
        Node tmp = new Node(top.x, top.y);
        top = top.next;

        return tmp;
    }


    void print_Queue() {
        for(Node tmp = top; tmp != null; tmp = tmp.next) {
            System.out.printf("%d, %d\n", tmp.x, tmp.y);
        }
    }

}

class Main {
    public static void main(String[] args) {
        Queue q = new Queue(1, 1);

        System.out.println("--------------------------- printing the Queue -----------------------------");
        q.print_Queue();

        q.addQ(2, 2);
        q.addQ(3, 3);
        q.addQ(4, 4);
        q.addQ(5, 5);
        q.addQ(6, 6);

        System.out.println("--------------------------- printing the Queue -----------------------------");
        q.print_Queue();

        System.out.println("----------------------------------------------------------------------------\n");
        Node node_ref = q.removeQ();
        System.out.printf("Values of the popped Node: %d, %d\n\n", node_ref.x, node_ref.y);

        System.out.println("-------------- printing the Queue after popping the front Node ---------------");
        q.print_Queue();
    }
}
