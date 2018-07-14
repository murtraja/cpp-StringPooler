#define _USE_TRACER

#ifdef _USE_TRACER
#include <iostream>
#define TRACETHIS std::cout<<__PRETTY_FUNCTION__<<std::endl;
#else
#define TRACETHIS
#endif // _USE_TRACER