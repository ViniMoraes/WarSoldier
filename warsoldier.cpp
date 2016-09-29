#include <allegro.h>
#include <iostream>

using namespace std;
////PROTOTIPO DA FUNCAO
void init();

//funcao que retorna valores inteiro
///MAIN
int main() {
    //chamando a funcao
	init();

    ///CARREGANDO BITMAPS
	//carregar uma imagem no Allegro
	BITMAP *soldado = load_bitmap("soldado.bmp",NULL);
	BITMAP *shot = load_bitmap("shot.bmp",NULL);
	BITMAP *zumbi = load_bitmap("zumbi.bmp",NULL);
	BITMAP *fundo1 = load_bitmap("fundo1.bmp",NULL);
	BITMAP *fundo = load_bitmap("fundo.bmp",NULL);
	BITMAP *menu2 = load_bitmap("menu2.bmp",NULL);
	BITMAP *creditos = load_bitmap("credits.bmp",NULL);
	BITMAP *fases = load_bitmap("stage.bmp",NULL);
	BITMAP *fases2 = load_bitmap("stage2.bmp",NULL);
	//criar tela auxiliar para o DOUBLE BUFFERING
	BITMAP *tela = create_bitmap(640,480);
	SAMPLE* doze = load_sample("doze.wav");
    MIDI* musica = load_midi("som.mid");
	//declarando as variaveis locais da main
	///VARIAVEIS LOCAIS
	int i=0;
	int za=0;
	int zb=0;
	int zx=0;
	int zy=0;
    int x = 0;
    int j = 0;
    int y = 0, vy = 0, vx = 5;
    int h = 2, l = 165, z = 340, w = 52;
    int pulou = 0, puloub = 0;
    int movimento  =0;
    int movimetozumbi=0;
    int menu = 0;
    int credits = 0;
    int pos_menu = 1;
    int pos_menu_aux=0;
    int px =0;
    int py =0;
    int pos_stagio = 1;


    //Segurando os textos na tela
    ///TELA INICIAL
     play_midi(musica,TRUE);
    while(menu == 0)
    {

        blit(tela, screen,0,0,0,0,640,480);
        blit(fundo, tela,x,0,0,0,1199,480);

        if(pos_menu == 1)
        {
            blit(menu2, tela,0,170,0,170,1199,50);

             if(key[KEY_ENTER])
             {
                  menu=1;
             }
        }

        ///TELA FASES
        if(pos_menu == 2)
        {

            blit(menu2, tela,0,220,0,220,1199,50);
            if(key[KEY_ENTER])
             {
                 while(!key[KEY_ESC])
                 {
                      blit(tela, screen,0,0,0,0,640,480);
                      blit(fases, tela,x,0,0,0,1199,480);

                      if(key[KEY_LEFT])
                      {
                          if(pos_menu_aux==0)
                          {


                            if(px<1 && py ==1)
                            {
                                px = 4;
                                py = 0;
                            }
                            else if(px < 1 && py==0)
                            {

                            }
                            else
                            {
                                px--;
                            }
                          pos_menu_aux=1;}
                      }

                      if (!(key[KEY_LEFT] || key[KEY_RIGHT]))
                      {
                           pos_menu_aux=0;
                      }
                      if(key[KEY_RIGHT])
                      {
                            if(pos_menu_aux==0)
                            {
                                if(px>3 && py ==0)
                                {
                                    px = 0;
                                    py = 1;
                                }
                                else if(px > 3 && py==1)
                                {

                                }
                                else
                                {
                                    px++;
                                }

                                pos_menu_aux=1;
                            }
                     }

                     blit(fases, tela,0,0,0,0,1199,480);
                     blit(fases2, tela,45+110*px,55+170*py,45+110*px,55+170*py,95,95);

                    cout << py*5+px+1 << "\n";
                    if(px == 1)
                    {
                        if(key[KEY_ENTER])
                        {
                            menu=1;
                        }
                    }

                    switch(py*5+px+1)
                    {
                    case 1:

                        break;
                    }
                 }
             }
        }

        ///TELA CREDITOS
        if(pos_menu == 3)
        {
            blit(menu2, tela,0,270,0,270,1199,50);

            if(key[KEY_ENTER])
             {

                 while(!key[KEY_ESC])
                 {
                      blit(tela, screen,0,0,0,0,640,480);
                      blit(creditos, tela,x,0,0,0,1199,480);
                 }
             }
        }

        if(key[KEY_UP])
        {
            if(pos_menu_aux == 0)
            {
                if(pos_menu<=1)
                {
                    pos_menu=1;
                }
                else
                {
                    pos_menu--;
                }
                pos_menu_aux=1;
            }
        }
        if(key[KEY_DOWN])
        {
            if(pos_menu_aux == 0)
            {
                if(pos_menu>=3)
                {
                    pos_menu=3;
                }
                else
                {
                    pos_menu++;
                }
                pos_menu_aux=1;
            }
        }
        if (!(key[KEY_UP] || key[KEY_DOWN]))
        {
            pos_menu_aux=0;
        }
        //textout_centre_ex(tela,font,"BEM VINDO!!",SCREEN_W/2,SCREEN_H/2-50,makecol(185,0,0),-1);
        //textout_centre_ex(tela,font,"Aperte ENTER para COMECAR",SCREEN_W/2,SCREEN_H/2,makecol(185,0,0),-1);
    }
        ///TELA DO JOGO
    	while (!key[KEY_ESC]) {

		//colocando a imagem na janela de visualização
		blit(fundo1, tela,x,0,0,0,1199,480);

		//colocando o soldado na janela de visualização
		masked_blit(soldado,tela,0+i*65,0+j*78,x,350-y,65,78);
		//colocando o zumbi na janela de vizualozação
		masked_blit(zumbi,tela,0+za*156,0+zb*200,zx+500,250-zy,156,200);




		//contando as imagens do sprite em coluna
		if (movimento == 1)
        {
                i =  i + 1;
        }


        za = za+1;

        if(movimetozumbi == 1)
        {

            if(za>11)
            {
                movimetozumbi = 0;
                zx = 500;
            }
        }
        else
        {
            if(za>3)
            {
                za=0;
            }
                 zx = zx-5;
        }




        if(key[KEY_B])
            {

                masked_blit(shot,tela,i*1,y,x+60,375-y,43,58);
                play_sample(doze,255,128,1000,FALSE);
                movimetozumbi = 1;
            }





		//ao acionar o pulo quando y for menor que 0, retorna o sprite para y = 0, retorna o pulo para antes de ser acionado
        // e retorna a velocidade x de 10 para 5.
         if(pulou == 1 && y >= 0)
        {
              //calculo da velocidade na vertical
              vy = vy - 10;
              y = y + vy;
        }

        if(pulou == 1 && y < 0)
        {
             y = 0;
             pulou = 0;
             vx = 5;
        }

        //quantidade de posições do sprite na coluna i = 0
        if(i > 4)
        {
            i = 0;
        }
        //parar contagem de troca de imagens
        if((!key[KEY_RIGHT])&&(!key[KEY_LEFT]))
        {
            j=0;
            movimento = 0;
            i = 0;
        }
        else{movimento =1;}

        if(key[KEY_RIGHT] && x < (1195-640))
        {
            //determina a linha do sprite (ASH ANDANDO PRA DIREITA NO BMP)
            j = 3;
            //determina a direção da animação (DIREITA)
            x = x + vx;
        }

        //andando para a esquerda
        if(key[KEY_LEFT] && x > 5)
        {
            //determina a linha do sprite (ASH ANDANDO PRA ESQUERDA NO BMP)
            j = 1;
            //determina a direção da animação (ESQUERDA)
            x = x - vx;
        }

        if(key[KEY_UP])
        {
            //determina a linha do sprite (ASH ANDANDO PRA ESQUERDA NO BMP)
            j = 2;
            //determina a direção da animação (ESQUERDA)
            //x = x - vx;
        }

        if(key[KEY_DOWN])
        {
            //determina a linha do sprite (ASH ANDANDO PRA ESQUERDA NO BMP)
            j = 0;
            //determina a direção da animação (ESQUERDA)
            //x = x - vx;
        }

        //altera o valor da variável  pulo de 0 pra 1 da velocidade y de 0 pra 50 e velocidade x de 5 pra 10
        // determinando o impulso
        if(key[KEY_SPACE] && pulou == 0)
        {
             pulou = 1;
             vy = 45;
             vx = 10;
        }

        //quando chega ao final da tela retorna para o começo
        //andando em circulo para a direita
        if(x > 1199)
        {
            x = 0;
        }

        //quando chega ao final da tela retorna para o começo
        //andando em circulo para a esquerda
        if(x < 0)
        {
             x = 1195;
        }

	    //colocar a tela auxiliar na janela de visualisação
		blit(tela, screen,0,0,0,0,640,480);
		//descanso da animação
        rest(50);

        // limpa para nova cena.
		clear(tela);

	}
    destroy_sample(doze);

	return 0;
}
END_OF_MAIN()

//definido a funcao
void init() {
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	install_timer();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	install_keyboard();



	/* add other initializations here */
}

