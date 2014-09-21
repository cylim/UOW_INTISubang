#include <iostream>
#include <exception>
using namespace std;
#include <stdexcept>
using std::runtime_error;

void function3() throw ( runtime_error ){
   throw runtime_error( "runtime_error in function3" );
} // end function function3
void function2() throw ( runtime_error ){
   function3();
} // end function function2
void function1() throw ( runtime_error ){
   function2();
} // end function function1
int main(){
   try {
      function1();
   } // end try
   catch ( runtime_error e )
   {
      cout << "Exception occurred: " << e.what() << endl;
   } // end catch

   return 0;
} // end function main
