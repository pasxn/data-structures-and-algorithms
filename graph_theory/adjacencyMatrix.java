import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        
        int grid[][] = {{0, 0, 0, 1, 0}, 
                        {1, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1},
                        {0, 1, 1, 0, 0}}; 

        System.out.println(Arrays.deepToString(grid));
    }
}