// tips.hpp

#ifndef TIPS_HPP
#define TIPS_HPP

#include <iostream>

namespace tips
{

// Display on one line of cout each element of a container
// text - optional text to display before the elements
//    (if there is text it will be followed by a colon and a space)
// element_separator - character(s) to put between the elements
//    (default is a space)

template <class T>
void print( const T& container, const char* text=0,
   const char* element_separator = " " )
{
   const char* text_separator = ": ";

   // if there's text, display it and some separator characters
   if( text != 0 )
      std::cout << text << text_separator;

   // store the end iterator, which doesn't change
   typename T::const_iterator container_end = container.end();

   // display each element followed by the element separator
   for( typename T::const_iterator i = container.begin();
      i != container_end; ++i )
      std::cout << *i << element_separator;

   std::cout << std::endl;
}

}  // end namespace
#endif
