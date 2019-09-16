/*

                   |---|  |--\  |---  |\   |  /---\  |
                   |   |  |__|  |___  | \  |  |      |
                   |   |  |     |     |  \ |  |  -+- |
                   \---/  |     |---  |   \|  \---|  \----

                            Aula 01 - OpenGl: Janelas  

 PrimeiroPrograma - Prof. Leandro Alves Neves
 Um programa OpenGL simples que abre uma janela GLUT
 Este código está baseado no Simple.c, exemplo 
 disponível no livro "OpenGL SuperBible" e "OpenGl: uma abordagem prática e objetiva" , 
 2nd Edition, de Richard S. e Wright Jr.*/

#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

void DISPLAY ();

// Inicializa parâmetros de rendering
void DISPLAY ()
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1, 0, 0, 0);
    glMatrixMode(GL_PROJECTION); //Ativa matriz de projeção
    glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.    
    gluOrtho2D(-200,200,-200,200);//Define tipo de projeção (2D) e o tamanho
    glMatrixMode(GL_MODELVIEW);//Ativa matriz de visualização
	glLoadIdentity();//"Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.
	//Limpa a janela de visualização com a cor de fundo especificada
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combinações de buffers, 
                                                         onde buffer é uma área de armazenamento para informações da imagem. 
                                                        Nesse caso, está "limpando os buffers para suportarem animações */
   //Chamada para Função  ou funções para desenhar o objeto/cena...
   //----------------------------------------------------------------
    glutSwapBuffers();
    
}

int main(int argc,char **argv)
{
   glutInit(&argc, argv); // Initializes glut
    
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   /*Avisa a GLUT que modo de exibição deve ser usado quando a janela é criada. 
   //  Nesse caso, permite: uma única janela; cores compostas por Verm. Verde e Azul; e, */
   glutInitWindowSize(400,400);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Aula 01 (OpenGL) - Meu Primeiro Programa");
   glutDisplayFunc(DISPLAY);
   glutMainLoop();
   return 0;
}
