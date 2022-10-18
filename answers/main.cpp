#include <iostream>
#include "Sample.h"

// 1.) Where in memory does this variable reside?
// 2.) What is the lifetime of this variable?
// 3.) What is the inital value of this variable?
// ANSWER:
// 1.) Neither the stack or the heap! Global variables like
//     global_variable are stored in the data section of an
//     executable file... If asked on a quiz, aim for an answer
//     like that or "static memory".
// 2.) The lifetime of the program
// 3.) Global variables are initialized to 0
int global_variable;

int main(){

    // 1.) Where in memory does this variable reside?
    // 2.) What is the lifetime of this variable?
    // 3.) What is the inital value of this variable?
    // ANSWER:
    // 1.) Stack memory
    // 2.) The function which it is declared in
    // 3.) For our purposes, it is random.
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
    // ANSWER:
    // 1.) s1 is a local/automatic variable, so it resides
    //     on the stack.
    // 2.) Per #1, s1 is on the stack. This means that memory
    //     on the stack has been reserved for all of s1's
    //     variables. So int_pointer is on the stack.
    // 3.) int_pointer is a pointer, and it points to a value
    //     that was returned with "new", meaning it is on the heap.
    // 4.) The stack, same justification as #2.
    //
    //      STACK MEMORY                  HEAP MEMORY
    // ┌───────────────────────┐     ┌────────────────────┐
    // │                       │     │                    │
    // │                       │     │                    │
    // │                       │     │                    │
    // │  ┌────────────────┐   │     │                    │
    // │  │ Sample s1      │   │     │                    │
    // │  │ ┌───────────┐  │   │     │        ┌───┐       │
    // │  │ │int_pointer├──┼───┼─────┼───────►│ 1 │       │
    // │  │ └───────────┘  │   │     │        └───┘       │
    // │  │                │   │     │                    │
    // │  │                │   │     │                    │
    // │  │ ┌───────────┐  │   │     │                    │
    // │  │ │regular_int│  │   │     │                    │
    // │  │ └───────────┘  │   │     │                    │
    // │  │                │   │     │                    │
    // │  └────────────────┘   │     │                    │
    // │                       │     │                    │
    // └───────────────────────┘     └────────────────────┘
    Sample s1(1, -1);


    // 1.) Where in memory does s2 reside?
    // 1.5) What is the lifetime of s2?
    // 2.) What is the lifetime of the Sample object that s2 points to?
    // 2.) Where in memory does s2->int_pointer reside?
    // 3.) Where in memory does *(s2->int_pointer) reside?
    // 4.) Where in memory does s2.regular_int reside?
    // ANSWER:
    // 1.) This is tricky! The pointer s2 resides on the stack
    //     even though the data that it points to is on the heap.
    // 1.5) Since s2 is on the stack, its lifetime is the main function.
    // 2.) From when "new" gets called to when "delete" gets called
    // 3.) Since the Sample that s2 points to is on the heap,
    //     all of its member variables are on the heap as well.
    // 4.) s2->int_pointer is a pointer (on the heap) that points
    //     to another location the heap! So *(s2->int_pointer) is
    //     on the heap as well.
    // 5.) The heap, same justification as #2.
    //
    //       STACK MEMORY              HEAP MEMORY
    // ┌───────────────────────┐    ┌────────────────────────┐
    // │                       │    │                        │
    // │                       │    │                        │
    // │                       │    │                        │
    // │                       │    │           ┌─────┐      │
    // │                       │    │           │  2  │      │
    // │                       │    │           └──▲──┘      │
    // │                       │    │              │         │
    // │                       │    │  ┌───────────┼─────┐   │
    // │                       │    │  │ Sample    │     │   │
    // │                       │    │  │           │     │   │
    // │                       │    │  │ ┌─────────┴───┐ │   │
    // │                       │    │  │ │ int_pointer │ │   │
    // │     ┌────────┐        │    │  │ └─────────────┘ │   │
    // │     │        │        │    │  │                 │   │
    // │     │  s2    ├────────┼────┼──►                 │   │
    // │     │        │        │    │  │                 │   │
    // │     └────────┘        │    │  │ ┌─────────────┐ │   │
    // │                       │    │  │ │ regular_int │ │   │
    // │                       │    │  │ └─────────────┘ │   │
    // │                       │    │  │                 │   │
    // │                       │    │  └─────────────────┘   │
    // │                       │    │                        │
    // └───────────────────────┘    └────────────────────────┘
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
    // ANSWER:
    // 1.) It's a clean 10 bytes. Arrays don't have an overhead.
    // 2.) Each node has 1 character and 1 pointer, so 5 bytes. 5 nodes = 25 bytes
    // 3.) Each node has 1 character and 2 pointers, so 9 bytes. 5 nodes = 45 bytes
    //
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
    // ANSWER:
    // 1.) We would need to copy every existing data point
    //     from our array to a new, slightly larger array.
    //     That's 10 copies for a size 10 array, or 100 for
    //     a size 100 array!
    // 2.) We would need to iterate through our entire linked
    //     list and then add one at the end. We don't need
    //     to copy anything, but that's still 5 visits
    //     for a list of 5 nodes, or 50 visits for 50 nodes!
    // 3.) We just go to the end and add a new node. This takes
    //     tht same amount of time, regardless of size.
    // 4.) Same as #2
    // 5.) Same as #3
    //
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
    // ANSWER:
    // Note: Some of these operations require a specific order
    //       of maintaining and deleting nodes which I ignore
    //       in favor of simple explanations
    // 1.) Make a new node, have it point to the old "head"
    // 2.) Make a new node, have the old "tail" point to it
    // 3.) Get rid of the old "head", have the #2 node become head
    // 4.) Iterate over the entire list to get the 2nd to last node,
    //     have it point to null (to become the last node), and
    //     get rid of the old "tail"
    // Since we know that some operations are worse than others,
    // let's re-examine professor Lewis's explanation of LIFO/FIFO on
    // linked lists from 3/5.
    // Which side of the list should we operate on?
    // 1.) FIFO add/remove nodes to front or back? Why?
    // 2.) LIFO add/remove nodes to front or back? Why?
    // ANSWER:
    // 1.) FIFO queues add and remove nodes from opposite ends of
    //     the list from one another. Since we know that we want
    //     to avoid removing from the end, and we have to add from
    //     wherever we don't remove, we add at the end and remove
    //     from the front.
    // 2.) LIFO queues add and remove nodes from the same end of
    //     the list. Since We want to avoid removing from the end,
    //     we and and remove from the front of the list.


    // Here we can see the addresses of all the data associated
    // with s1 and s2. Do you notice any patterns?
    print_sample_addresses(s1);
    print_sample_addresses(s2);

    return 0;
}
