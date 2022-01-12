#include "lib.h"
/*
  proc/cpuinfo  //info processeur
  "proc/rtc"
  proc/stat   //info utilisation du cpu
  proc/version  //systeme d'exploitation
  proc/uptime
  proc/net/
  proc/sys/net/
  proc/sys/kernel/version  //version du kernel
  proc/sys/kernel/hostname  //nom de la machine
  proc/meminfo   //RAM
  proc/key-users  //nom utilisateur??

  USER = ENV;


  time_t tm = time(0);
  ctime(&tm); // renvoie le tmp

*/

    #include <stdio.h>
#include <time.h>


int main (int argc, char *argv[], char **env)
{

  char *name;
  for (int i = 0; env[i] != NULL; i++)
    if (strncmp (env[i], "USER=", 5) == 0)
      name = &(env[i][5]);

  ModuleCore core (name);

  core.display ();

  ModuleRAM ram;
  return (0);
}
