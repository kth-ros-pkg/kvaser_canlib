#include <stdio.h>
#include <stdlib.h>
#include <canlib.h>
#include <iostream>



int main(int argc, char **argv)
{

  canHandle h, h2;

  h = canOpenChannel(0, canWANT_EXCLUSIVE |canWANT_EXTENDED);
  std::cout << h << std::endl;

  // canBusOff(h);
  // (void)canClose(h);

  h2 = canOpenChannel(0, canWANT_EXCLUSIVE |canWANT_EXTENDED);
  std::cout << h2 << std::endl;
  
  canBusOff(h);
  (void)canClose(h);

  canBusOff(h2);
  (void)canClose(h2);

  std::cout << h << std::endl;


  return 0;
}
