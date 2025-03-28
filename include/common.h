#ifndef COMMON_H
#define COMMON_H

namespace Sort {
    enum Type {
        Bubble = 1,
        Insertion,
        StdSort
    };
    
    enum Data {
        ByScore = 1,
        ByName,
        ByGroup
    };
    
    enum Order {
        Ascending = 1,
        Descending
    };
}

#endif // COMMON_H