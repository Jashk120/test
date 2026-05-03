import java.util.LinkedList;
//hi
public class Queue {
    private LinkedList<Integer> list = new LinkedList<>();

    public void enqueue(int value) {
        list.addLast(value);
    }

    public int dequeue() {
        return list.removeFirst();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }
}
