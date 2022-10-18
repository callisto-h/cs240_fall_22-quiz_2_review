#include <iostream>
#include "Sample.h"

// 1.) Where in memory does this variable reside?
// 2.) What is the lifetime of this variable?
// 3.) What is the inital value of this variable?
int global_variable;

int main()
{

    // 1.) Where in memory does this variable reside?
    // 2.) What is the lifetime of this variable?
    // 3.) What is the inital value of this variable?
    int main_local;

    // HINT: I like to draw out boxes to represent
    // memory, you should too!
    //
    //    THE STACK                                  THE HEAP
    // ┌──────────────────────┐                ┌─────────────────────┐
    // │                      │                │                     │
    // │   ┌──────┐           │                │                     │
    // │   │STACK │           │                │                     │
    // │   │ VAR  │           │                │        ┌──────┐     │
    // │   └──────┘           │                │        │ HEAP │     │
    // │                      │                │        │ VAR  │     │
    // │                      │                │        │      │     │
    // │                      │                │        └──▲───┘     │
    // │                      │                │           │         │
    // │                      │                │           │         │
    // │        ┌───────┐     │                │           │         │
    // │        │       │     │                │           │         │
    // │        │ PTR   ├─────┼────────────────┼───────────┘         │
    // │        └───────┘     │                │                     │
    // └──────────────────────┘                └─────────────────────┘

    // 1.) Where in memory does s1 reside?
    // 2.) Where in memory does s1.int_pointer reside?
    // 3.) Where in memory does *(s1.int_pointer) reside?
    // 4.) Where in memory does s1.regular_int reside?
    Sample s1(1, -1);

    // 1.) Where in memory does s2 reside?
    // 1.5) What is the lifetime of s2?
    // 2.) What is the lifetime of the Sample object that s2 points to?
    // 2.) Where in memory does s2->int_pointer reside?
    // 3.) Where in memory does *(s2->int_pointer) reside?
    // 4.) Where in memory does s2.regular_int reside?
    Sample *s2 = new Sample(2, -2);

    // ======== LIST STUFF ==========

    // This is going to be less *code* and more *discuss/draw stuff* with
    // your group.

    // First, let's consider size complexity of array lists vs linked lists.
    // Assume that a char is 1 byte and a pointer is 4 bytes.
    // How large are:
    // 1.) An array of 10 characters?
    // 2.) A singly linked list of 5 characters?
    // 3.) A doubly linked list of 5 characters?

    //  ARRAY
    // ┌──┬──┬──┬──┬──┬──┬────────────────────────────┬──┬──┬──┬──┐
    // │  │  │  │  │  │  │                            │  │  │  │  │
    // │  │  │  │  │  │  │      .............         │  │  │  │  │
    // └──┴──┴──┴──┴──┴──┴────────────────────────────┴──┴──┴──┴──┘
    //
    //  NODE #1               NODE #2                    NODE #n
    // ┌──┬───────────┐     ┌──┬───────────┐          ┌──┬───────────┐
    // │  │           │     │  │           │          │  │           │
    // │  │           ├─────►  │           ├─►.... ──►│  │           ├───►NULL
    // └──┴───────────┘     └──┴───────────┘          └──┴───────────┘
    //
    //             NODE #1                                 NODE #n
    //        ┌───────────┬──┬───────────┐             ┌───────────┬──┬──────────┐
    //        │           │  │           │             │           │  │          │
    // NULL ◄─┤           │  │           ├──►..... ───►│           │  │          ├──►NULL
    //        └───────────┴──┴───────────┘             └───────────┴──┴──────────┘

    // Second, let's consider the work needed to GROW these list implementations.
    // Assume that the array is dynamically growable and is currently at capacity
    // of 10/10 characters.
    // What work needs to be performed to grow:
    // 1.) The array by 1 entry
    // 2.) The singly linked list by 1 entry (no tail pointer)
    // 3.) The singly linked list by 1 entry (with a tail pointer)
    // 4.) The doubly linked list by 1 entry (no tail pointer)
    // 5.) The doubly linked list by 1 entry (with a no tail pointer)

    //  NODE #1               NODE #2                    NODE #3
    // ┌──┬───────────┐     ┌──┬───────────┐          ┌──┬───────────┐
    // │  │           │     │  │           │          │  │           │
    // │  │           ├─────►  │           ├─►.... ──►│  │           ├───►NULL
    // └──┴───────────┘     └──┴───────────┘          └──┴───────────┘
    //                                                       ▲
    //  TAIL                                                 │
    // ┌──────────┐                                          │
    // │          │                                          │
    // │          ├──────────────────────────────────────────┘
    // └──────────┘

    // Thirdly, let's discuss LIFO stacks and FIFO queues.
    // LIFO = Last in, first out
    // FIFO = First in, first out
    // Neither of these structures operate on data in the MIDDLE of
    // the structure -- right? They are primarily concerned with what's
    // at the beginning or what's at the end.
    // Consider a singly linked list with a tail pointer.
    // What would be required to:
    // 1.) Add a node to the front
    // 2.) Add a node to the back
    // 3.) Remove a node from the front
    // 4.) Remove a node from the rear


    // Since we know that some operations are worse than others,
    // let's re-examine professor Lewis's explanation of LIFO/FIFO on
    // linked lists from 3/5.
    // Which side of the list should we operate on?
    // 1.) FIFO add/remove nodes to front or back? Why?
    // 2.) LIFO add/remove nodes to front or back? Why?

    // Here we can see the addresses of all the data associated
    // with s1 and s2. Do you notice any patterns?
    print_sample_addresses(s1);
    print_sample_addresses(s2);

    return 0;
}
