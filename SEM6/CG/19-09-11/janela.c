#include <GL/freeglut.h>

void DISPLAY();

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  /*
    Avisa a GLUT que modo de exibição deve ser usado quando a janela é criada.
    Nesse caso, permite: uma única janela; cores compostas por Vermelho, Verde e Azul; profundidade de cenas.
  */
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 01 (OpenGL) - Meu Primeiro Programa");
  glutDisplayFunc(DISPLAY);
  glutMainLoop();
  return EXIT_SUCCESS;
}

// Inicializa parâmetros de rendering
void DISPLAY() {
  // Define a cor de fundo da janela de visualização como vermelho
  glClearColor(1, 0, 0, 0);
  glMatrixMode(GL_PROJECTION); // Ativa a matriz de projeção
  glLoadIdentity(); // "Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.
  gluOrtho2D(-200, 200, -200, 200); // Define o tipo de projeção (2D) e o tamanho
  glMatrixMode(GL_MODELVIEW); // Ativa matriz de visualização
  glLoadIdentity(); // "Limpa" ou "transforma" a matriz em identidade, reduzindo possíveis erros.
  // Limpa a janela de visualização com a cor de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /*
    "Limpa" um buffer particular ou combinações de buffers, onde buffer é uma área de armazenamento para informações da imagem. Nesse caso, está "limpando os buffers para suportarem animações"
    Chamada para Função ou funções para desenha o objeto/cena...
  */
  glutSwapBuffers();
}