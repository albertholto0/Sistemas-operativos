// cambia_eco.h
// Commuta el modo eco / no eco del terminal
///////////////////////////////////////////////////////////

#include <unistd.h>
#include <termios.h>
//#include <sys/ioctl.h>

int main ()
{
        int r;
        struct termios tm;

        tcgetattr(0, &tm);
        if (tm.c_lflag & ECHO) {
                r= 1;
                tm.c_lflag &= ~ECHO;
        }
        else {
                r= 0;
                tm.c_lflag |= ECHO;
        }
        tcsetattr(0, TCSANOW, &tm);
        return (r);
}
