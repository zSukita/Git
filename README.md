# Conversor de Unidades de Potência

Um programa em C que permite converter entre diferentes unidades de potência, incluindo Watts (W), Quilowatts (kW), Cavalos-vapor (CV) e Horse Power (HP).

## Funcionalidades

- Conversão bidirecional entre todas as unidades suportadas
- Interface interativa com menu de opções
- Validação de entrada de dados
- Suporte para múltiplas conversões em sequência
- Alta precisão nos cálculos (4 casas decimais)
- Tratamento de erros de entrada

## Fatores de Conversão

| De      | Para    | Fator       |
|---------|---------|-------------|
| W       | kW      | 0.001       |
| W       | CV      | 0.00136     |
| W       | HP      | 0.00134102  |
| kW      | W       | 1000.0      |
| CV      | W       | 735.499     |
| HP      | W       | 745.7       |

## Requisitos

- Compilador C (GCC recomendado)
- Sistema operacional: Windows, Linux ou macOS

## Compilação

Para compilar o programa, execute o seguinte comando no terminal:

```bash
gcc conversor_potencia.c -o conversor_potencia
```

## Execução

Após compilar, execute o programa:

### Windows
```bash
conversor_potencia.exe
```

### Linux/macOS
```bash
./conversor_potencia
```

## Como Usar

1. Execute o programa
2. Escolha a unidade de entrada (1-4)
3. Digite o valor a ser convertido
4. Escolha a unidade de saída (1-4)
5. Visualize o resultado
6. Pressione Enter para continuar ou escolha 0 para sair

## Estrutura do Código

- `UnidadePotencia`: Enumeração com as unidades suportadas
- `FatorConversao`: Estrutura para armazenar fatores de conversão
- Funções principais:
  - `converterPotencia()`: Realiza os cálculos de conversão
  - `obterOpcao()`: Gerencia entrada do usuário
  - `exibirMenu()`: Mostra as opções disponíveis
  - `limparBuffer()`: Previne erros de entrada

## Exemplos de Uso

```
### Conversor de Potencia ###

=== Unidade de Entrada ===
1 - Watts (W)
2 - Quilowatts (kW)
3 - Cavalos-vapor (CV)
4 - Horse Power (HP)
0 - Sair
Escolha uma opcao: 1

Digite o valor a ser convertido: 1000

=== Unidade de Saida ===
1 - Watts (W)
2 - Quilowatts (kW)
3 - Cavalos-vapor (CV)
4 - Horse Power (HP)
0 - Sair
Escolha uma opcao: 2

1000.0000 W = 1.0000 kW
```

## Tratamento de Erros

O programa inclui:
- Validação de entrada numérica
- Verificação de valores negativos
- Limpeza de buffer para prevenir erros
- Mensagens de erro informativas

## Contribuição

Para contribuir com o projeto:
1. Faça um fork do repositório
2. Crie uma branch para sua feature (`git checkout -b feature/NovaFeature`)
3. Faça commit das mudanças (`git commit -m 'feat: Adiciona nova feature'`)
4. Push para a branch (`git push origin feature/NovaFeature`)
5. Crie um Pull Request


## Autor

[ Lucas Silva de Souza ]

## Histórico de Versões

- 1.0.0 (2024-12-18)
  - Primeira versão
  - Suporte para W, kW, CV e HP
  - Interface interativa
  - Validação de entrada
