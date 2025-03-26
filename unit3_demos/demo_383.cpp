#include <string>
#include <iostream>

class NamePrinter{

public:
    std::string name = "Felix";
    // HERE READ COMMENTS
    void print_name(){ //removed static from this line
        // here we use the this pointer
        // inside an static member funtion 
        std::cout << this->name << std::endl; // will return error if method is static
    }
};

int main(void) {
   // create an object
   NamePrinter p;
   p.print_name();
   return 0;
}