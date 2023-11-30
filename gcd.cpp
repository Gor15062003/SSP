
#include <iostream>

int gcd(int a, int b)
{
   while (b)
   {
	   int t = a;
	   a = b;
	   b = t % a;
   }
   return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main() {
	int a, b;
	std::cout << "Input a:";
	std::cin >> a;
	std::cout << "Input b:";
	std::cin >> b;
	std::cout << "GCD is " << gcd(a, b) << std::endl;
	std::cout << "LCM is " << lcm(a, b) << std::endl;
	return 0;
}

