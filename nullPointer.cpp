#include <iostream>
#include <memory>

int main()
{
     int *ptr = nullptr;
     if (ptr == nullptr)
     {
          std::cout << "Pointer is null." << std::endl;
     }
     // Safe usage
     std::unique_ptr<int> uptr = std::make_unique<int>(42);
     std::cout << "Value: " << *uptr << std::endl;
     std::shared_ptr<int> sptr = std::make_shared<int>(24);
     std::cout << "Shared value: " << *sptr << std::endl;
     // Null check
     int *raw = new int(10);
     if (raw)
     {
          std::cout << "Raw pointer value: " << *raw << std::endl;
          delete raw;
     }
     return 0;
}