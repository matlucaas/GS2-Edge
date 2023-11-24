# GS2-Edge
Global Solution - Segundo Semestre

## Sobre o projeto:
Por meio da nossa ferramenta (site), iremos auxiliar o usuário a ter um dia a dia mais saudável, fornecendo dicas como atividades físicas no dia a dia, e caso o usuário tenha uma receita com nutricionistas, ele pode colocar na plataforma o quanto ele deve consumir no dia a dia para atingir sua meta diária. Com base nas informações do usuário, serão entregues dicas para o dia a dia como atividades físicas, monitoramento de sono, lembretes de alimentação e hidratação e informar pequenos sintomas que podem indicar doenças graves, mostrando a importância de ir a um médico para verificar.

## Componentes:
Para desenvolver este protótipo, foi utilizado:

+ ESP32;
+ Um sensor de temperatura (DHT22);
+ Um ILI9341 2.8" TFT-LCD Display;
+ 4 Push-buttons.

## Como funciona?
Para montar o protótipo, você pode verificar o projeto já montado no simulador, que será exibido posteriormente no arquivo. Bom, o propósito deste protótipo é mostrar ao usuário receitas que podem auxiliar com pequenas dores mas principalmente previni-las, além de receber os dados de temperatura do usuário e enviá-los para a plataforma tago via protocolo MQTT, e nessa plataforma é mostrado se o nível da temperatura está boa, alta (possível febre) ou baixa (possível hipotermia leve ou outros fatores).

### Receitas
+ O ***Display***, quando inicializado, exibe quatro opções onde o usuário escolhe cada uma delas com um botão;
+ As 3 primeiras são opções de receitas que podem auxiliar com pequenas dores mas principalmente previni-las, usando componentes encontrados em casa;
+ Caso o usuário queira voltar ao menu após ter selecionado alguma receita, é indicado que ele pode clicar em qualquer botão para voltar.

### Temperatura
+ A quarta opção do menu é a opção de verificar temperatura;
+ O ***Sensor de temperatura (DHT22)*** mede o usuário em tempo real;
+ Ao clicar em qualquer botão, os dados da temperatura são enviados para a plataforma via MQTT e o usuário é direcionado ao menu novamente.

## Links Importantes
+ Simulador Wokwi: https://wokwi.com/projects/382059464165905409
+ Vídeo explicativo: https://youtu.be/s47eLU7DODY?si=t-55TkefWekqGg-f
