#include <stdexcept>

int fibonacci(int n)
{
  if (n < 0)
  {
    throw std::invalid_argument("Index cannot be negative");
  }
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}