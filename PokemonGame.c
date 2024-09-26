#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

enum sekil { daire = 1, kare = 2, dikdortgen = 3 };
#define maxLength 10
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

int SetColor(int color) {
    if (color >= 0 && color <= 1000) {
        return color % 5;
    } else {
        return 1; 
    }
}

void dairealan() {
    double uzunluk;
    const double pi = 3.14;

    do {    
        printf("\nBir uzunluk giriniz: ");
        scanf("%lf", &uzunluk);
    } while (uzunluk <= 0 || uzunluk > maxLength);

    for (int y = uzunluk; y >= -uzunluk; y--) {   
        for (int x = -uzunluk; x <= uzunluk; x++) {
            if (round(sqrt(x * x + y * y)) == uzunluk) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void karealan() {
    double uzunluk;

    do {    
        printf("\nBir uzunluk giriniz: ");
        scanf("%lf", &uzunluk);
    } while (uzunluk <= 0 || uzunluk > maxLength);
    
    for (int i = 0; i < uzunluk; i++) {  
        for (int j = 0; j < uzunluk; j++) {
            printf("X");
        }
        printf("\n");
    }
}

void dikdortgenalan() {
    double kisakenar, uzunkenar;

    do {    
        printf("\nKisa kenari giriniz: ");
        scanf("%lf", &kisakenar);
        printf("\nUzun kenari giriniz: ");
        scanf("%lf", &uzunkenar);
    } while (uzunkenar <= 0 || uzunkenar > maxLength || uzunkenar < kisakenar || kisakenar <= 0 || kisakenar > maxLength);

    for (int i = 0; i < kisakenar; i++) {  
        for (int j = 0; j < uzunkenar; j++) {
            printf("X");
        }
        printf("\n");
    }
}

int CreateBody(double *body_size) {
    int shape;
    do {
        printf("\nHangi sekli olusturmak istiyorsun. (1. daire - 2. kare - 3. dikdortgen): ");
        scanf("%d", &shape);
    } while (shape < 1 || shape > 3);
    
    if (shape == 1) {
        dairealan();
        *body_size = 1;
        printf("Name : Daire Pokemon\n");
    } else if (shape == 2) {
        karealan();
        *body_size = 2; 
        printf("Name : Kare Pokemon\n");
    } else if (shape == 3) {
        dikdortgenalan();
        *body_size = 3; 
        printf("Name : Dikdortgen Pokemon\n");
    }
    return shape; 
}

double LoadMoves(int shape, double body_size) {
    double move_length = 0;
    const double pi = 3.14;
    if (shape == 1) {
        move_length = 2 * pi * body_size;
    } else if (shape == 2) {
        move_length = 4 * body_size;
    } else if (shape == 3) {
        double a = 5; 
        double b = body_size; 
        move_length = 2 * (a + b);
    }
    return move_length;
}

int SetAttackPower(int lower_bound, int upper_bound) {
    int attack_power;
    srand(time(0));
    attack_power = (rand() % (upper_bound)) + lower_bound; 
    return attack_power;
}

int main() {
    int shape, color, attack_power;
    double size_of_body, move_length;

    shape = CreateBody(&size_of_body);
    printf("Renk girisi yapiniz: ");
    scanf("%d", &color);
    
    color = SetColor(color); 
    move_length = LoadMoves(shape, size_of_body);
    printf("Hareket: %.2f\n", move_length);
    size_of_body = LoadMoves(shape, move_length);
    printf("Buyukluk: %.2f\n", size_of_body);
    attack_power = SetAttackPower(0, 150);
    printf("Saldiri gucunuz: %d\n", attack_power);

    switch (color) { 
        case RED:
            printf("Renk: Kirmizi\n");
            break;
        case YELLOW:
            printf("Renk: Sari\n");
            break;
        case BLUE:
            printf("Renk: Mavi\n");
            break;
        case BLACK:
            printf("Renk: Siyah\n");
            break;
        case WHITE:
            printf("Renk: Beyaz\n");
            break;
        default:
            printf("Hatali giris\n");
            break;
    }  
    return 0;
}
