//
//  Function_Arguments.c
//  Demonstrations
//

//  Copyright © 2018 apurva anand. All rights reserved.
//


 /* A more rigorous example of function arguments. */

int f1(int a, int b)
{
    int count;
    print("in f1");
    count = a; do {
        print(count);
    } while(count=count-1);
    print(a); print(b); print(a*b);
    return a*b;
}
int f2(int a, int x, int y) {
    print(a); print(x); print(x / a); print(y*x);
    return 0;
    
}
int main() {
    f2(10, f1(10, 20), 99);
    return 0;
    
}
