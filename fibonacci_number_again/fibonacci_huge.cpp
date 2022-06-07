#include <iostream>
#include <vector>

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;
    long long cur_iter = 2, cur = 1, prev = 0, len = 2, last_fib;
    std::vector<long long> fibonacci;
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    
    //std::cout << "Number:\n 0: 0\n1: 1\n";
    while(cur_iter < n) {
        long long prev_second = (long long)prev;
        prev = (long long)cur;
        cur = (prev_second % m + cur % m) % m;
        fibonacci.push_back(cur);
        //std::cout << cur_iter << ": "<< (long long)cur << "\n";

        //std::cout << divide << " ";
        if (((long long)prev == 0) && ((long long)cur == 1)) {
            //std::cout << "Exit " << last_fib <<" " << prev << " " << cur << "\n";
            len--;
            cur = fibonacci[n % len];
           break;
        }
        len++;
        cur_iter++;
        last_fib = (long long)prev;
    }
    //std::cout << "\nLen " << len << " " << last_fib <<" " << prev << " " << cur << "\n";
    return (long long)cur;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    //std::cout << previous << " " << current << " ";
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (long long)tmp_previous + current;
        //std::cout << current % m << " ";
    }

    return (long long)current % m;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    //n = (unsigned long long)2816213588;
    //n = 239;
    //std::cout << n << "\n";
    //m = 1000;
    std::cout << get_fibonacci_huge(n, m) << '\n';
    //std::cout << "F" << n % 238 << "\n";  
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';

}
