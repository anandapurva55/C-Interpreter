//
//  Recursive_Functions.c
//  Demonstrations
//

//  Copyright © 2018 apurva anand. All rights reserved.
//

/* This program demonstrates recursive functions. */
/* return the factorial of i */


int factr(int i)
{
    if(i<2) { return 1;
    }
    else {
        return i * factr(i-1);
        
    }
}
int main() {
    print("Factorial of 4 is: ");
          print(factr(4));
          return 0;
    
}
