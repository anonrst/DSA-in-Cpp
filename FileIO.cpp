#include <iostream>
typedef unsigned char BITE;
int main(int argc, char *argv[])
{
     BITE b;
     FILE *src = fopen(argv[1], "rb");
     FILE *dst = fopen(argv[2], "wb");

     while (fread(&b, sizeof(b), 1, src) != 0)
     {
          fwrite(&b, sizeof(b), 1, dst);
     }
     std::cout << "programme: " << argv[0] << "complete\n";
     fclose(src);
     fclose(dst);
     return 0;
}