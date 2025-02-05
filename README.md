<h1 align="center"> Temporizador de um disparo (One-Shot)</h1>

## 📋 Sobre
<p align="justify"> 
Este projeto demonstra como controlar três LEDs (azul, vermelho e verde) usando um botão no  Raspberry Pi Pico. Ao pressionar o botão, todos os LEDs são acesos e, em seguida, desligados progressivamente a cada 3 segundos. O botão só pode ser pressionado novamente após todos os LEDs serem desligados.
</p>

## 🚀 Funcionalidades
1. **Acionamento dos LEDs:**
    - Quando o botão é pressionado, todos os LEDS (azul, vermelho e verde) são ligados simultaneamente.
2. **Desligamento Progressivo:** 
    - Após 3 segundos, o LED azul é desligado.
    - Após mais 3 segundos, o LED vermelho é desligado.
    - Finalmente, após mais 3 segundos, o LED verde é desligado.
3. **Bloqueio do Botão:**
    - O botão só pode ser pressionado novamente após todos os LEDs serem desligados, evitando ativações múltiplas durante o processo.

### 🎬 Exemplo de Funcionamento
1. Pressione o botão.
2. Todos os LEDs (azul, vermelho e verde) acendem.
3. Após 3 segundos, o LED azul se apaga.
4. Após mais 3 segundos, o LED vermelho se apaga.
5. Após mais 3 segundos, o LED verde se apaga.
6. O botão pode ser pressionado novamente para repetir o processo.