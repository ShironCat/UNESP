#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

static struct termios old, new;

void initTermios(int echo) {
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

void resetTermios(void) {
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char getch(void) {
    return getch_(0);
}

char getche(void) {
    return getch_(1);
}

void main() {
    int i, j, p[2] = {1, 2}, g[2] = {3, 2};
    char mov;
    int M[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    while(p[0] != g[0] || p[1] != g[1]) {
        system("clear");
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 10; j++) {
                if(j == p[0] && i == p[1]) {
                    printf("&");
                } else if(j == g[0] && i == g[1]) {
                    printf("$");
                } else {
                    printf("%s", (M[i][j] == 1) ? "*" : " ");
                }
            }
            printf("\n");
        }
        mov = getch();
        if(mov == 'w') {
            if(M[(p[0])][(p[1] - 1)] == 0) p[1] -= 1;
        } else if(mov == 's') {
            if(M[(p[0])][(p[1] + 1)] == 0) p[1] += 1;
        } else if(mov == 'a') {
            if(M[(p[0] - 1)][(p[1])] == 0) p[0] -= 1;
        } else if(mov == 'd') {
            if(M[(p[0] + 1)][(p[1])] == 0) p[0] += 1;
        }
    }
}