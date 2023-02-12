#include <iostream>

using namespace std;

char* array_chars_to_lowercase(char* input_char_arr)
{

    for (int x=0; x<strlen(input_char_arr); x++)
        input_char_arr[x] = char(tolower(input_char_arr[x]));
    return input_char_arr;

}
