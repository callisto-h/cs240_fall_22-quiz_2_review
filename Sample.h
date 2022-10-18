#include <iostream>

class Sample{
    public:
        int *int_pointer;
        int regular_int;

        Sample(){
            int_pointer = nullptr;
            regular_int = 0;
        }

        Sample(int value1, int value2){
            int_pointer = new int(value1);
            regular_int = value2;
        }

        // THIS COPY CONSTRUCTOR DOES NOT WORK, FIX IT!
        // What could we change about this class
        // in order to not NEED this constructor?
        // ANSWER:
        // If we got rid of the heap storage (int_pointer)
        // then we would only need a shallow copy constructor,
        // which the compiler generates for us
        Sample(Sample const &s){
            // Why can we do this:
            regular_int = s.regular_int;
            // But not this:
            int_pointer = s.int_pointer;
        }

        // 1.) Where in memory do the "value" parameters reside?
        // 2.) What are the lifetimes of these variables?
        // 3.) What are the inital values of these variables?
        // ANSWER:
        // 1.) Stack memory
        // 2.) The lifetime of the "change_value" function
        // 3.) Whatever values are passed in to a "change_value()" call
        void change_value(int value1, int value2){
            regular_int = value2;
            if(int_pointer == nullptr){
                int_pointer = new int(value1);
                return;
            }
            *int_pointer = value1;
        }

        ~Sample(){
            delete int_pointer;
        }
};

void print_sample_addresses(Sample const &s){
    std::cout << "PRINTING s1 ADDRESS DATA ======================" << std::endl;
    std::cout << "Address of s1                : " << &s << std::endl;
    std::cout << "Address of s1.int_pointer    : " << &(s.int_pointer) << std::endl;
    std::cout << "Address of *(s1.int_pointer) : " << s.int_pointer << std::endl;
    std::cout << "Address of s1.regular_int    : " << &(s.regular_int) << std::endl;
}

void print_sample_addresses(Sample *s){
    std::cout << "PRINTING s2 ADDRESS DATA ======================" << std::endl;
    std::cout << "Address of s2                : " << &s << std::endl;
    std::cout << "Address of *s2               : " << s << std::endl;
    std::cout << "Address of s2->int_pointer   : " << &(s->int_pointer) << std::endl;
    std::cout << "Address of *(s2->int_pointer): " << s->int_pointer << std::endl;
    std::cout << "Address of s2->regular_int   : " << &(s->regular_int) << std::endl;
}
