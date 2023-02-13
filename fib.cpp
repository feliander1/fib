#include <iostream>
#include <cstring>

using namespace std;

#include "fib_n.cpp"
#include "fib_log_n.cpp"
#include "utils.cpp"
#include "tests.cpp"

int main(int argc, char** argv)
{

    if ((argc == 2) && (strcmp(argv[1], "--help") == 0)) {
        cout << endl
             << "--test for launch tests" << "\n"
             << "-n fibonacci number expected" << "\n"
             << "-a algorythm difficulty N or LogN" << "\n"
             << endl
             << "example: fib -n 10 -a N" << "\n"
             << endl;
        return 0;
    }

    if ((argc == 2) && (strcmp(argv[1], "--test") == 0)) {
        cout << endl
             << "launch tests" << "\n"
             << endl;
        check_fib_n();
        check_fib_log_n();
        return 0;
    }
    
    int fib_num;
    char* diff = "";
    if (argc == 5) {
        for (int i = 0; i < argc; ++i)
            if (strcmp(argv[i], "-n") == 0 ) {
                fib_num = atoi(argv[i + 1]);
            }
            else if (strcmp(argv[i], "-a") == 0 ) {
                diff = argv[i + 1];
            }
    }
    
    if ((diff[0] != '\0') && strcmp(array_chars_to_lowercase(diff), "n") == 0) {
        cout << endl
             << "start calculating fibonacci number "
             << fib_num
             << " with difficulty "
             << diff << "\n"
             << endl;
        clock_t tStart = clock();
        BigInt Result;
        Result = getNthFibNum(fib_num);
        cout << "fib value = " << Result << "\n"
             << endl
             << "it takes " << clock() - tStart << " clicks or\n"
             << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds\n"
             << endl;
        return 0;
    }
    
    if ((diff[0] != '\0') && strcmp(array_chars_to_lowercase(diff), "logn") == 0) {
        cout << endl
             << "start calculating fibonacci number "
             << fib_num
             << " with difficulty "
             << diff << "\n"
             << endl;
        clock_t tStart = clock();
        int result = fib_n_log_func(fib_num);
        cout << "fib value = " << result << "\n"
             << endl
             << "it takes " << clock() - tStart << " clicks or\n"
             << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds\n"
             << endl;
        return 0;
    }
    
    cout << endl
            << "bad arguments" << "\n"
            << endl
            << "--help for more info" << "\n"
            << endl;
  
    return 0;
}
