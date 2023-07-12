# T4 - Motor

### Luís Henrique Chesani



## Como usar
- utilize a tecla '/' para alternar entre o modo 2D e 3D
- utilize as teclas '=' e '-' para controlar a dimensão da figura, impactos no fps
- utilize as teclas 'w' e 's' para controlar a rotação por minuto do motor
- utilize as teclas de 0 a 8 para ocultar/exibir as peças do motor
- utilize a tecla ' ' (espaço) para alternar entre projeção de perspectiva e ortográfica
- utilize as teclas ',', '.' e ';' para alternar entre o tipo de malha/preenchimento, sugere-se ocultar a camisa para melhor visualização.
#### peças
- '0' = manivela
- '1' = virabrequim 1
- '2' = pistão 1
- '3' = virabrequim 2
- '4' = pistão 2
- '5' = biela 1
- '6' = biela 2
- '7' = camisa 1
- '8' = camisa 2

## Requisitos

### Básicos
- Rotação do eixo variável
- Visualização ortográfica e perspectiva sob vários ângulos em wireframe
- Compilado em Windows

### Extras
- Coloração RGB por coordenadas esféricas. (R = cos(theta) sin(phi), G = sin(theta) sin(phi), B = cos(phi))
- Preenchimento controlado por dimensão variável, se estiver disposto a sacrificar o FPS pode aumentar a dimensão até onde quiser.
- Múltiplos tipos de preenchimento (3).
- Implementação completamente baseada em transormações com matrizes e three-dimensional pipeline.
- Matriz de rotação geral ao inves de uma matriz para cada eixo.
- Câmera muito estilosa implementada com matriz lookAt e coordenadas esféricas.
- Música.
- Aspecto visual bonito.
