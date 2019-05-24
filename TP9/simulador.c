/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "funbits.h"

enum states {INIT, NEG, TURNON, TURNOFF, QUIT, ERROR};

static void turn_on(void);
static void turn_off(void);
static void negate(void);
static void printLeds(void);
static void cleanBuffer(void);

void simulate(void){
    char input = '0';
    int state = INIT;
    while(state != QUIT){
        switch(state){
            case INIT:
                input = getchar();
                if(input == 'c'){
                    state = TURNOFF;
                }
               else if(input == 's'){
                    state = TURNON;
                }
                else if(input == 't'){
                 state = NEG;
                }
                else if(input == 'q'){
                    state = QUIT;
                }
                else{
                    state = ERROR;
                }
                cleanBuffer();
                break;
            case TURNOFF:
                turn_off();
                break;
            case TURNON:
                turn_on();
                break;
            case NEG:
                negate();
                break;
            case QUIT:
                break;
            default:    printf("Operacion invalida!\n");    break;
        }
        printLeds();
    }
    printf("Fin de la simulacion\n");
    cleanBuffer();
    return;
}

static void turn_on(void){
    printf("Turn on!\n");
    return;
}

static void turn_off(void){
    printf("Turn off!\n");
    return;
}
static void negate(void){
    printf("Negate!\n");
    return;
}
static void printLeds(void){
    printf("Print Leds!\n");
    return;
}

static void cleanBuffer(void){
    while(getchar() != '\n'){}
    return;
}