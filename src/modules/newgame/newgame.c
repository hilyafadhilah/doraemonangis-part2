#include <stdio.h>
#include "../../game_header.h"

#define enter printf("\n");
#define border printf("----------- END OF INFO CONFIG.TXT------------\n\n");

void startGame(Config newgame, boolean isNewGame) {

    /* INISIALISASI AWAL PERMAINAN */
    Matrix m;
    Player p;
    POINT loc;
    DaftarPesanan tempPsn = newgame.pesanans;
    Speedboost sb;
    Tas tas;
    Item item;
    Inventory invPlayer;
    TDList todo;
    Pesanan p1, p2;

    CreatePlayer(&p);    UANG(p) = 0;
    setPlayerLoc(&p, newgame.bangunans.buffer[0].position.X, newgame.bangunans.buffer[0].position.Y);
    resetSpeedboost(&sb);
    CreateTas(&tas);
    CreateInv(&invPlayer);
    CreateListTD(&todo);

    /* INISIALISASI MAP */
    readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2);
    showMap(&m,newgame.bangunans);

    /* UNTUK DEBUG MENAMPILKAN MAP */
    // enter;displayMatrix(newgame.adjMatrix);enter;
    // displayListPoint(newgame.bangunans);enter;

    /* Jika load game */
    if (!isNewGame) {
        printf("\n--- LOAD SAVE FILE ---\n");
        loadGame(&(newgame.pesanans), &p, &invPlayer, &tas, &todo, &sb);
    }

    /* COMMAND */
    printf("length pesanan %d", lengthDftr(newgame.pesanans));enter;
    printf("Waktu: %d\n", WAKTU(p));
    while (!isDone(todo,tas,newgame.pesanans,p,newgame.bangunans)){
        printf("\nENTER COMMAND: ");
        startWord(stdin);
        if (endWord) {
            if (wordEquals(currentWord, "MOVE")) {
                movecmd(&p, &newgame, &todo, &tas, &sb);
                printf("Waktu: %d", WAKTU(p));
            } else if (wordEquals(currentWord, "MAP")) {
                displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter;
            } else if (wordEquals(currentWord, "PICK_UP")) {
                pickupcmd(p, &newgame, &tas, &todo, &sb);
            } else if (wordEquals(currentWord, "DROP_OFF")) {
                dropoffcmd(&p, &newgame, &tas, &sb, &todo);
            } else if (wordEquals(currentWord, "IN_PROGRESS")) {
                DisplayInPrgs2(tas);
            } else if (wordEquals(currentWord, "TO_DO")) {
                DisplayListToDo(todo,WAKTU(p));
            } else if(wordEquals(currentWord, "BUY")){
                if(CUR_LOCX(p)==newgame.bangunans.buffer[0].position.X && CUR_LOCY(p)==newgame.bangunans.buffer[0].position.Y){
                    BuyGadget(&invPlayer,&UANG(p));
                }else{
                    printf("Kamu tidak berada di HQ\n");	
                }
            } else if(wordEquals(currentWord, "INVENTORY")) {
                printf("Uang yang dimiliki: %d\n",UANG(p));
                DisplayGadget(&invPlayer,&WAKTU(p),&tas,todo,tempPsn,&p, newgame.bangunans);

            } else if (wordEquals(currentWord, "SAVE_GAME")) {
                saveGame(p, invPlayer, tas, todo, sb);
            } else if (wordEquals(currentWord, "HELP")) {
                show_help();
            } else if (wordEquals(currentWord, "EXIT")) {
                printf("Kamu berhenti dari permainan, sampai jumpa!\n");
                break;
            }
            else {
                printf("WRONG INPUT\n");
            }
            // enter;displayMatrixLabel(m,newgame.adjMatrix,newgame.bangunans,p,tas,todo);enter;enter; // AUTO PRINT MAP BUAT DEBUG
        } else {
            ignoreWords();
        }
    }
    if (isDone(todo,tas,newgame.pesanans,p,newgame.bangunans)) {
        printf("Selamat kamu telah berhasil menyelesaikan permainan. \nJumlah item yang berhasil diantarkan: %d\nWaktu yang dilampaui: %d\n", PESANAN_DONE(p), WAKTU(p));
    }
}