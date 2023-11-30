
#include <iostream>
#include <string>

int main()
{
    std::string line = "WWWWWWWWWWWWWBBBBWWWWBWWBBBBBBBBW";
    int count = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == line[i + 1])
        {
            count++;
        }
        else
        {
            std::cout << count << line[i];
            count = 1;
        }
    }
    return 0;
}
