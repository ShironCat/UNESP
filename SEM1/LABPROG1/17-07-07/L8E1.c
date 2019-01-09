#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int redondo(int a) {
    if(a == -1) {
        return 15;
    } else if(a == 16) {
        return 0;
    } else {
        return a;
    }
}

void main() {
    int B[15][15], i, j, n = 0;
    int N[15][15] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
    char op = 1;
    srand(time(NULL));
    for(i = 0; i < 15; i++) {
        for(j = 0; j < 15; j++) {
            B[i][j] = rand()%2;
        }
    }
    while(op != 27) {
        system("clear");
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                if(B[i][j] == 1) {
                    if(N[i][j] < 2) {
                        B[i][j] = 0;
                    } else if(N[i][j] > 3) {
                        B[i][j] = 0;
                    }
                } else if(N[i][j] == 3) B[i][j] = 1;
            }
        }
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                printf("%d", B[i][j]);
            }
            printf("\n");
        }
        for(i = 0; i < 15; i++) {
            for(j = 0; j < 15; j++) {
                if(B[redondo(i + 1)][redondo(j)] == 1) n++;
                if(B[redondo(i - 1)][redondo(j)] == 1) n++;
                if(B[redondo(i)][redondo(j + 1)] == 1) n++;
                if(B[redondo(i)][redondo(j - 1)] == 1) n++;
                if(B[redondo(i + 1)][redondo(j + 1)] == 1) n++;
                if(B[redondo(i + 1)][redondo(j - 1)] == 1) n++;
                if(B[redondo(i - 1)][redondo(j + 1)] == 1) n++;
                if(B[redondo(i - 1)][redondo(j - 1)] == 1) n++;
                N[i][j] = n;
                n = 0;
            }
        }
        printf("Presione qualquer tecla para ver a proxima geracao...\n(Pressione ESC para parar)\n");
        op = getch();
    }
}