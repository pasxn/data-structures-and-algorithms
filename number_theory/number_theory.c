/*
is any number, k a power of c:

c^n = k
log(c^n) = log(k)

n = lig(k)/log(C)

is n integer???
*/

/*
Greatest common devisor

- Naive approach
- Euclid algorithm
- Extended Euclid algorithm
- Stein's algorithm
*/

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

// Naive approach 
int naive_gcd(int a, int b) {
    int min = MIN(a, b);
    int gcd = 1;
    for(int i = min ; i>0;  --i) {
        if(a%i == 0 && b%i == 0) {
            gcd = i;
            break;
        }
    }  
    return gcd;
}

// Euclid algorithm
int euclid_gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return(b, a%b);
}

/*
Least common multiplier

- Naive approach
- Euclid algorithm
- Extended Euclid algorithm
- Stein's algorithm
*/

int naive_lcm(int a, int b) {
    int lcm = MAX(a, b);
    while(1) {
        if(lcm%a == 0 && lcm%b == 0) {
            return lcm;
        }
        lcm++;    
    }

    return lcm;
}

int lcm_gcd(int a, int b) {
    return a*b/euclid(a, b);
}