#include "../inc/libmx.h"

int mx_sqrt(int x) {

    if(x < 0) return 0;
    if(x == 1) return 1;
    int left  = 0;
    int right = x/2 + 1;
    int middle;
    if(right > 46340) right = 46341;
    while(left <= right){
        middle = (right - left)/2 + left;
        if(middle * middle == x)
            return middle;
        else if(middle * middle > x)
            right = middle;
        else
            left = middle;
        if(left + 1 == right)
            return 0;
    }
    return 0;
}
