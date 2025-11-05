# 🧾 `get_next_line` — 42 School Project  
> 📚 Read a line from a file descriptor, one line at a time — elegantly and efficiently.  
> Leitura linha a linha de um arquivo, com controle de memória e buffer dinâmico.

---

## 🧠 🇧🇷 Descrição

O **`get_next_line`** é um projeto da **Escola 42** cujo objetivo é implementar uma função capaz de **ler uma linha completa de um arquivo** (ou da entrada padrão), **sem perder o restante do conteúdo** entre chamadas subsequentes.

Isso significa que a função deve **lembrar onde parou**, gerenciando o **buffer** e o **resto da leitura** de forma eficiente — mesmo que as linhas sejam longas, o arquivo seja grande ou o descritor mude.

A versão **bônus** amplia a função para **lidar com múltiplos descritores de arquivo simultaneamente**, mantendo o contexto de leitura de cada um.

---

### 🧠 🇺🇸 Description

The **`get_next_line`** project from **42 School** challenges you to implement a function that **reads one full line from a file descriptor** each time it’s called — **without losing track** of where the last read stopped.

This means the function must **remember its position**, efficiently managing the **buffer** and **remaining data**, even when reading large files or long lines.

The **bonus version** extends functionality to **support multiple file descriptors simultaneously**, keeping each read state independent.

---

## ⚙️ 🇧🇷 Funcionamento

A função lê blocos de texto do arquivo (usando `read`) em um **buffer de tamanho fixo (`BUFFER_SIZE`)**.  
Cada leitura é **concatenada com o que sobrou da chamada anterior**, até encontrar um caractere `'\n'` ou o fim do arquivo (`EOF`).

Principais funções do projeto:
- **`get_next_line(int fd)`** → Lê uma linha completa do descritor `fd`.  
- **`ft_strjoin`, `ft_strchr`, `ft_strdup`, `ft_substr`** → Utilitários para manipulação segura de strings.  
- **Controle de memória** → Liberação de buffers antigos, garantindo ausência de leaks.  
- **Bônus:** Uso de uma **estrutura estática por descritor** (`fd`) para manter o estado de leitura independente.

---

### ⚙️ 🇺🇸 How it Works

The function reads chunks of data (via `read`) using a **fixed-size buffer (`BUFFER_SIZE`)**.  
Each read appends to the **remainder** of the previous call until a `'\n'` or `EOF` is found.

Core project functions:
- **`get_next_line(int fd)`** → Reads one complete line from `fd`.  
- **Helper functions:** `ft_strjoin`, `ft_strchr`, `ft_strdup`, `ft_substr` for safe string handling.  
- **Memory management:** Prevents leaks by freeing unused buffers.  
- **Bonus:** Uses a **static buffer per file descriptor**, allowing multiple simultaneous reads.

---

## 🧪 🇧🇷 Compilação e uso

```bash
# Compilação simples
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

# Execução de exemplo
./gnl < arquivo.txt
``` 
---

### 🧪 🇺🇸 Compilation and Usage

```bash
# Basic compilation
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

# Example run
./gnl < file.txt
```

---
## 🧰 Estrutura de Arquivos / File Structure

📂 get_next_line/
-
- ├── get_next_line.c
- ├── get_next_line_utils.c
- ├── get_next_line_bonus.c
- ├── get_next_line_utils_bonus.c
- ├── get_next_line.h
- └── README.md

---

## 🏁 Resultado / Result

✅ Lê arquivos de qualquer tamanho
✅ Gerencia memória de forma eficiente
✅ Suporta múltiplos descritores (bônus)
✅ Segue a Norma da 42
✅ Sem leaks, comportamento estável e limpo

---

#### 👩‍💻 Créditos / Credits

Autor: Tai Fanfa |
Projeto: get_next_line (42 School) |
Linguagem: C |
Licença: MIT

