#pragma once

typedef unsigned int uint;

#define EQUALS_OPERATOR(X) (X& operator= (X&& other);)
#define COPY_CONSTRUCTOR(X) (X& X(X&& other);)
#define EQUALS2X_OPERATOR(X) (X& operator== (X&& other);)

#define COPY_EQUALS_FUNC(X) (\
    EQUALS_OPERATOR(X)\
    COPY_CONSTRUCTOR(X)\
)
#define COPY_EQUALS_EQUALS2X(X) (\
    EQUALS_X2_OPERATOR(X)\
    EQUALS_OPERATOR(X)\
    COPY_CONSTRUCTOR(X)\
)


//template<typename T>
//struct Ret
//{
//    T item;
//    std::string err;
//    uint errorcode;
//};