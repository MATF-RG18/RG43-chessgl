#include "Game.hpp"

Game::Game() {}

void Game::init(){

    /* Inicijalizacija svetala */
    light.enable();
    light.draw();
    
    /* Inicijalizacija polja i same table*/
    board.init(fields);

    /* Inicijalizacija figura*/
    init_pieces();
    
    /* Ucitavanje modela figura*/

    /*  NAPOMENA: Zbog velikog broja figura ucitavanje modela(na mojoj masini) 
        traje predugo(preko 30sekundi) tokom kojim je program zamrznut
        pa se zato ne koriste stvarni modeli vec improvizovane figure
    */ 

    /* Top */
    // pieces[0].objHandler.prepFile("./models/rook/rook.obj");
    // pieces[0].objHandler.loadModel();
    
    /* Konj */
    // pieces[1].objHandler.prepFile("./models/knight/knight.obj");
    // pieces[1].objHandler.loadModel();

    /* Lovac*/
    // pieces[2].objHandler.prepFile("./models/bishop/bishop.obj");
    // pieces[2].objHandler.loadModel();

    /* Dama */
    // pieces[3].objHandler.prepFile("./models/queen/queen.obj");
    // pieces[3].objHandler.loadModel();

    /* Kralj */
    // pieces[4].objHandler.prepFile("./models/king/king.obj");
    // pieces[4].objHandler.loadModel();

    /* Lovac */ 
    // pieces[5].objHandler.prepFile("./models/bishop/bishop.obj");
    // pieces[5].objHandler.loadModel();

    /* Konj */
    // pieces[6].objHandler.prepFile("./models/knight/knight.obj");
    // pieces[6].objHandler.loadModel();

    /* Top */
    // pieces[7].objHandler.prepFile("./models/rook/rook.obj");
    // pieces[7].objHandler.loadModel();

    /* Pijuni */
    // for(int i=8;i<24; i++){
        // pieces[i].objHandler.prepFile("./models/pawn/pawn.obj");
        // pieces[i].objHandler.loadModel();
    // }


    /* Top */
    // pieces[24].objHandler.prepFile("./models/rook/rook.obj");
    // pieces[24].objHandler.loadModel();

    /* Konj */
    // pieces[25].objHandler.prepFile("./models/knight/knight.obj");
    // pieces[25].objHandler.loadModel();

    /* Lovac*/
    // pieces[26].objHandler.prepFile("./models/bishop/bishop.obj");
    // pieces[26].objHandler.loadModel();

    /* Kralj */
    // pieces[27].objHandler.prepFile("./models/king/king.obj");
    // pieces[27].objHandler.loadModel();

    /* Dama */
    // pieces[28].objHandler.prepFile("./models/queen/queen.obj");
    // pieces[28].objHandler.loadModel();

    /* Lovac */ 
    // pieces[29].objHandler.prepFile("./models/bishop/bishop.obj");
    // pieces[29].objHandler.loadModel();

    /* Konj */
    // pieces[30].objHandler.prepFile("./models/knight/knight.obj");
    // pieces[30].objHandler.loadModel();

    /* Top */
    // pieces[31].objHandler.prepFile("./models/rook/rook.obj");
    // pieces[31].objHandler.loadModel();
   
}


void Game::draw(){
    
    /* Ukljucivanje i postavljanje kamere*/
    camera.init(); 
    
    /* Iscrtavnje table i okvira*/
    board.draw(fields);

    /* Iscrtavanje figura*/
    for(auto e : pieces){
        e.draw();
    }

    glutSwapBuffers();
}


void Game::init_pieces(){

    int br = 0;

    for(int i=0; i<=1; i++){
        for(int j=0; j<=7; j++){
            pieces[br].rank = i;
            pieces[br].column = j;
            pieces[br].color = COLOR_WHITE;
            pieces[br].x = i*FIELD_SIZE + FIELD_SIZE;
            pieces[br].y = j*FIELD_SIZE + FIELD_SIZE;
            pieces[br].z = 1;
        
            br+=1;
        }
    }

    for(int i=6; i<=7; i++){
        for(int j=0; j<=7; j++){
            pieces[br].rank = i;
            pieces[br].column = j;
            pieces[br].color = COLOR_BLACK;
            pieces[br].x = i*FIELD_SIZE + FIELD_SIZE;
            pieces[br].y = j*FIELD_SIZE + FIELD_SIZE;
            pieces[br].z = 1;
            br++;
        }
    }
}
