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

class Stack {

    Node top = null;

    Stack(int x, int y) {
        this.top = new Node(x, y);
    }

    void push(int x, int y) {
        Node newNode = new Node(x, y);

        if(top == null) { 
            top = newNode;
        }else{
            newNode.next = top;
            top = newNode;
        }
    }

    Node pop() {
        Node tmp = new Node(top.x, top.y);
        top = top.next;

        return tmp;
    }


    void print_stack() {
        for(Node tmp = top; tmp != null; tmp = tmp.next) {
            System.out.printf("%d, %d\n", tmp.x, tmp.y);
        }
    }

}

class Main {
    public static void main(String[] args) {
        Stack st = new Stack(1, 1);

        System.out.println("--------------------------- printing the stack -----------------------------");
        st.print_stack();

        st.push(2, 2);
        st.push(3, 3);
        st.push(4, 4);
        st.push(5, 5);
        st.push(6, 6);

        System.out.println("--------------------------- printing the stack -----------------------------");
        st.print_stack();

        System.out.println("----------------------------------------------------------------------------\n");
        Node node_ref = st.pop();
        System.out.printf("Values of the popped Node: %d, %d\n\n", node_ref.x, node_ref.y);

        System.out.println("-------------- printing the stack after popping the top Node ---------------");
        st.print_stack();
    }
}
