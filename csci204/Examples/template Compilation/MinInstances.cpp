//: C05:MinInstances.cpp {O}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
#include "OurMin.cpp"

// Explicit Instantiations for int and double
template const int& Min<int>(const int&, const int&);
template const double& Min<double>(const double&,
                                   const double&);
///:~
