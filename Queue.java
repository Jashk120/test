```java
import java.util.LinkedList;

/**
 * A simple generic queue implementation using a LinkedList.
 * Provides FIFO (first-in, first-out) behavior for integers.
 */
public class Queue {
    private LinkedList<Integer> list = new LinkedList<>();

    /**
     * Adds an element to the end of the queue.
     *
     * @param value the integer value to be appended to the queue
     */
    public void enqueue(int value) {
        list.addLast(value);
    }

    /**
     * Removes and returns the element at the front of the queue.
     *
     * @return the integer at the front of the queue
     * @throws java.util.NoSuchElementException if the queue is empty
     */
    public int dequeue() {
        return list.removeFirst();
    }

    /**
     * Checks whether the queue contains no elements.
     *
     * @return {@code true} if the queue is empty, {@code false} otherwise
     */
    public boolean isEmpty() {
        return list.isEmpty();
    }
}
```